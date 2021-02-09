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
U 1 1 601F240E
P 1300 1600
F 0 "J1" H 1150 2550 50  0000 L CNN
F 1 "Conn_01x16" H 900 2450 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Horizontal" H 1300 1600 50  0001 C CNN
F 3 "~" H 1300 1600 50  0001 C CNN
	1    1300 1600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x16 J2
U 1 1 601F3A8E
P 1550 1700
F 0 "J2" H 1300 650 50  0000 L CNN
F 1 "Conn_01x16" H 1150 750 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Horizontal" H 1550 1700 50  0001 C CNN
F 3 "~" H 1550 1700 50  0001 C CNN
	1    1550 1700
	-1   0    0    1   
$EndComp
Text GLabel 1000 900  0    50   Input ~ 0
GND
Wire Wire Line
	1000 900  1100 900 
Text GLabel 1000 1000 0    50   Input ~ 0
VCC
Text GLabel 1000 1100 0    50   Input ~ 0
RESET
Text GLabel 1000 1200 0    50   Input ~ 0
CLOCK
Wire Wire Line
	1000 1000 1100 1000
Wire Wire Line
	1000 1100 1100 1100
Wire Wire Line
	1000 1200 1100 1200
Text GLabel 1000 1300 0    50   Input ~ 0
SIG_OUT
Text GLabel 1000 1400 0    50   Input ~ 0
SIG_IN
Text GLabel 1000 1500 0    50   Input ~ 0
SIG0
Text GLabel 1000 1600 0    50   Input ~ 0
SIG1
Text GLabel 1000 1700 0    50   Input ~ 0
BUS0
Text GLabel 1000 2000 0    50   Input ~ 0
BUS3
Text GLabel 1000 1800 0    50   Input ~ 0
BUS1
Text GLabel 1000 1900 0    50   Input ~ 0
BUS2
Text GLabel 1000 2100 0    50   Input ~ 0
BUS4
Text GLabel 1000 2400 0    50   Input ~ 0
BUS7
Text GLabel 1000 2200 0    50   Input ~ 0
BUS5
Text GLabel 1000 2300 0    50   Input ~ 0
BUS6
Wire Wire Line
	1000 1300 1100 1300
Wire Wire Line
	1000 1400 1100 1400
Wire Wire Line
	1000 1500 1100 1500
Wire Wire Line
	1000 1600 1100 1600
Wire Wire Line
	1000 1700 1100 1700
Wire Wire Line
	1000 1800 1100 1800
Wire Wire Line
	1000 1900 1100 1900
Wire Wire Line
	1000 2000 1100 2000
Wire Wire Line
	1000 2100 1100 2100
Wire Wire Line
	1000 2200 1100 2200
Wire Wire Line
	1000 2300 1100 2300
Wire Wire Line
	1000 2400 1100 2400
Text GLabel 1850 900  2    50   Input ~ 0
GND
Text GLabel 1850 1000 2    50   Input ~ 0
VCC
Text GLabel 1850 1100 2    50   Input ~ 0
RESET
Text GLabel 1850 1200 2    50   Input ~ 0
CLOCK
Text GLabel 1850 1300 2    50   Input ~ 0
SIG_OUT
Text GLabel 1850 1400 2    50   Input ~ 0
SIG_IN
Text GLabel 1850 1500 2    50   Input ~ 0
SIG0
Text GLabel 1850 1600 2    50   Input ~ 0
SIG1
Text GLabel 1850 1700 2    50   Input ~ 0
BUS0
Text GLabel 1850 2000 2    50   Input ~ 0
BUS3
Text GLabel 1850 1800 2    50   Input ~ 0
BUS1
Text GLabel 1850 1900 2    50   Input ~ 0
BUS2
Text GLabel 1850 2100 2    50   Input ~ 0
BUS4
Text GLabel 1850 2400 2    50   Input ~ 0
BUS7
Text GLabel 1850 2200 2    50   Input ~ 0
BUS5
Text GLabel 1850 2300 2    50   Input ~ 0
BUS6
Wire Wire Line
	1750 900  1850 900 
Wire Wire Line
	1750 1000 1850 1000
Wire Wire Line
	1750 1100 1850 1100
Wire Wire Line
	1750 1200 1850 1200
Wire Wire Line
	1750 1300 1850 1300
Wire Wire Line
	1750 1400 1850 1400
Wire Wire Line
	1750 1500 1850 1500
Wire Wire Line
	1750 1600 1850 1600
Wire Wire Line
	1750 1700 1850 1700
