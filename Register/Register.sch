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
L Connector_Generic:Conn_01x16 J1
U 1 1 5FA93B6C
P 1600 3450
F 0 "J1" H 1200 4400 50  0000 L CNN
F 1 "Conn_01x16" H 1200 4300 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Horizontal" H 1600 3450 50  0001 C CNN
F 3 "~" H 1600 3450 50  0001 C CNN
	1    1600 3450
	1    0    0    -1  
$EndComp
Text GLabel 1250 2750 0    50   Input ~ 0
GND
Wire Wire Line
	1250 2750 1400 2750
Text GLabel 1250 2850 0    50   Input ~ 0
VCC
Text GLabel 1250 2950 0    50   Input ~ 0
RESET
Text GLabel 1250 3050 0    50   Input ~ 0
CLOCK
Text GLabel 1250 3250 0    50   Input ~ 0
SIG_IN
Text GLabel 1250 3150 0    50   Input ~ 0
SIG_OUT
Text GLabel 1250 3350 0    50   Input ~ 0
SIG0
Text GLabel 1250 3450 0    50   Input ~ 0
SIG1
Text GLabel 1250 3550 0    50   Input ~ 0
BUS0
Text GLabel 1250 3650 0    50   Input ~ 0
BUS1
Text GLabel 1250 3750 0    50   Input ~ 0
BUS2
Text GLabel 1250 3850 0    50   Input ~ 0
BUS3
Text GLabel 1250 3950 0    50   Input ~ 0
BUS4
Text GLabel 1250 4050 0    50   Input ~ 0
BUS5
Text GLabel 1250 4150 0    50   Input ~ 0
BUS6
Text GLabel 1250 4250 0    50   Input ~ 0
BUS7
Wire Wire Line
	1250 2850 1400 2850
Wire Wire Line
	1250 2950 1400 2950
Wire Wire Line
	1250 3050 1400 3050
Wire Wire Line
	1250 3150 1400 3150
Wire Wire Line
	1250 3250 1400 3250
Wire Wire Line
	1250 3350 1400 3350
Wire Wire Line
	1250 3450 1400 3450
Wire Wire Line
	1250 3550 1400 3550
Wire Wire Line
	1250 3650 1400 3650
Wire Wire Line
	1250 3750 1400 3750
Wire Wire Line
	1250 3850 1400 3850
Wire Wire Line
	1250 3950 1400 3950
Wire Wire Line
	1250 4050 1400 4050
Wire Wire Line
	1250 4150 1400 4150
Wire Wire Line
	1400 4250 1250 4250
$Comp
L Connector_Generic:Conn_01x16 J2
U 1 1 5FAA0F3D
P 1850 3550
F 0 "J2" H 1800 2500 50  0000 L CNN
F 1 "Conn_01x16" H 1450 2600 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Horizontal" H 1850 3550 50  0001 C CNN
F 3 "~" H 1850 3550 50  0001 C CNN
	1    1850 3550
	-1   0    0    1   
$EndComp
Text GLabel 2200 2750 2    50   Input ~ 0
GND
Wire Wire Line
	2200 4250 2050 4250
Text GLabel 2200 2850 2    50   Input ~ 0
VCC
Text GLabel 2200 2950 2    50   Input ~ 0
RESET
Text GLabel 2200 3050 2    50   Input ~ 0
CLOCK
Text GLabel 2200 3250 2    50   Input ~ 0
SIG_IN
Text GLabel 2200 3150 2    50   Input ~ 0
SIG_OUT
Text GLabel 2200 3350 2    50   Input ~ 0
SIG0
Text GLabel 2200 3450 2    50   Input ~ 0
SIG1
Text GLabel 2200 3550 2    50   Input ~ 0
BUS0
Text GLabel 2200 3650 2    50   Input ~ 0
BUS1
Text GLabel 2200 3750 2    50   Input ~ 0
BUS2
Text GLabel 2200 3850 2    50   Input ~ 0
BUS3
Text GLabel 2200 3950 2    50   Input ~ 0
BUS4
Text GLabel 2200 4050 2    50   Input ~ 0
BUS5
Text GLabel 2200 4150 2    50   Input ~ 0
BUS6
Text GLabel 2200 4250 2    50   Input ~ 0
BUS7
Wire Wire Line
	2200 4150 2050 4150
