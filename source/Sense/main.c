#include <atmel_start.h>
#include <util/delay.h>

typedef enum {
    NONE = 0x00,
    RECALIBRATETOUCH = 0x10,
    RECALIBRATEIR = 0x11,
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

typedef enum { NEWCOMMAND = 0x00, WAITFORDATA = 0x01 } COMMANDSTATETYPE;

typedef enum {
    HOLD,
    RUNIR,
    RUNTOUCH

} RUNMODETYPE;

volatile uint8_t irThreshold = 20;
volatile uint8_t touchThreshold = 20;
volatile uint8_t irSamples = 10;
volatile uint8_t irDelay = 0;

volatile uint8_t touchAnalogGain = 0;
volatile uint8_t touchDigitalGain = 0;
volatile uint8_t touchFilterLevel = 0;

volatile uint8_t address = 0x00;

volatile bool waitForController = true;
volatile uint8_t senseState = 0x00;

volatile COMMANDTYPE command = NONE;
volatile COMMANDSTATETYPE commandState = NEWCOMMAND;

volatile uint8_t mode = HOLD;

volatile bool waitForSenseRead = false;

qtm_acq_t81x_node_config_t ptc_seq_node_cfg1[DEF_NUM_CHANNELS] = {
    {X_NONE, Y(0), 0, PRSC_DIV_SEL_16, NODE_GAIN(GAIN_1, GAIN_1), FILTER_LEVEL_16},
    {X_NONE, Y(1), 0, PRSC_DIV_SEL_16, NODE_GAIN(GAIN_1, GAIN_1), FILTER_LEVEL_16},
    {X_NONE, Y(2), 0, PRSC_DIV_SEL_16, NODE_GAIN(GAIN_1, GAIN_1), FILTER_LEVEL_16}};

void I2C_0_address_handler() {
    I2C_0_send_ack();
}

void I2C_0_read_handler() {
    I2C_0_write(senseState);
    waitForSenseRead = false;
    sense_trig_set_level(0);
}

void reset() {
    _PROTECTED_WRITE(RSTCTRL.SWRR, 1);
}

void touch_config() {
    ptc_seq_node_cfg1[0].node_gain = NODE_GAIN(touchAnalogGain, touchDigitalGain);
    ptc_seq_node_cfg1[1].node_gain = NODE_GAIN(touchAnalogGain, touchDigitalGain);
    ptc_seq_node_cfg1[2].node_gain = NODE_GAIN(touchAnalogGain, touchDigitalGain);

    ptc_seq_node_cfg1[0].node_oversampling = touchFilterLevel;
    ptc_seq_node_cfg1[1].node_oversampling = touchFilterLevel;
    ptc_seq_node_cfg1[2].node_oversampling = touchFilterLevel;
}
void I2C_0_write_handler() {

    // Read
    if (commandState == NEWCOMMAND) {
        command = I2C_0_read();

        // direct Command?
        switch (command) {
            case SETMODEIR: mode = RUNIR; break;
            case SETMODETOUCH:
                touch_config();
                touch_init();
                mode = RUNTOUCH;
                break;
            case RECALIBRATETOUCH:
                calibrate_node(0);
                calibrate_node(1);
                calibrate_node(2);
                break;
            case RECALIBRATEIR:; break;
            case START: waitForController = false; break;
            case RESET: reset(); break;
            // commands with more data
            case SETTOUCHANALOGGAIN:
            case SETTOUCHDIGITALGAIN:
            case SETTOUCHFILTERLEVEL:

            case SETIRTRESHOLD:
            case SETIRAVG:
            case SETIRDELAY: commandState = WAITFORDATA; break;

            default: break;
        }
    }
    else if (commandState == WAITFORDATA) {

        uint8_t readData = I2C_0_read();
        // Value
        switch (command) {
            case SETIRTRESHOLD: irThreshold = readData; break;
            case SETIRAVG: irSamples = readData; break;
            case SETIRDELAY: irDelay = readData; break;
            case SETTOUCHANALOGGAIN: touchAnalogGain = readData;
            case SETTOUCHDIGITALGAIN: touchDigitalGain = readData;
            case SETTOUCHFILTERLEVEL: touchFilterLevel = readData;

            default: break;
        }

        commandState = NEWCOMMAND;

        // end command
    }

    I2C_0_send_ack();
}

void I2C_0_stop_handler() {
    commandState = NEWCOMMAND;
}

void I2C_0_error_handler() {
    // reset
    commandState = NEWCOMMAND;
    sense_trig_set_level(0);
}

/*
BP_Table Sense
Infrared and Touch SensePlate
To start the SensePlate you have to send the Config for Touch / IR , set the mode and send a start command.
The SensePlate will pull down the sense interrupt line to the control IC if a sense change occured. It will wait for
an read I2C request and response with the current sensing state. So if the Sense line is pulled down
-> request the Sense data for each SensePlate until the sense line is cleared

For a clean start trigger a reset via Reset command and wait 100ms for Bootup.

example communication for IR
Startup
- RESET  (for a clean start)
- wait 100ms
- SETIRTRESHOLD + value
- SETIRAVG + value
- SETIRDELAY + value
- SETMODEIR
- START

example communication fir TOUCH
Startup
- RESET  (for a clean start)
- wait 100ms
- SETTOUCHDIGITALGAIN + value
- SETTOUCHANALOGGAIN + value
- SETTOUCHFILTERLEVEL + value
- SETMODETOUCH
- START



///////Protocol///////
if write
        receive 1 Byte
                -> command mode
                    -> command without data
                        -> execute
                    -> command with data?
                        -> set data mode
                -> data mode
                    -> check command state
                        -> write data
                    -> reset mode

if read
        send 1 byte (sense status)
        clear sense line

if stop bit
-> reset command state

*/

int main(void) {

    //// Initializes MCU, drivers and middleware ////

    atmel_start_init();
    cpu_irq_enable();

    sense_trig_set_level(0);

    // read MCU ID + 1  (I2C Address 0 is reserved for general call)
    address =
        (!A4_get_level() << 4 | !A3_get_level() << 3 | !A2_get_level() << 2 | !A1_get_level() << 1 | !A0_get_level()) +
        1;

    // //// I2C ////
    // set Slabe Address
    TWI0.SADDR = address << TWI_ADDRMASK_gp /* Slave Address: 0x0 */
                 | 0 << TWI_ADDREN_bp;      /* General Call Recognition Enable: disabled */

    // register Callback
    I2C_0_set_read_callback(I2C_0_read_handler);
    I2C_0_set_write_callback(I2C_0_write_handler);
    I2C_0_set_address_callback(I2C_0_address_handler);
    I2C_0_set_stop_callback(I2C_0_stop_handler);
    I2C_0_set_collision_callback(I2C_0_error_handler);
    I2C_0_set_bus_error_callback(I2C_0_error_handler);

    I2C_0_enable();
    I2C_0_open();

    // Wait for start Command
    while (waitForController)
        ;

    uint8_t touchStatus = 0;
    uint8_t irStatus = 0;
    uint8_t irCounter = 0;

    uint16_t irOffValue = 0;
    uint16_t irOnValue = 0;
    uint16_t irDifference = 0;

    while (1) {
        if (mode == RUNTOUCH) {
            //// Touch ////
            touch_process();

            // // check sensor state
            touchStatus = (get_sensor_state(0) & KEY_TOUCHED_MASK) >> 7 |
                          (get_sensor_state(1) & KEY_TOUCHED_MASK) >> 6 | (get_sensor_state(2) & KEY_TOUCHED_MASK) >> 5;
        }
        else if (mode == RUNIR) {
            //// Infrared ////

            // reset Status
            irCounter = 0;
            irStatus = 0;

            // sample
            for (size_t i = 0; i < irSamples; i++) {
                // sense OFF Value
                irOffValue = ADC_0_get_conversion(ADC_MUXPOS_AIN10_gc);

                IR_LED_set_level(1);
                // // sense ON Value
                _delay_us(1000); // wait a moment for IR LED and receiver

                irOnValue = ADC_0_get_conversion(ADC_MUXPOS_AIN10_gc);

                IR_LED_set_level(0);
                _delay_us(1000); // wait a moment for IR LED and receiver

                // check difference above treshold
                irDifference = abs((int16_t)irOnValue - (int16_t)irOffValue);

                if (irDifference >= irThreshold) {
                    irCounter = irCounter + 1;
                }

                for (size_t i = 0; i < irDelay;
                     i++) // looks weird but is needed because the delay needs a compile time constant
                {
                    _delay_ms(1); // wait for 1 ms per loop
                }
            }
            // get ir status (average)
            if ((float)(irCounter /= (float)irSamples) >= 0.5) {
                irStatus = 1;
            }
        }

        //  check state change and call controller
        if (senseState != (touchStatus | irStatus)) {
            senseState = touchStatus | irStatus;
            sense_trig_set_level(1);
            waitForSenseRead = true;
            while (waitForSenseRead == true) // wait for control read
                ;
        }
    }
}
