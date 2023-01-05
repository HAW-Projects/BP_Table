/*
 * Code generated from START.
 *
 * This file will be overwritten when reconfiguring your START project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <port.h>

/**
 * \brief Set PA1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void PA1_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTA_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set PA1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PA1_set_dir(const enum port_dir dir) {
    PORTA_set_pin_dir(1, dir);
}

/**
 * \brief Set PA1 input/sense configuration
 *
 * Enable/disable PA1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PA1_set_isc(const PORT_ISC_t isc) {
    PORTA_pin_set_isc(1, isc);
}

/**
 * \brief Set PA1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PA1 is inverted
 *                     false = I/O on PA1 is not inverted
 */
static inline void PA1_set_inverted(const bool inverted) {
    PORTA_pin_set_inverted(1, inverted);
}

/**
 * \brief Set PA1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PA1_set_level(const bool level) {
    PORTA_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on PA1
 *
 * Toggle the pin level
 */
static inline void PA1_toggle_level() {
    PORTA_toggle_pin_level(1);
}

/**
 * \brief Get level on PA1
 *
 * Reads the level on a pin
 */
static inline bool PA1_get_level() {
    return PORTA_get_pin_level(1);
}

/**
 * \brief Set PA2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void PA2_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTA_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set PA2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PA2_set_dir(const enum port_dir dir) {
    PORTA_set_pin_dir(2, dir);
}

/**
 * \brief Set PA2 input/sense configuration
 *
 * Enable/disable PA2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PA2_set_isc(const PORT_ISC_t isc) {
    PORTA_pin_set_isc(2, isc);
}

/**
 * \brief Set PA2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PA2 is inverted
 *                     false = I/O on PA2 is not inverted
 */
static inline void PA2_set_inverted(const bool inverted) {
    PORTA_pin_set_inverted(2, inverted);
}

/**
 * \brief Set PA2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PA2_set_level(const bool level) {
    PORTA_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on PA2
 *
 * Toggle the pin level
 */
static inline void PA2_toggle_level() {
    PORTA_toggle_pin_level(2);
}

/**
 * \brief Get level on PA2
 *
 * Reads the level on a pin
 */
static inline bool PA2_get_level() {
    return PORTA_get_pin_level(2);
}

/**
 * \brief Set PA4 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void PA4_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTA_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set PA4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PA4_set_dir(const enum port_dir dir) {
    PORTA_set_pin_dir(4, dir);
}

/**
 * \brief Set PA4 input/sense configuration
 *
 * Enable/disable PA4 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PA4_set_isc(const PORT_ISC_t isc) {
    PORTA_pin_set_isc(4, isc);
}

/**
 * \brief Set PA4 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PA4 is inverted
 *                     false = I/O on PA4 is not inverted
 */
static inline void PA4_set_inverted(const bool inverted) {
    PORTA_pin_set_inverted(4, inverted);
}

/**
 * \brief Set PA4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PA4_set_level(const bool level) {
    PORTA_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on PA4
 *
 * Toggle the pin level
 */
static inline void PA4_toggle_level() {
    PORTA_toggle_pin_level(4);
}

/**
 * \brief Get level on PA4
 *
 * Reads the level on a pin
 */
static inline bool PA4_get_level() {
    return PORTA_get_pin_level(4);
}

/**
 * \brief Set PA5 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void PA5_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTA_set_pin_pull_mode(5, pull_mode);
}

/**
 * \brief Set PA5 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PA5_set_dir(const enum port_dir dir) {
    PORTA_set_pin_dir(5, dir);
}

/**
 * \brief Set PA5 input/sense configuration
 *
 * Enable/disable PA5 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PA5_set_isc(const PORT_ISC_t isc) {
    PORTA_pin_set_isc(5, isc);
}

/**
 * \brief Set PA5 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PA5 is inverted
 *                     false = I/O on PA5 is not inverted
 */
static inline void PA5_set_inverted(const bool inverted) {
    PORTA_pin_set_inverted(5, inverted);
}

/**
 * \brief Set PA5 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PA5_set_level(const bool level) {
    PORTA_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on PA5
 *
 * Toggle the pin level
 */
static inline void PA5_toggle_level() {
    PORTA_toggle_pin_level(5);
}

/**
 * \brief Get level on PA5
 *
 * Reads the level on a pin
 */
static inline bool PA5_get_level() {
    return PORTA_get_pin_level(5);
}

/**
 * \brief Set PA6 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void PA6_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTA_set_pin_pull_mode(6, pull_mode);
}

/**
 * \brief Set PA6 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PA6_set_dir(const enum port_dir dir) {
    PORTA_set_pin_dir(6, dir);
}

/**
 * \brief Set PA6 input/sense configuration
 *
 * Enable/disable PA6 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PA6_set_isc(const PORT_ISC_t isc) {
    PORTA_pin_set_isc(6, isc);
}

/**
 * \brief Set PA6 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PA6 is inverted
 *                     false = I/O on PA6 is not inverted
 */
