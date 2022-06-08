EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR?
U 1 1 62973F2D
P 2175 4550
F 0 "#PWR?" H 2175 4300 50  0001 C CNN
F 1 "GND" H 2180 4377 50  0000 C CNN
F 2 "" H 2175 4550 50  0001 C CNN
F 3 "" H 2175 4550 50  0001 C CNN
	1    2175 4550
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 6297454D
P 2175 2750
F 0 "#PWR?" H 2175 2600 50  0001 C CNN
F 1 "+3.3V" H 2190 2923 50  0000 C CNN
F 2 "" H 2175 2750 50  0001 C CNN
F 3 "" H 2175 2750 50  0001 C CNN
	1    2175 2750
	1    0    0    -1  
$EndComp
NoConn ~ 1575 3850
NoConn ~ 1575 3950
NoConn ~ 1575 4050
NoConn ~ 2775 4350
NoConn ~ 2775 4250
NoConn ~ 2775 4150
NoConn ~ 2775 4050
NoConn ~ 2775 3950
NoConn ~ 2775 3850
NoConn ~ 2775 3650
NoConn ~ 2775 3250
NoConn ~ 2775 2950
Text GLabel 2775 3550 2    50   Input ~ 0
sense_2
Text GLabel 2775 3450 2    50   Input ~ 0
sense_1
Text GLabel 2775 3350 2    50   Input ~ 0
sense_0
Text GLabel 1575 4150 0    50   Input ~ 0
touch
Text GLabel 2775 3150 2    50   Input ~ 0
I2C_SCL
Text GLabel 2775 3050 2    50   Input ~ 0
I2C_SDA
$Comp
L MCU_Microchip_ATtiny:ATtiny816-S U?
U 1 1 629730BF
P 2175 3650
F 0 "U?" H 1875 4700 50  0000 C CNN
F 1 "ATtiny816-S" H 1825 4575 50  0000 C CNN
F 2 "Package_SO:SOIC-20W_7.5x12.8mm_P1.27mm" H 2175 3650 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/40001913A.pdf" H 2175 3650 50  0001 C CNN
	1    2175 3650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