Wire Wire Line
	2200 4050 2050 4050
Wire Wire Line
	2200 3950 2050 3950
Wire Wire Line
	2200 3850 2050 3850
Wire Wire Line
	2200 3750 2050 3750
Wire Wire Line
	2200 3650 2050 3650
Wire Wire Line
	2200 3550 2050 3550
Wire Wire Line
	2200 3450 2050 3450
Wire Wire Line
	2200 3350 2050 3350
Wire Wire Line
	2200 3250 2050 3250
Wire Wire Line
	2200 3150 2050 3150
Wire Wire Line
	2200 3050 2050 3050
Wire Wire Line
	2200 2950 2050 2950
Wire Wire Line
	2200 2850 2050 2850
Wire Wire Line
	2050 2750 2200 2750
$Comp
L 74xx:74LS173 U2
U 1 1 5F4C51CA
P 6650 1900
F 0 "U2" H 6850 2750 50  0000 C CNN
F 1 "74LS173" H 6850 2650 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 6650 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS173" H 6650 1900 50  0001 C CNN
	1    6650 1900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS173 U3
U 1 1 5F4C8B84
P 6650 3950
F 0 "U3" H 6850 4800 50  0000 C CNN
F 1 "74LS173" H 6850 4700 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 6650 3950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS173" H 6650 3950 50  0001 C CNN
	1    6650 3950
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS245 U4
U 1 1 5F4CA6E5
P 9300 2250
F 0 "U4" H 9500 3000 50  0000 C CNN
F 1 "74LS245" H 9500 2900 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm" H 9300 2250 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS245" H 9300 2250 50  0001 C CNN
	1    9300 2250
	1    0    0    -1  
$EndComp
$Comp
L Register-rescue:SN74LS04N-dk_Logic-Gates-and-Inverters U1
U 1 1 5F4D085A
P 4700 3600
F 0 "U1" H 4700 4403 60  0000 C CNN
F 1 "SN74LS04N" H 4700 4297 60  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 4900 3800 60  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74ls04.pdf" H 4900 3900 60  0001 L CNN
F 4 "296-1629-5-ND" H 4900 4000 60  0001 L CNN "Digi-Key_PN"
F 5 "SN74LS04N" H 4900 4100 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 4900 4200 60  0001 L CNN "Category"
F 7 "Logic - Gates and Inverters" H 4900 4300 60  0001 L CNN "Family"
F 8 "http://www.ti.com/lit/ds/symlink/sn74ls04.pdf" H 4900 4400 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/texas-instruments/SN74LS04N/296-1629-5-ND/277275" H 4900 4500 60  0001 L CNN "DK_Detail_Page"
F 10 "IC INVERTER 6CH 6-INP 14DIP" H 4900 4600 60  0001 L CNN "Description"
F 11 "Texas Instruments" H 4900 4700 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4900 4800 60  0001 L CNN "Status"
	1    4700 3600
	1    0    0    -1  
$EndComp
Text GLabel 8700 2650 0    50   Input ~ 0
VCC
Wire Wire Line
	8700 2650 8800 2650
Text GLabel 6050 1300 0    50   Input ~ 0
BUS0
Text GLabel 6050 1400 0    50   Input ~ 0
BUS1
Text GLabel 6050 1500 0    50   Input ~ 0
BUS2
Text GLabel 6050 1600 0    50   Input ~ 0
BUS3
Text GLabel 6050 3350 0    50   Input ~ 0
BUS4
Text GLabel 6050 3450 0    50   Input ~ 0
BUS5
Text GLabel 6050 3550 0    50   Input ~ 0
BUS6
Text GLabel 6050 3650 0    50   Input ~ 0
BUS7
Wire Wire Line
	6050 1300 6150 1300
Wire Wire Line
	6050 1400 6150 1400
Wire Wire Line
	6050 1500 6150 1500
Wire Wire Line
	6050 1600 6150 1600
Wire Wire Line
	6050 3350 6150 3350
Wire Wire Line
	6050 3450 6150 3450
Wire Wire Line
	6050 3550 6150 3550
Wire Wire Line
	6050 3650 6150 3650