static inline void PA6_set_inverted(const bool inverted) {
    PORTA_pin_set_inverted(6, inverted);
}

/**
 * \brief Set PA6 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PA6_set_level(const bool level) {
    PORTA_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on PA6
 *
 * Toggle the pin level
 */
static inline void PA6_toggle_level() {
    PORTA_toggle_pin_level(6);
}

/**
 * \brief Get level on PA6
 *
 * Reads the level on a pin
 */
static inline bool PA6_get_level() {
    return PORTA_get_pin_level(6);
}

/**
 * \brief Set A4 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void A4_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTA_set_pin_pull_mode(7, pull_mode);
}

/**
 * \brief Set A4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void A4_set_dir(const enum port_dir dir) {
    PORTA_set_pin_dir(7, dir);
}

/**
 * \brief Set A4 input/sense configuration
 *
 * Enable/disable A4 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void A4_set_isc(const PORT_ISC_t isc) {
    PORTA_pin_set_isc(7, isc);
}

/**
 * \brief Set A4 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on A4 is inverted
 *                     false = I/O on A4 is not inverted
 */
static inline void A4_set_inverted(const bool inverted) {
    PORTA_pin_set_inverted(7, inverted);
}

/**
 * \brief Set A4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void A4_set_level(const bool level) {
    PORTA_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on A4
 *
 * Toggle the pin level
 */
static inline void A4_toggle_level() {
    PORTA_toggle_pin_level(7);
}

/**
 * \brief Get level on A4
 *
 * Reads the level on a pin
 */
static inline bool A4_get_level() {
    return PORTA_get_pin_level(7);
}

/**
 * \brief Set IR_LED pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void IR_LED_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTB_set_pin_pull_mode(0, pull_mode);
}

/**
 * \brief Set IR_LED data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void IR_LED_set_dir(const enum port_dir dir) {
    PORTB_set_pin_dir(0, dir);
}

/**
 * \brief Set IR_LED input/sense configuration
 *
 * Enable/disable IR_LED digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void IR_LED_set_isc(const PORT_ISC_t isc) {
    PORTB_pin_set_isc(0, isc);
}

/**
 * \brief Set IR_LED inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on IR_LED is inverted
 *                     false = I/O on IR_LED is not inverted
 */
static inline void IR_LED_set_inverted(const bool inverted) {
    PORTB_pin_set_inverted(0, inverted);
}

/**
 * \brief Set IR_LED level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void IR_LED_set_level(const bool level) {
    PORTB_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on IR_LED
 *
 * Toggle the pin level
 */
static inline void IR_LED_toggle_level() {
    PORTB_toggle_pin_level(0);
}

/**
 * \brief Get level on IR_LED
 *
 * Reads the level on a pin
 */
static inline bool IR_LED_get_level() {
    return PORTB_get_pin_level(0);
}

/**
 * \brief Set IR_SENSE pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void IR_SENSE_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTB_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set IR_SENSE data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void IR_SENSE_set_dir(const enum port_dir dir) {
    PORTB_set_pin_dir(1, dir);
}

/**
 * \brief Set IR_SENSE input/sense configuration
 *
 * Enable/disable IR_SENSE digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void IR_SENSE_set_isc(const PORT_ISC_t isc) {
    PORTB_pin_set_isc(1, isc);
}

/**
 * \brief Set IR_SENSE inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on IR_SENSE is inverted
 *                     false = I/O on IR_SENSE is not inverted
 */
static inline void IR_SENSE_set_inverted(const bool inverted) {
    PORTB_pin_set_inverted(1, inverted);
}

/**
 * \brief Set IR_SENSE level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void IR_SENSE_set_level(const bool level) {
    PORTB_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on IR_SENSE
 *
 * Toggle the pin level
 */
static inline void IR_SENSE_toggle_level() {
    PORTB_toggle_pin_level(1);
}

/**
 * \brief Get level on IR_SENSE
 *
 * Reads the level on a pin
 */
static inline bool IR_SENSE_get_level() {
    return PORTB_get_pin_level(1);
}

/**
 * \brief Set A0 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void A0_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTB_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set A0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void A0_set_dir(const enum port_dir dir) {
    PORTB_set_pin_dir(2, dir);
}

/**
 * \brief Set A0 input/sense configuration
 *
 * Enable/disable A0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void A0_set_isc(const PORT_ISC_t isc) {
    PORTB_pin_set_isc(2, isc);
}

/**
 * \brief Set A0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on A0 is inverted
 *                     false = I/O on A0 is not inverted
 */
