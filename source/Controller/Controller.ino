// --------------------------------------
// Example Code for the BP-Table

#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define LED_PIN 6
#define LED_PIN2 5

#define LED_COUNT 60

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT, LED_PIN2, NEO_GRB + NEO_KHZ800);

// I2C Commands
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

// touch configs
typedef enum { GAIN_1, GAIN_2, GAIN_4, GAIN_8, GAIN_16, GAIN_32 } touchGain;

typedef enum {
  FILTER_LEVEL_1,
  FILTER_LEVEL_2,
  FILTER_LEVEL_4,
  FILTER_LEVEL_8,
  FILTER_LEVEL_16,
  FILTER_LEVEL_32,
  FILTER_LEVEL_64
} touchFilter;

// Class for the sens plates
// Contains the current sense status, can call/config SesnsePlate via I2C

typedef enum {
  SENSERESET,
  SENSECONFIG,
  SENSEFOUND,
  SENSEERROR,
  SENSEREADY
} SENSEState;
typedef enum { notDetect, detect } SenseState;
typedef enum { SENSEMODE_TOUCH, SENSEMODE_IR } SenseMode;

class sensePlate {
public:
  sensePlate(uint8_t id, TwoWire *pWire, Adafruit_NeoPixel *pStrip,
             uint8_t ledStartID) {
    this->id = id;

    this->address = id + 1;
    this->pStrip = pStrip;
    this->pWire = pWire;

    for (size_t i = 0; i < numLEDs; i++) {
      ledIDs[i] = i + ledStartID;
    }
  }

  // Config sensePlate
  void init(SenseMode mode) {
    find();
    config(mode);
    start();
  }

  // call sensePlate reset
  void reset() {
    pWire->beginTransmission(address);
    pWire->write(RESET);
    pWire->endTransmission();
    state = SENSERESET;
  };

  // test sensePlate is reachable
  void find() {
    uint8_t error;

    pWire->beginTransmission(address);
    pWire->write(NONE);
    error = pWire->endTransmission();

    if (error != 0) {
      state = SENSEERROR;
      printInfo("Sensor not Found");

    } else {
      printInfo("Sensor Found");

      state = SENSEFOUND;
    }
  }

  // config for IR and Touch
  void config(SenseMode mode) {
    if (state == SENSEFOUND) {

      if (mode == SENSEMODE_IR) { // Config for IR
        pWire->beginTransmission(address);
        pWire->write(SETIRTRESHOLD);
        pWire->write(20);
        pWire->endTransmission();

        pWire->beginTransmission(address);
        pWire->write(SETIRAVG);
        pWire->write(10);
        pWire->endTransmission();

        pWire->beginTransmission(address);
        pWire->write(SETIRDELAY);
        pWire->write(10);
        pWire->endTransmission();

        // Set Mode
        pWire->beginTransmission(address);
        pWire->write(SETMODEIR);
        pWire->endTransmission();
      }

      else if (mode == SENSEMODE_TOUCH) { // Config for TOUCH
        pWire->beginTransmission(address);
        pWire->write(SETTOUCHDIGITALGAIN);
        pWire->write(GAIN_2);

        pWire->beginTransmission(address);
        pWire->write(SETTOUCHANALOGGAIN);
        pWire->write(GAIN_2);
        pWire->endTransmission();

        pWire->beginTransmission(address);
        pWire->write(SETTOUCHFILTERLEVEL);
        pWire->write(FILTER_LEVEL_32);
        pWire->endTransmission();

        // Set Mode
        pWire->beginTransmission(address);
        pWire->write(SETMODETOUCH);
        pWire->endTransmission();
      }
      state = SENSECONFIG;
    }
  }

  // Start sensing
  void start() {

    if (state == SENSECONFIG) {
      // START Sensing
      pWire->beginTransmission(address);
      pWire->write(START);
      pWire->endTransmission();
      state = SENSEREADY;

      for (uint8_t index = 0; index < numLEDs; index++) {
        pStrip->setPixelColor(ledIDs[index], 0xFFFFFF);
        timeCounter = 255; // temp for start animation
      }

    } else {
      printInfo("Sensor not Configured");

      for (uint8_t index = 0; index < numLEDs; index++) {
        pStrip->setPixelColor(ledIDs[index], 0xFF0000);
      }
    }
  }