Text GLabel 6050 1850 0    50   Input ~ 0
GND
Wire Wire Line
	6050 1850 6150 1850
Wire Wire Line
	6150 1850 6150 1800
Wire Wire Line
	6150 1850 6150 1900
Connection ~ 6150 1850
Text GLabel 6050 3900 0    50   Input ~ 0
GND
Wire Wire Line
	6050 3900 6150 3900
Wire Wire Line
	6150 3900 6150 3950
Wire Wire Line
	6150 3850 6150 3900
Connection ~ 6150 3900
Text GLabel 8700 2750 0    50   Input ~ 0
~SIG_OUT
Wire Wire Line
	8700 2750 8800 2750
Text GLabel 4300 3300 0    50   Input ~ 0
SIG_OUT
Text GLabel 5100 3300 2    50   Input ~ 0
~SIG_OUT
Wire Wire Line
	4300 3400 4400 3400
Wire Wire Line
	5000 3400 5100 3400
Text GLabel 4300 3400 0    50   Input ~ 0
SIG_IN
Text GLabel 5100 3400 2    50   Input ~ 0
~SIG_IN
Wire Wire Line
	5100 3300 5000 3300
Wire Wire Line
	4400 3300 4300 3300
Text GLabel 6050 2150 0    50   Input ~ 0
~SIG_IN
Wire Wire Line
	6050 2150 6150 2150
Wire Wire Line
	6150 2150 6150 2100
Wire Wire Line
	6150 2200 6150 2150
Connection ~ 6150 2150
Text GLabel 6050 4200 0    50   Input ~ 0
~SIG_IN
Wire Wire Line
	6050 4200 6150 4200
Wire Wire Line
	6150 4200 6150 4150
Wire Wire Line
	6150 4250 6150 4200
Connection ~ 6150 4200
Text GLabel 6550 2800 0    50   Input ~ 0
GND
Wire Wire Line
	6550 2800 6650 2800
Wire Wire Line
	9950 2450 9800 2450
Text GLabel 9950 1750 2    50   Input ~ 0
BUS0
Text GLabel 9950 1850 2    50   Input ~ 0
BUS1
Text GLabel 9950 1950 2    50   Input ~ 0
BUS2
Text GLabel 9950 2050 2    50   Input ~ 0
BUS3
Text GLabel 9950 2150 2    50   Input ~ 0
BUS4
Text GLabel 9950 2250 2    50   Input ~ 0
BUS5
Text GLabel 9950 2350 2    50   Input ~ 0
BUS6
Text GLabel 9950 2450 2    50   Input ~ 0
BUS7
Wire Wire Line
	9950 2350 9800 2350
Wire Wire Line
	9950 2250 9800 2250
Wire Wire Line
	9950 2150 9800 2150
Wire Wire Line
	9950 2050 9800 2050
Wire Wire Line
	9950 1950 9800 1950
Wire Wire Line
	9950 1850 9800 1850
Wire Wire Line
	9950 1750 9800 1750
Text GLabel 6050 4550 0    50   Input ~ 0
RESET
Wire Wire Line
	6050 2500 6150 2500
Wire Wire Line
	6050 4550 6150 4550
Text GLabel 6050 2500 0    50   Input ~ 0
RESET
Text GLabel 6050 2300 0    50   Input ~ 0
CLOCK
Wire Wire Line
	6050 2300 6150 2300
Text GLabel 6050 4350 0    50   Input ~ 0
CLOCK
Wire Wire Line
	6050 4350 6150 4350
Text GLabel 4600 3000 0    50   Input ~ 0
VCC
Text GLabel 6550 3050 0    50   Input ~ 0
VCC
Wire Wire Line
	6550 3050 6650 3050
Text GLabel 6550 1000 0    50   Input ~ 0
VCC
Text GLabel 6650 4950 3    50   Input ~ 0
GND
Wire Wire Line
	6650 4950 6650 4850
Text GLabel 9200 1450 0    50   Input ~ 0
VCC
Wire Wire Line
	9200 1450 9300 1450
Text GLabel 9200 3050 0    50   Input ~ 0
GND
Wire Wire Line
	9200 3050 9300 3050
Text GLabel 7250 1300 2    50   Input ~ 0
R0
Wire Wire Line
	7250 1300 7150 1300