static inline void A0_set_inverted(const bool inverted) {
    PORTB_pin_set_inverted(2, inverted);
}

/**
 * \brief Set A0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void A0_set_level(const bool level) {
    PORTB_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on A0
 *
 * Toggle the pin level
 */
static inline void A0_toggle_level() {
    PORTB_toggle_pin_level(2);
}

/**
 * \brief Get level on A0
 *
 * Reads the level on a pin
 */
static inline bool A0_get_level() {
    return PORTB_get_pin_level(2);
}

/**
 * \brief Set A1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void A1_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTB_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set A1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void A1_set_dir(const enum port_dir dir) {
    PORTB_set_pin_dir(3, dir);
}

/**
 * \brief Set A1 input/sense configuration
 *
 * Enable/disable A1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void A1_set_isc(const PORT_ISC_t isc) {
    PORTB_pin_set_isc(3, isc);
}

/**
 * \brief Set A1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on A1 is inverted
 *                     false = I/O on A1 is not inverted
 */
static inline void A1_set_inverted(const bool inverted) {
    PORTB_pin_set_inverted(3, inverted);
}

/**
 * \brief Set A1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void A1_set_level(const bool level) {
    PORTB_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on A1
 *
 * Toggle the pin level
 */
static inline void A1_toggle_level() {
    PORTB_toggle_pin_level(3);
}

/**
 * \brief Get level on A1
 *
 * Reads the level on a pin
 */
static inline bool A1_get_level() {
    return PORTB_get_pin_level(3);
}

/**
 * \brief Set A2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void A2_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTB_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set A2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void A2_set_dir(const enum port_dir dir) {
    PORTB_set_pin_dir(4, dir);
}

/**
 * \brief Set A2 input/sense configuration
 *
 * Enable/disable A2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void A2_set_isc(const PORT_ISC_t isc) {
    PORTB_pin_set_isc(4, isc);
}

/**
 * \brief Set A2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on A2 is inverted
 *                     false = I/O on A2 is not inverted
 */
static inline void A2_set_inverted(const bool inverted) {
    PORTB_pin_set_inverted(4, inverted);
}

/**
 * \brief Set A2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void A2_set_level(const bool level) {
    PORTB_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on A2
 *
 * Toggle the pin level
 */
static inline void A2_toggle_level() {
    PORTB_toggle_pin_level(4);
}

/**
 * \brief Get level on A2
 *
 * Reads the level on a pin
 */
static inline bool A2_get_level() {
    return PORTB_get_pin_level(4);
}

/**
 * \brief Set A3 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void A3_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTB_set_pin_pull_mode(5, pull_mode);
}

/**
 * \brief Set A3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void A3_set_dir(const enum port_dir dir) {
    PORTB_set_pin_dir(5, dir);
}

/**
 * \brief Set A3 input/sense configuration
 *
 * Enable/disable A3 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void A3_set_isc(const PORT_ISC_t isc) {
    PORTB_pin_set_isc(5, isc);
}

/**
 * \brief Set A3 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on A3 is inverted
 *                     false = I/O on A3 is not inverted
 */
static inline void A3_set_inverted(const bool inverted) {
    PORTB_pin_set_inverted(5, inverted);
}

/**
 * \brief Set A3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void A3_set_level(const bool level) {
    PORTB_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on A3
 *
 * Toggle the pin level
 */
static inline void A3_toggle_level() {
    PORTB_toggle_pin_level(5);
}

/**
 * \brief Get level on A3
 *
 * Reads the level on a pin
 */
static inline bool A3_get_level() {
    return PORTB_get_pin_level(5);
}

/**
 * \brief Set touch_trig pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void sense_trig_set_pull_mode(const enum port_pull_mode pull_mode) {
    PORTC_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set touch_trig data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void sense_trig_set_dir(const enum port_dir dir) {
    PORTC_set_pin_dir(3, dir);
}

/**
 * \brief Set touch_trig input/sense configuration
 *
 * Enable/disable touch_trig digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void sense_trig_set_isc(const PORT_ISC_t isc) {
    PORTC_pin_set_isc(3, isc);
}

/**
 * \brief Set touch_trig inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on touch_trig is inverted
 *                     false = I/O on touch_trig is not inverted
 */
static inline void sense_trig_set_inverted(const bool inverted) {
    PORTC_pin_set_inverted(3, inverted);
}

/**
 * \brief Set touch_trig level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void sense_trig_set_level(const bool level) {
    PORTC_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on touch_trig
 *
 * Toggle the pin level
 */
static inline void sense_trig_toggle_level() {
    PORTC_toggle_pin_level(3);
}

/**
 * \brief Get level on touch_trig
 *
 * Reads the level on a pin
 */
static inline bool sense_trig_get_level() {
    return PORTC_get_pin_level(3);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