Wire Wire Line
	1750 1800 1850 1800
Wire Wire Line
	1750 1900 1850 1900
Wire Wire Line
	1750 2000 1850 2000
Wire Wire Line
	1750 2100 1850 2100
Wire Wire Line
	1750 2200 1850 2200
Wire Wire Line
	1750 2300 1850 2300
Wire Wire Line
	1750 2400 1850 2400
$Comp
L Device:R_Network08 RN1
U 1 1 601FE2B0
P 7650 4400
F 0 "RN1" H 7170 4354 50  0000 R CNN
F 1 "1k" H 7170 4445 50  0000 R CNN
F 2 "Resistor_THT:R_Array_SIP9" V 8125 4400 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 7650 4400 50  0001 C CNN
	1    7650 4400
	-1   0    0    1   
$EndComp
$Comp
L 74xx:74LS245 U3
U 1 1 601FFFAF
P 9300 2950
F 0 "U3" H 9550 3750 50  0000 C CNN
F 1 "74LS245" H 9550 3650 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm" H 9300 2950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS245" H 9300 2950 50  0001 C CNN
	1    9300 2950
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS273 U2
U 1 1 60201CF8
P 6350 2950
F 0 "U2" H 6600 3750 50  0000 C CNN
F 1 "74LS273" H 6600 3650 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm" H 6350 2950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS273" H 6350 2950 50  0001 C CNN
	1    6350 2950
	1    0    0    -1  
$EndComp
Text GLabel 9900 2450 2    50   Input ~ 0
BUS0
Text GLabel 9900 2750 2    50   Input ~ 0
BUS3
Text GLabel 9900 2550 2    50   Input ~ 0
BUS1
Text GLabel 9900 2650 2    50   Input ~ 0
BUS2
Text GLabel 9900 2850 2    50   Input ~ 0
BUS4
Text GLabel 9900 3150 2    50   Input ~ 0
BUS7
Text GLabel 9900 2950 2    50   Input ~ 0
BUS5
Text GLabel 9900 3050 2    50   Input ~ 0
BUS6
Wire Wire Line
	9800 2450 9900 2450
Wire Wire Line
	9800 2550 9900 2550
Wire Wire Line
	9800 2650 9900 2650
Wire Wire Line
	9800 2750 9900 2750
Wire Wire Line
	9800 2850 9900 2850
Wire Wire Line
	9800 2950 9900 2950
Wire Wire Line
	9800 3050 9900 3050
Wire Wire Line
	9800 3150 9900 3150
Text GLabel 9300 3850 3    50   Input ~ 0
GND
Text GLabel 8700 3350 0    50   Input ~ 0
VCC
Wire Wire Line
	8700 3350 8800 3350
Text GLabel 8700 3450 0    50   Input ~ 0
~SIG_OUT
Wire Wire Line
	8700 3450 8800 3450
Wire Wire Line
	9300 3850 9300 3750
Text GLabel 9300 2050 1    50   Input ~ 0
VCC
Wire Wire Line
	9300 2050 9300 2150
$Comp
L 74xx:74LS00 U1
U 1 1 60211B21
P 3050 3350
F 0 "U1" H 3050 3675 50  0000 C CNN
F 1 "74LS00" H 3050 3584 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 3050 3350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 3050 3350 50  0001 C CNN
	1    3050 3350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS00 U1
U 2 1 60215201
P 3650 3350
F 0 "U1" H 3650 3675 50  0000 C CNN
F 1 "74LS00" H 3650 3584 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 3650 3350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 3650 3350 50  0001 C CNN
	2    3650 3350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS00 U1
U 3 1 6021800C
P 3600 3900
F 0 "U1" H 3600 4225 50  0000 C CNN
F 1 "74LS00" H 3600 4134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 3600 3900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 3600 3900 50  0001 C CNN
	3    3600 3900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS00 U1
U 4 1 6021B76F
P 3600 4450
F 0 "U1" H 3600 4775 50  0000 C CNN
F 1 "74LS00" H 3600 4684 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 3600 4450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 3600 4450 50  0001 C CNN
	4    3600 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 3250 3350 3350
Connection ~ 3350 3350
Wire Wire Line
	3350 3350 3350 3450
Text GLabel 2650 3250 0    50   Input ~ 0
CLOCK
Wire Wire Line
	2650 3250 2750 3250
Text GLabel 2650 3450 0    50   Input ~ 0
SIG_IN
Wire Wire Line
	2650 3450 2750 3450