Text GLabel 7250 1400 2    50   Input ~ 0
R1
Text GLabel 7250 1500 2    50   Input ~ 0
R2
Text GLabel 7250 1600 2    50   Input ~ 0
R3
Wire Wire Line
	7250 1400 7150 1400
Wire Wire Line
	7250 1500 7150 1500
Wire Wire Line
	7250 1600 7150 1600
Text GLabel 7250 3350 2    50   Input ~ 0
R4
Wire Wire Line
	7250 3350 7150 3350
Text GLabel 7250 3450 2    50   Input ~ 0
R5
Text GLabel 7250 3550 2    50   Input ~ 0
R6
Text GLabel 7250 3650 2    50   Input ~ 0
R7
Wire Wire Line
	7250 3450 7150 3450
Wire Wire Line
	7250 3550 7150 3550
Wire Wire Line
	7250 3650 7150 3650
Text GLabel 8650 1750 0    50   Input ~ 0
R0
Text GLabel 8650 1850 0    50   Input ~ 0
R1
Text GLabel 8650 1950 0    50   Input ~ 0
R2
Text GLabel 8650 2050 0    50   Input ~ 0
R3
Text GLabel 8650 2150 0    50   Input ~ 0
R4
Text GLabel 8650 2250 0    50   Input ~ 0
R5
Text GLabel 8650 2350 0    50   Input ~ 0
R6
Text GLabel 8650 2450 0    50   Input ~ 0
R7
Wire Wire Line
	8800 2450 8650 2450
Wire Wire Line
	8800 2350 8650 2350
Wire Wire Line
	8800 2250 8650 2250
Wire Wire Line
	8800 2150 8650 2150
Wire Wire Line
	8800 2050 8650 2050
Wire Wire Line
	8800 1950 8650 1950
Wire Wire Line
	8800 1850 8650 1850
Wire Wire Line
	8800 1750 8650 1750
Text GLabel 4500 4300 3    50   Input ~ 0
GND
$Comp
L Connector_Generic:Conn_01x08 J4
U 1 1 5F5AAC95
P 4550 1250
F 0 "J4" V 4675 1196 50  0000 C CNN
F 1 "Conn_01x08" V 4766 1196 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Horizontal" H 4550 1250 50  0001 C CNN
F 3 "~" H 4550 1250 50  0001 C CNN
	1    4550 1250
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J3
U 1 1 5F5AE57D
P 4450 1900
F 0 "J3" V 4667 1846 50  0000 C CNN
F 1 "Conn_01x08" V 4576 1846 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Horizontal" H 4450 1900 50  0001 C CNN
F 3 "~" H 4450 1900 50  0001 C CNN
	1    4450 1900
	0    -1   -1   0   
$EndComp
Text GLabel 4150 2250 3    50   Input ~ 0
R0
Text GLabel 4250 2250 3    50   Input ~ 0
R1
Text GLabel 4350 2250 3    50   Input ~ 0
R2
Text GLabel 4450 2250 3    50   Input ~ 0
R3
Text GLabel 4550 2250 3    50   Input ~ 0
R4
Text GLabel 4650 2250 3    50   Input ~ 0
R5
Text GLabel 4750 2250 3    50   Input ~ 0
R6
Text GLabel 4850 2250 3    50   Input ~ 0
R7
Wire Wire Line
	4850 2100 4850 2250
Wire Wire Line
	4750 2100 4750 2250
Wire Wire Line
	4650 2100 4650 2250
Wire Wire Line
	4550 2100 4550 2250
Wire Wire Line
	4450 2100 4450 2250
Wire Wire Line
	4350 2100 4350 2250
Wire Wire Line
	4250 2100 4250 2250
Wire Wire Line
	4150 2100 4150 2250
Text GLabel 4150 900  1    50   Input ~ 0
R0
Text GLabel 4250 900  1    50   Input ~ 0
R1
Text GLabel 4350 900  1    50   Input ~ 0
R2
Text GLabel 4450 900  1    50   Input ~ 0
R3
Text GLabel 4550 900  1    50   Input ~ 0
R4
Text GLabel 4650 900  1    50   Input ~ 0
R5
Text GLabel 4750 900  1    50   Input ~ 0
R6
Text GLabel 4850 900  1    50   Input ~ 0
R7
Wire Wire Line
	4850 900  4850 1050