  // Request current sense status from sensePlate
  void requesetSense() {
    if (state != SENSEREADY)
      return;
    uint8_t data;

    pWire->requestFrom(address, (uint8_t)1, (uint8_t) true);

    data = pWire->read();
    if (senseState != data) {
      printInfo("State-- changed");
    }
    if (data > 0) {
      senseState = detect;
    } else {
      senseState = notDetect;
    }
  }

  // Print debug Info
  void printInfo(char *message) {
    Serial.print("Sensor: ");
    Serial.println(address);
    Serial.print("  - ");
    Serial.println(message);
  }

  // Temporary draw function for the LED on the SensePlate
  void draw() {

    uint32_t color = 0x0;
    if (state == SENSEREADY) { // cheack SENSE is in ready mode

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
      pStrip->setPixelColor(ledIDs[index], color);
    }
  }
  uint8_t numLEDs = 6;
  uint8_t ledIDs[6];

  Adafruit_NeoPixel *pStrip = nullptr;
  TwoWire *pWire = nullptr;

  uint8_t address = 0;
  uint8_t id = 0;

  uint16_t timeCounter = 0;

  SENSEState state = SENSERESET;
  SenseState senseState = notDetect;
};

sensePlate Senseagons1[10] = {
    sensePlate(0, &Wire1, &strip, 0),  sensePlate(1, &Wire1, &strip, 6),
    sensePlate(2, &Wire1, &strip, 12), sensePlate(3, &Wire1, &strip, 18),
    sensePlate(4, &Wire1, &strip, 24), sensePlate(5, &Wire1, &strip, 30),
    sensePlate(6, &Wire1, &strip, 36), sensePlate(7, &Wire1, &strip, 42),
    sensePlate(8, &Wire1, &strip, 48), sensePlate(9, &Wire1, &strip, 54)};

sensePlate Senseagons2[10] = {sensePlate(0 + 16, &Wire1, &strip2, 0),
                              sensePlate(1 + 16, &Wire1, &strip2, 6),
                              sensePlate(2 + 16, &Wire1, &strip2, 12),
                              sensePlate(3 + 16, &Wire1, &strip2, 18),
                              sensePlate(4 + 16, &Wire1, &strip2, 24),
                              sensePlate(5 + 16, &Wire1, &strip2, 30),
                              sensePlate(6 + 16, &Wire1, &strip2, 36),
                              sensePlate(7 + 16, &Wire1, &strip2, 42),
                              sensePlate(8 + 16, &Wire1, &strip2, 48),
                              sensePlate(9 + 16, &Wire1, &strip2, 54)};

void setup() {
  // NEOPixel
  strip.begin(); // INITIALIZE NeoPixel strip object
  strip.show();
  strip.setBrightness(50); // Set brigthness

  strip2.begin(); // INITIALIZE NeoPixel strip object
  strip2.show();
  strip2.setBrightness(50); // Set brigthness

  // I2C
  Wire1.begin();
  Wire1.setClock(10000);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);

  // Serual
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("\nBP_Control");

  // GPIO
  pinMode(7, INPUT);
  pinMode(4, INPUT);

  // Reset all sensePlates
  for (int SENSEID = 0; SENSEID < 10; SENSEID++) {
    Senseagons1[SENSEID].reset();
    Senseagons2[SENSEID].reset();
  }

  delay(200); // wait for reset

  // Set sense config and mode
  for (int SENSEID = 0; SENSEID < 10; SENSEID++) {
    Senseagons1[SENSEID].init(SENSEMODE_IR);
    Senseagons2[SENSEID].init(SENSEMODE_IR);

    strip.show();
    strip2.show();

    delay(50);
  }
}

void loop() {

  // Check state
  if (digitalRead(7) == LOW) {
    for (uint8_t SENSEID = 0; SENSEID < 10; SENSEID++) {

      Senseagons1[SENSEID].requesetSense();
    }
  }

  if (digitalRead(4) == LOW) {
    for (uint8_t SENSEID = 0; SENSEID < 10; SENSEID++) {

      Senseagons2[SENSEID].requesetSense();
    }
  }

  // Draw LEDs
  strip.clear();
  strip2.clear();

  for (uint8_t SENSEID = 0; SENSEID < 10; SENSEID++) {
    Senseagons1[SENSEID].draw();
    Senseagons2[SENSEID].draw();
  }
  strip.show();
  strip2.show();
}