Wire Wire Line
	5850 3350 3950 3350
Text GLabel 3200 3900 0    50   Input ~ 0
RESET
Wire Wire Line
	3300 3800 3300 3900
Wire Wire Line
	3200 3900 3300 3900
Connection ~ 3300 3900
Wire Wire Line
	3300 3900 3300 4000
Wire Wire Line
	5850 3450 3900 3450
Wire Wire Line
	3900 3450 3900 3900
$Comp
L Device:R_Network08 RN2
U 1 1 6023BBFA
P 5150 4000
F 0 "RN2" H 4670 3954 50  0000 R CNN
F 1 "100k" H 4670 4045 50  0000 R CNN
F 2 "Resistor_THT:R_Array_SIP9" V 5625 4000 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 5150 4000 50  0001 C CNN
	1    5150 4000
	-1   0    0    1   
$EndComp
$Comp
L Device:LED_Small_ALT D1
U 1 1 60240BA3
P 7150 3850
F 0 "D1" V 7196 3780 50  0000 R CNN
F 1 "LED" V 7105 3780 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 7150 3850 50  0001 C CNN
F 3 "~" V 7150 3850 50  0001 C CNN
	1    7150 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D2
U 1 1 60241FBA
P 7300 3850
F 0 "D2" V 7346 3780 50  0000 R CNN
F 1 "LED" V 7255 3780 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 7300 3850 50  0001 C CNN
F 3 "~" V 7300 3850 50  0001 C CNN
	1    7300 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D3
U 1 1 60242B1A
P 7450 3850
F 0 "D3" V 7496 3780 50  0000 R CNN
F 1 "LED" V 7405 3780 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 7450 3850 50  0001 C CNN
F 3 "~" V 7450 3850 50  0001 C CNN
	1    7450 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D4
U 1 1 60242E35
P 7600 3850
F 0 "D4" V 7646 3780 50  0000 R CNN
F 1 "LED" V 7555 3780 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 7600 3850 50  0001 C CNN
F 3 "~" V 7600 3850 50  0001 C CNN
	1    7600 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D5
U 1 1 6024507A
P 7750 3850
F 0 "D5" V 7796 3780 50  0000 R CNN
F 1 "LED" V 7705 3780 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 7750 3850 50  0001 C CNN
F 3 "~" V 7750 3850 50  0001 C CNN
	1    7750 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D6
U 1 1 60245080
P 7900 3850
F 0 "D6" V 7946 3780 50  0000 R CNN
F 1 "LED" V 7855 3780 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 7900 3850 50  0001 C CNN
F 3 "~" V 7900 3850 50  0001 C CNN
	1    7900 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D7
U 1 1 60245086
P 8050 3850
F 0 "D7" V 8096 3780 50  0000 R CNN
F 1 "LED" V 8005 3780 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 8050 3850 50  0001 C CNN
F 3 "~" V 8050 3850 50  0001 C CNN
	1    8050 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D8
U 1 1 6024508C
P 8200 3850
F 0 "D8" V 8246 3780 50  0000 R CNN
F 1 "LED" V 8155 3780 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 8200 3850 50  0001 C CNN
F 3 "~" V 8200 3850 50  0001 C CNN
	1    8200 3850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7150 3950 7150 4200
Wire Wire Line
	7150 4200 7350 4200
Wire Wire Line
	7300 3950 7300 4150
Wire Wire Line
	7300 4150 7450 4150
Wire Wire Line
	7450 4150 7450 4200
Wire Wire Line
	7450 3950 7450 4100
Wire Wire Line
	7450 4100 7550 4100
Wire Wire Line
	7550 4100 7550 4200
Wire Wire Line
	7600 3950 7600 4050
Wire Wire Line
	7600 4050 7650 4050
Wire Wire Line
	7650 4050 7650 4200
Wire Wire Line
	7750 3950 7750 4200
Wire Wire Line
	8200 3950 8200 4200
Wire Wire Line
	8200 4200 8050 4200
Wire Wire Line
	8050 3950 8050 4150
Wire Wire Line
	8050 4150 7950 4150
Wire Wire Line
	7950 4150 7950 4200
Wire Wire Line
	7900 3950 7900 4100
Wire Wire Line
	7900 4100 7850 4100
Wire Wire Line
	7850 4100 7850 4200
Text GLabel 6350 3850 3    50   Input ~ 0
GND
Wire Wire Line
	6350 3850 6350 3750
Text GLabel 8050 4700 3    50   Input ~ 0
GND
Wire Wire Line
	8050 4700 8050 4600