Wire Wire Line
	4750 900  4750 1050
Wire Wire Line
	4650 900  4650 1050
Wire Wire Line
	4550 900  4550 1050
Wire Wire Line
	4450 900  4450 1050
Wire Wire Line
	4350 900  4350 1050
Wire Wire Line
	4250 900  4250 1050
Wire Wire Line
	4150 900  4150 1050
Text GLabel 10300 4500 1    50   Input ~ 0
R0
Text GLabel 9950 4500 1    50   Input ~ 0
R1
Text GLabel 9600 4500 1    50   Input ~ 0
R2
Text GLabel 9250 4500 1    50   Input ~ 0
R3
Text GLabel 8850 4500 1    50   Input ~ 0
R4
Text GLabel 8500 4500 1    50   Input ~ 0
R5
Text GLabel 8150 4500 1    50   Input ~ 0
R6
Text GLabel 7800 4500 1    50   Input ~ 0
R7
Wire Wire Line
	10300 4500 10300 4650
Wire Wire Line
	9950 4500 9950 4650
Wire Wire Line
	9600 4500 9600 4650
Wire Wire Line
	9250 4500 9250 4650
Wire Wire Line
	8850 4500 8850 4650
Wire Wire Line
	8500 4500 8500 4650
$Comp
L Device:R_Network08_US RN1
U 1 1 5F601876
P 9000 5450
F 0 "RN1" H 8520 5404 50  0000 R CNN
F 1 "1k" H 8520 5495 50  0000 R CNN
F 2 "Resistor_THT:R_Array_SIP9" V 9475 5450 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 9000 5450 50  0001 C CNN
	1    9000 5450
	-1   0    0    1   
$EndComp
Text GLabel 9400 5750 3    50   Input ~ 0
GND
Wire Wire Line
	9400 5750 9400 5650
Wire Wire Line
	8900 5150 8900 5250
Wire Wire Line
	9000 5100 9000 5250
Wire Wire Line
	9100 5100 9100 5250
Wire Wire Line
	9200 5150 9200 5250
Wire Wire Line
	9300 5200 9300 5250
Wire Wire Line
	10300 5250 9400 5250
Wire Wire Line
	8150 4500 8150 4650
Wire Wire Line
	8800 5200 8800 5250
Wire Wire Line
	7800 4500 7800 4650
$Comp
L Device:LED D1
U 1 1 5F6839C1
P 7800 4800
F 0 "D1" V 7839 4683 50  0000 R CNN
F 1 "LED" V 7748 4683 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 7800 4800 50  0001 C CNN
F 3 "~" H 7800 4800 50  0001 C CNN
	1    7800 4800
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5F69BED4
P 8150 4800
F 0 "D2" V 8189 4683 50  0000 R CNN
F 1 "LED" V 8098 4683 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 8150 4800 50  0001 C CNN
F 3 "~" H 8150 4800 50  0001 C CNN
	1    8150 4800
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D3
U 1 1 5F69C8D2
P 8500 4800
F 0 "D3" V 8539 4683 50  0000 R CNN
F 1 "LED" V 8448 4683 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 8500 4800 50  0001 C CNN
F 3 "~" H 8500 4800 50  0001 C CNN
	1    8500 4800
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D4
U 1 1 5F69D100
P 8850 4800
F 0 "D4" V 8889 4683 50  0000 R CNN
F 1 "LED" V 8798 4683 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 8850 4800 50  0001 C CNN
F 3 "~" H 8850 4800 50  0001 C CNN
	1    8850 4800
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D5
U 1 1 5F69D63C
P 9250 4800
F 0 "D5" V 9289 4683 50  0000 R CNN
F 1 "LED" V 9198 4683 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 9250 4800 50  0001 C CNN
F 3 "~" H 9250 4800 50  0001 C CNN
	1    9250 4800
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D6
U 1 1 5F69DE30
P 9600 4800
F 0 "D6" V 9639 4683 50  0000 R CNN
F 1 "LED" V 9548 4683 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 9600 4800 50  0001 C CNN
F 3 "~" H 9600 4800 50  0001 C CNN
	1    9600 4800
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D7
U 1 1 5F69E7F4
P 9950 4800
F 0 "D7" V 9989 4683 50  0000 R CNN
F 1 "LED" V 9898 4683 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 9950 4800 50  0001 C CNN
F 3 "~" H 9950 4800 50  0001 C CNN
	1    9950 4800
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D8
U 1 1 5F69F096
P 10300 4800
F 0 "D8" V 10339 4683 50  0000 R CNN
F 1 "LED" V 10248 4683 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 10300 4800 50  0001 C CNN
F 3 "~" H 10300 4800 50  0001 C CNN
	1    10300 4800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9100 5100 9250 5100
