// --------------------------------------
// Example Code for the BP-Table

#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define LED_PIN 6
#define LED_COUNT 60

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

typedef enum {
  NONE = 0x00,
  RECALIBRATETOUCH = 0x10,
  RECALIBRATEIR = 0x11, // not used
  SETIRTRESHOLD = 0x81,
  SETIRAVG = 0x82,
  SETIRDELAY = 0x83,
  SETTOUCHANALOGGAIN = 0x8A, // Touch Config must be set before SETMODETOUCH
  SETTOUCHDIGITALGAIN = 0x8B,
  SETTOUCHFILTERLEVEL = 0x8C,
  SETMODEIR = 0xF0,
  SETMODETOUCH = 0xF1,
  START = 0xFA,
  RESET = 0xFB
} COMMANDTYPE;

// touch config
typedef enum tag_gain_t {
  GAIN_1,
  GAIN_2,
  GAIN_4,
  GAIN_8,
  GAIN_16,
  GAIN_32
} gain_t;

typedef enum tag_filter_level_t {
  FILTER_LEVEL_1,
  FILTER_LEVEL_2,
  FILTER_LEVEL_4,
  FILTER_LEVEL_8,
  FILTER_LEVEL_16,
  FILTER_LEVEL_32,
  FILTER_LEVEL_64
} filter_level_t;

typedef enum { HEXRESET, HEXCONFIG, HEXFOUND, HEXERROR, HEXREADY } HexState;
typedef enum { notDetect, detect } HexSenseState;
typedef enum { HEXMODE_TOUCH, HEXMODE_IR } HexMode;

class senseHex {
public:
  senseHex(uint8_t id, Adafruit_NeoPixel *strip, uint8_t ledStartID) {
    this->id = id;

    this->address = id + 1;
    this->strip = strip;

    for (size_t i = 0; i < numLEDs; i++) {
      ledIDs[i] = i + ledStartID;
    }
  }

  void init(HexMode mode) {
    find();
    config(mode);
    start();
  }
  void reset() {
    Wire1.beginTransmission(address);
    Wire1.write(RESET);
    Wire1.endTransmission();
    state = HEXRESET;
  };
  void find() {
    uint8_t error;

    Wire1.beginTransmission(address);
    Wire1.write(NONE);
    error = Wire1.endTransmission();

    if (error != 0) {
      state = HEXERROR;
      printInfo("HEX not Found");

    } else {
      state = HEXFOUND;
    }
  }
  void config(HexMode mode) {
    if (state == HEXFOUND) {

      if (mode = HEXMODE_IR) { // Config for IR
        Wire1.beginTransmission(address);
        Wire1.write(SETIRTRESHOLD);
        Wire1.write(20);
        Wire1.endTransmission();

        Wire1.beginTransmission(address);
        Wire1.write(SETIRAVG);
        Wire1.write(10);
        Wire1.endTransmission();

        Wire1.beginTransmission(address);
        Wire1.write(SETIRDELAY);
        Wire1.write(1);
        Wire1.endTransmission();

        // Set Mode
        Wire1.beginTransmission(address);
        Wire1.write(SETMODEIR);
        Wire1.endTransmission();
      }

      else if (mode = HEXMODE_TOUCH) { // Config for TOUCH
        Wire1.beginTransmission(address);
        Wire1.write(SETTOUCHDIGITALGAIN);
        Wire1.write(GAIN_8);

        Wire1.beginTransmission(address);
        Wire1.write(SETTOUCHANALOGGAIN);
        Wire1.write(GAIN_4);
        Wire1.endTransmission();

        Wire1.beginTransmission(address);
        Wire1.write(SETTOUCHFILTERLEVEL);
        Wire1.write(FILTER_LEVEL_32);
        Wire1.endTransmission();

        // Set Mode
        Wire1.beginTransmission(address);
        Wire1.write(SETMODETOUCH);
        Wire1.endTransmission();
      }
    }
    state = HEXCONFIG;
  }
  void start() {

    if (state == HEXCONFIG) {
      // START Sensing
      Wire1.beginTransmission(address);
      Wire1.write(START);
      Wire1.endTransmission();
      state = HEXREADY;

      for (uint8_t index = 0; index < numLEDs; index++) {
        strip->setPixelColor(ledIDs[index], 0xFFFFFF);
        timeCounter = 255; // temp for start animation
      }

    } else {
      printInfo("HEX not Configured");

      for (uint8_t index = 0; index < numLEDs; index++) {
        strip->setPixelColor(ledIDs[index], 0xFF0000);
      }
    }
  }

  void requesetSense() {
    uint8_t data;

    Wire1.requestFrom(address, (uint8_t)1, (uint8_t) true);

    data = Wire1.read();

    if (data > 0) {
      senseState = detect;
    } else {
      senseState = notDetect;
    }
  }

  void printInfo(char *message) {
    Serial.print("HEX ERROR : ");
    Serial.println(address);
    Serial.print("  - ");
    Serial.println(message);
  }

  void draw() { // simple temporary draw function for the detection

    uint32_t color = 0x0;
    if (state == HEXREADY) { // cheack hex is in ready mode

      if (senseState == detect) {

        if (timeCounter < 255)
          timeCounter++;
      }

      if (senseState == notDetect) {
        if (timeCounter > 0)
          timeCounter--;
      }

      color = timeCounter << 16 | timeCounter << 8 | timeCounter;

    } else { // error color for debug
      color = 0xFF0000;
    }

    for (uint8_t index = 0; index < numLEDs; index++) {
      strip->setPixelColor(ledIDs[index], color);
    }
  }
  uint8_t numLEDs = 6;
  uint8_t ledIDs[6];

  Adafruit_NeoPixel *strip = nullptr;

  uint8_t address = 0;
  uint8_t id = 0;

  uint16_t timeCounter = 0;

  HexState state = HEXRESET;
  HexSenseState senseState = notDetect;
};

senseHex Hexagons[10] = {senseHex(0, &strip, 0),  senseHex(1, &strip, 6),
                         senseHex(2, &strip, 12), senseHex(3, &strip, 18),
                         senseHex(4, &strip, 24), senseHex(5, &strip, 30),
                         senseHex(6, &strip, 36), senseHex(7, &strip, 42),
                         senseHex(8, &strip, 48), senseHex(9, &strip, 54)};

void setup() {
  // NEOPixel
  strip.begin(); // INITIALIZE NeoPixel strip object
  strip.show();
  strip.setBrightness(10); // Set brigthness

  // I2C
  Wire1.begin();

  // Serual
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("\nBP_Control");

  // GPIO
  pinMode(7, INPUT);

  // Config all attiny
  for (int hexID = 0; hexID < 10; hexID++) {
    Hexagons[hexID].reset();
  }

  delay(100); // wait for reset

  for (int hexID = 0; hexID < 10; hexID++) {
    Hexagons[hexID].init(HEXMODE_IR);

    strip.show();

    delay(100);
  }

  // Config Done
}

void loop() {

  // Check state
  if (digitalRead(7) == LOW) {
    for (uint8_t hexID = 0; hexID < 10; hexID++) {

      Hexagons[hexID].requesetSense();
    }
  }

  // Draw LEDs
  strip.clear();

  for (uint8_t hexID = 0; hexID < 10; hexID++) {
    Hexagons[hexID].draw();
  }
  strip.show();
}