Text GLabel 5550 4300 3    50   Input ~ 0
GND
Wire Wire Line
	5550 4200 5550 4300
Wire Wire Line
	7150 3750 7150 2450
Wire Wire Line
	7300 3750 7300 2550
Wire Wire Line
	7450 2650 7450 3750
Wire Wire Line
	7600 3750 7600 2750
Wire Wire Line
	7750 2850 7750 3750
Wire Wire Line
	7900 3750 7900 2950
Wire Wire Line
	8050 3750 8050 3050
Wire Wire Line
	8200 3150 8200 3750
Text GLabel 4000 4450 2    50   Input ~ 0
~SIG_OUT
Wire Wire Line
	4000 4450 3900 4450
Text GLabel 3200 4450 0    50   Input ~ 0
SIG_OUT
Wire Wire Line
	3300 4550 3300 4450
Wire Wire Line
	3300 4450 3200 4450
Connection ~ 3300 4450
Wire Wire Line
	3300 4450 3300 4350
$Comp
L 74xx:74LS00 U1
U 5 1 60296BD0
P 1800 4000
F 0 "U1" H 2030 4046 50  0000 L CNN
F 1 "74LS00" H 2030 3955 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 1800 4000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 1800 4000 50  0001 C CNN
	5    1800 4000
	1    0    0    -1  
$EndComp
Text GLabel 6250 2150 0    50   Input ~ 0
VCC
Wire Wire Line
	6250 2150 6350 2150
Text GLabel 1800 3400 1    50   Input ~ 0
VCC
Wire Wire Line
	1800 3400 1800 3500
Text GLabel 1800 4600 3    50   Input ~ 0
GND
Wire Wire Line
	1800 4600 1800 4500
Wire Wire Line
	4850 3800 4850 2450
Wire Wire Line
	4950 3800 4950 2550
Wire Wire Line
	5050 2650 5050 3800
Wire Wire Line
	5150 3800 5150 2750
Wire Wire Line
	5250 2850 5250 3800
Wire Wire Line
	5350 3800 5350 2950
Wire Wire Line
	5450 3050 5450 3800
Wire Wire Line
	5550 3800 5550 3150
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 602DC352
P 7600 900
F 0 "#FLG0101" H 7600 975 50  0001 C CNN
F 1 "PWR_FLAG" H 7600 1073 50  0000 C CNN
F 2 "" H 7600 900 50  0001 C CNN
F 3 "~" H 7600 900 50  0001 C CNN
	1    7600 900 
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 602DCD37
P 7600 1400
F 0 "#FLG0102" H 7600 1475 50  0001 C CNN
F 1 "PWR_FLAG" H 7600 1573 50  0000 C CNN
F 2 "" H 7600 1400 50  0001 C CNN
F 3 "~" H 7600 1400 50  0001 C CNN
	1    7600 1400
	1    0    0    -1  
$EndComp
Text GLabel 7600 800  1    50   Input ~ 0
VCC
Wire Wire Line
	7600 800  7600 900 
Text GLabel 7600 1500 3    50   Input ~ 0
GND
Wire Wire Line
	7600 1500 7600 1400
$Comp
L Device:C_Small C1
U 1 1 602E5DE0
P 8100 1100
F 0 "C1" H 8192 1146 50  0000 L CNN
F 1 "100nF" H 8192 1055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 8100 1100 50  0001 C CNN
F 3 "~" H 8100 1100 50  0001 C CNN
	1    8100 1100
	1    0    0    -1  
$EndComp
Text GLabel 8100 900  1    50   Input ~ 0
VCC
Wire Wire Line
	8100 900  8100 1000
Text GLabel 8100 1300 3    50   Input ~ 0
GND
Wire Wire Line
	8100 1300 8100 1200
$Comp
L Device:C_Small C2
U 1 1 602F45CB
P 8550 1100
F 0 "C2" H 8642 1146 50  0000 L CNN
F 1 "100nF" H 8642 1055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 8550 1100 50  0001 C CNN
F 3 "~" H 8550 1100 50  0001 C CNN
	1    8550 1100
	1    0    0    -1  
$EndComp
Text GLabel 8550 900  1    50   Input ~ 0
VCC
Wire Wire Line
	8550 900  8550 1000
Text GLabel 8550 1300 3    50   Input ~ 0
GND
Wire Wire Line
	8550 1300 8550 1200