Wire Wire Line
	9000 5100 8850 5100
Wire Wire Line
	8500 5150 8900 5150
Wire Wire Line
	7800 5250 7800 4950
Wire Wire Line
	7800 5250 8700 5250
Wire Wire Line
	8150 5200 8150 4950
Wire Wire Line
	8150 5200 8800 5200
Wire Wire Line
	8500 5150 8500 4950
Wire Wire Line
	8850 5100 8850 4950
Wire Wire Line
	9250 5100 9250 4950
Wire Wire Line
	10300 5250 10300 4950
Wire Wire Line
	9600 5150 9600 4950
Wire Wire Line
	9200 5150 9600 5150
Wire Wire Line
	9950 5200 9950 4950
Wire Wire Line
	9300 5200 9950 5200
NoConn ~ 5000 3500
NoConn ~ 5000 3600
NoConn ~ 5000 3700
NoConn ~ 5000 3800
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5F8B6D7C
P 1250 1850
F 0 "#FLG02" H 1250 1925 50  0001 C CNN
F 1 "PWR_FLAG" H 1250 2023 50  0000 C CNN
F 2 "" H 1250 1850 50  0001 C CNN
F 3 "~" H 1250 1850 50  0001 C CNN
	1    1250 1850
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5F8B890C
P 1250 1300
F 0 "#FLG01" H 1250 1375 50  0001 C CNN
F 1 "PWR_FLAG" H 1250 1473 50  0000 C CNN
F 2 "" H 1250 1300 50  0001 C CNN
F 3 "~" H 1250 1300 50  0001 C CNN
	1    1250 1300
	-1   0    0    1   
$EndComp
Text GLabel 1250 2000 3    50   Input ~ 0
GND
Wire Wire Line
	1250 2000 1250 1850
Text GLabel 1250 1150 1    50   Input ~ 0
VCC
Wire Wire Line
	1250 1150 1250 1300
$Comp
L Device:C_Small C1
U 1 1 5F8DF5FF
P 1850 1600
F 0 "C1" H 1942 1646 50  0000 L CNN
F 1 "100nF" H 1942 1555 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 1850 1600 50  0001 C CNN
F 3 "~" H 1850 1600 50  0001 C CNN
	1    1850 1600
	1    0    0    -1  
$EndComp
Text GLabel 1850 1400 1    50   Input ~ 0
VCC
Text GLabel 1850 1800 3    50   Input ~ 0
GND
Wire Wire Line
	1850 1400 1850 1500
Wire Wire Line
	1850 1700 1850 1800
$Comp
L Device:C_Small C2
U 1 1 5F8EBE4B
P 2300 1600
F 0 "C2" H 2392 1646 50  0000 L CNN
F 1 "100nF" H 2392 1555 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 2300 1600 50  0001 C CNN
F 3 "~" H 2300 1600 50  0001 C CNN
	1    2300 1600
	1    0    0    -1  
$EndComp
Text GLabel 2300 1400 1    50   Input ~ 0
VCC
Text GLabel 2300 1800 3    50   Input ~ 0
GND
Wire Wire Line
	2300 1400 2300 1500
Wire Wire Line
	2300 1700 2300 1800
Wire Wire Line
	6550 1000 6650 1000
Wire Wire Line
	4600 3000 4700 3000
$Comp
L Device:C_Small C3
U 1 1 5F7B91BE
P 2750 1600
F 0 "C3" H 2842 1646 50  0000 L CNN
F 1 "100nF" H 2842 1555 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 2750 1600 50  0001 C CNN
F 3 "~" H 2750 1600 50  0001 C CNN
	1    2750 1600
	1    0    0    -1  
$EndComp
Text GLabel 2750 1400 1    50   Input ~ 0
VCC
Text GLabel 2750 1800 3    50   Input ~ 0
GND
Wire Wire Line
	2750 1400 2750 1500
Wire Wire Line
	2750 1700 2750 1800
$Comp
L Device:C_Small C4
U 1 1 5F7B91C8
P 3200 1600
F 0 "C4" H 3292 1646 50  0000 L CNN
F 1 "100nF" H 3292 1555 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 3200 1600 50  0001 C CNN
F 3 "~" H 3200 1600 50  0001 C CNN
	1    3200 1600
	1    0    0    -1  
$EndComp
Text GLabel 3200 1400 1    50   Input ~ 0
VCC
Text GLabel 3200 1800 3    50   Input ~ 0
GND
Wire Wire Line
	3200 1400 3200 1500
Wire Wire Line
	3200 1700 3200 1800
$Comp
L Connector_Generic:Conn_01x12 J5
U 1 1 605159BF
P 3400 3250
F 0 "J5" H 3000 4000 50  0000 L CNN
F 1 "Conn_01x12" H 3000 3900 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 3400 3250 50  0001 C CNN
F 3 "~" H 3400 3250 50  0001 C CNN
	1    3400 3250
	1    0    0    -1  
$EndComp
Text GLabel 3050 2950 0    50   Input ~ 0
R0
Text GLabel 3050 3050 0    50   Input ~ 0
R1
Text GLabel 3050 3150 0    50   Input ~ 0
R2
Text GLabel 3050 3250 0    50   Input ~ 0
R3
Text GLabel 3050 3350 0    50   Input ~ 0
R4
Text GLabel 3050 3450 0    50   Input ~ 0
R5
Text GLabel 3050 3550 0    50   Input ~ 0
R6
Text GLabel 3050 3650 0    50   Input ~ 0
R7
Wire Wire Line
	3200 3650 3050 3650
Wire Wire Line
	3200 3550 3050 3550
Wire Wire Line
	3200 3450 3050 3450
Wire Wire Line
	3200 3350 3050 3350
Wire Wire Line
	3200 3250 3050 3250
Wire Wire Line
	3200 3150 3050 3150
Wire Wire Line
	3200 3050 3050 3050
Wire Wire Line
	3200 2950 3050 2950
Text GLabel 3050 2750 0    50   Input ~ 0
GND
Wire Wire Line
	3050 2750 3200 2750
Text GLabel 3050 2850 0    50   Input ~ 0
VCC
Wire Wire Line
	3050 2850 3200 2850
Text GLabel 3050 3750 0    50   Input ~ 0
GND
Wire Wire Line
	3050 3750 3200 3750
Text GLabel 3050 3850 0    50   Input ~ 0
VCC
Wire Wire Line
	3050 3850 3200 3850
Wire Wire Line
	4400 3500 4300 3500
Wire Wire Line
	4300 3500 4300 3600
Wire Wire Line
	4400 3600 4300 3600
Connection ~ 4300 3600
Wire Wire Line
	4300 3600 4300 3700
Wire Wire Line
	4400 3700 4300 3700
Connection ~ 4300 3700
Wire Wire Line
	4300 3700 4300 3800
Wire Wire Line
	4400 3800 4300 3800
$Comp
L Device:R_Small_US R1
U 1 1 60473EB3
P 4300 4000
F 0 "R1" H 4232 3954 50  0000 R CNN
F 1 "10k" H 4232 4045 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 4300 4000 50  0001 C CNN
F 3 "~" H 4300 4000 50  0001 C CNN
	1    4300 4000
	-1   0    0    1   
$EndComp
Wire Wire Line
	4300 3800 4300 3900
Connection ~ 4300 3800
Wire Wire Line
	4300 4100 4300 4200
Wire Wire Line
	4300 4200 4500 4200
Wire Wire Line
	4700 4200 4700 4100
Wire Wire Line
	4500 4300 4500 4200
Connection ~ 4500 4200
Wire Wire Line
	4500 4200 4700 4200
$EndSCHEMATC