$Comp
L Device:C_Small C3
U 1 1 602F8E5E
P 9000 1100
F 0 "C3" H 9092 1146 50  0000 L CNN
F 1 "100nF" H 9092 1055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 9000 1100 50  0001 C CNN
F 3 "~" H 9000 1100 50  0001 C CNN
	1    9000 1100
	1    0    0    -1  
$EndComp
Text GLabel 9000 900  1    50   Input ~ 0
VCC
Wire Wire Line
	9000 900  9000 1000
Text GLabel 9000 1300 3    50   Input ~ 0
GND
Wire Wire Line
	9000 1300 9000 1200
$Comp
L Connector_Generic:Conn_01x14 J3
U 1 1 602FDCBD
P 6100 1250
F 0 "J3" H 6450 1850 50  0000 L CNN
F 1 "Conn_01x14" H 6200 1750 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x14_P2.54mm_Vertical" H 6100 1250 50  0001 C CNN
F 3 "~" H 6100 1250 50  0001 C CNN
	1    6100 1250
	1    0    0    -1  
$EndComp
Text GLabel 5800 650  0    50   Input ~ 0
GND
Text GLabel 5800 750  0    50   Input ~ 0
VCC
Text GLabel 5800 850  0    50   Input ~ 0
RESET
Text GLabel 5800 950  0    50   Input ~ 0
CLOCK
Wire Wire Line
	5900 650  5800 650 
Wire Wire Line
	5900 750  5800 750 
Wire Wire Line
	5900 850  5800 850 
Wire Wire Line
	5900 950  5800 950 
Text GLabel 5800 1850 0    50   Input ~ 0
GND
Text GLabel 5800 1950 0    50   Input ~ 0
VCC
Wire Wire Line
	5900 1850 5800 1850
Wire Wire Line
	5900 1950 5800 1950
Wire Wire Line
	5850 2550 4950 2550
Wire Wire Line
	5850 2750 5150 2750
Wire Wire Line
	5850 3050 5450 3050
Connection ~ 7150 2450
Wire Wire Line
	7150 2450 8800 2450
Connection ~ 7300 2550
Wire Wire Line
	7300 2550 8800 2550
Connection ~ 7450 2650
Wire Wire Line
	7450 2650 8800 2650
Connection ~ 7600 2750
Wire Wire Line
	7600 2750 8800 2750
Connection ~ 7750 2850
Wire Wire Line
	7750 2850 8800 2850
Connection ~ 7900 2950
Wire Wire Line
	7900 2950 8800 2950
Connection ~ 8050 3050
Wire Wire Line
	8050 3050 8800 3050
Connection ~ 8200 3150
Wire Wire Line
	8200 3150 8800 3150
Wire Wire Line
	6850 2450 7150 2450
Wire Wire Line
	6850 2550 7300 2550
Wire Wire Line
	6850 2650 7450 2650
Wire Wire Line
	6850 2750 7600 2750
Wire Wire Line
	6850 2850 7750 2850
Wire Wire Line
	6850 3050 8050 3050
Wire Wire Line
	6850 3150 8200 3150
Wire Wire Line
	6850 2950 7900 2950
Wire Wire Line
	4850 2450 5850 2450
Wire Wire Line
	5050 2650 5850 2650
Wire Wire Line
	5250 2850 5850 2850
Wire Wire Line
	5350 2950 5850 2950
Wire Wire Line
	5550 3150 5850 3150
Wire Wire Line
	4850 2450 4850 1050
Wire Wire Line
	4850 1050 5900 1050
Connection ~ 4850 2450
Wire Wire Line
	4950 2550 4950 1150
Wire Wire Line
	4950 1150 5900 1150
Connection ~ 4950 2550
Wire Wire Line
	5050 2650 5050 1250
Wire Wire Line
	5050 1250 5900 1250
Connection ~ 5050 2650
Wire Wire Line
	5900 1350 5150 1350
Wire Wire Line
	5150 1350 5150 2750
Connection ~ 5150 2750
Wire Wire Line
	5250 2850 5250 1450
Wire Wire Line
	5250 1450 5900 1450
Connection ~ 5250 2850
Wire Wire Line
	5900 1550 5350 1550
Wire Wire Line
	5350 1550 5350 2950
Connection ~ 5350 2950
Wire Wire Line
	5450 3050 5450 1650
Wire Wire Line
	5450 1650 5900 1650
Connection ~ 5450 3050
Wire Wire Line
	5900 1750 5550 1750
Wire Wire Line
	5550 1750 5550 3150
Connection ~ 5550 3150
$EndSCHEMATC
