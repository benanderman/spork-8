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
P 8250 4450
F 0 "RN1" H 7770 4404 50  0000 R CNN
F 1 "1k" H 7770 4495 50  0000 R CNN
F 2 "Resistor_THT:R_Array_SIP9" V 8725 4450 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 8250 4450 50  0001 C CNN
	1    8250 4450
	-1   0    0    1   
$EndComp
$Comp
L 74xx:74LS245 U3
U 1 1 601FFFAF
P 10100 2950
F 0 "U3" H 10350 3750 50  0000 C CNN
F 1 "74LS245" H 10350 3650 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm" H 10100 2950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS245" H 10100 2950 50  0001 C CNN
	1    10100 2950
	1    0    0    -1  
$EndComp
Text GLabel 10700 2450 2    50   Input ~ 0
BUS0
Text GLabel 10700 2750 2    50   Input ~ 0
BUS3
Text GLabel 10700 2550 2    50   Input ~ 0
BUS1
Text GLabel 10700 2650 2    50   Input ~ 0
BUS2
Text GLabel 10700 2850 2    50   Input ~ 0
BUS4
Text GLabel 10700 3150 2    50   Input ~ 0
BUS7
Text GLabel 10700 2950 2    50   Input ~ 0
BUS5
Text GLabel 10700 3050 2    50   Input ~ 0
BUS6
Wire Wire Line
	10600 2450 10700 2450
Wire Wire Line
	10600 2550 10700 2550
Wire Wire Line
	10600 2650 10700 2650
Wire Wire Line
	10600 2750 10700 2750
Wire Wire Line
	10600 2850 10700 2850
Wire Wire Line
	10600 2950 10700 2950
Wire Wire Line
	10600 3050 10700 3050
Wire Wire Line
	10600 3150 10700 3150
Text GLabel 10100 3850 3    50   Input ~ 0
GND
Text GLabel 9500 3350 0    50   Input ~ 0
VCC
Wire Wire Line
	9500 3350 9600 3350
Text GLabel 9500 3450 0    50   Input ~ 0
~SIG_OUT
Wire Wire Line
	9500 3450 9600 3450
Wire Wire Line
	10100 3850 10100 3750
Text GLabel 10100 2050 1    50   Input ~ 0
VCC
Wire Wire Line
	10100 2050 10100 2150
$Comp
L Device:R_Network08 RN2
U 1 1 6023BBFA
P 5150 6200
F 0 "RN2" H 4670 6154 50  0000 R CNN
F 1 "100k" H 4670 6245 50  0000 R CNN
F 2 "Resistor_THT:R_Array_SIP9" V 5625 6200 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 5150 6200 50  0001 C CNN
	1    5150 6200
	-1   0    0    1   
$EndComp
$Comp
L Device:LED_Small_ALT D1
U 1 1 60240BA3
P 7750 3900
F 0 "D1" V 7796 3830 50  0000 R CNN
F 1 "LED" V 7705 3830 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 7750 3900 50  0001 C CNN
F 3 "~" V 7750 3900 50  0001 C CNN
	1    7750 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D2
U 1 1 60241FBA
P 7900 3900
F 0 "D2" V 7946 3830 50  0000 R CNN
F 1 "LED" V 7855 3830 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 7900 3900 50  0001 C CNN
F 3 "~" V 7900 3900 50  0001 C CNN
	1    7900 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D3
U 1 1 60242B1A
P 8050 3900
F 0 "D3" V 8096 3830 50  0000 R CNN
F 1 "LED" V 8005 3830 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 8050 3900 50  0001 C CNN
F 3 "~" V 8050 3900 50  0001 C CNN
	1    8050 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D4
U 1 1 60242E35
P 8200 3900
F 0 "D4" V 8246 3830 50  0000 R CNN
F 1 "LED" V 8155 3830 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 8200 3900 50  0001 C CNN
F 3 "~" V 8200 3900 50  0001 C CNN
	1    8200 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D5
U 1 1 6024507A
P 8350 3900
F 0 "D5" V 8396 3830 50  0000 R CNN
F 1 "LED" V 8305 3830 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 8350 3900 50  0001 C CNN
F 3 "~" V 8350 3900 50  0001 C CNN
	1    8350 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D6
U 1 1 60245080
P 8500 3900
F 0 "D6" V 8546 3830 50  0000 R CNN
F 1 "LED" V 8455 3830 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 8500 3900 50  0001 C CNN
F 3 "~" V 8500 3900 50  0001 C CNN
	1    8500 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D7
U 1 1 60245086
P 8650 3900
F 0 "D7" V 8696 3830 50  0000 R CNN
F 1 "LED" V 8605 3830 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 8650 3900 50  0001 C CNN
F 3 "~" V 8650 3900 50  0001 C CNN
	1    8650 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D8
U 1 1 6024508C
P 8800 3900
F 0 "D8" V 8846 3830 50  0000 R CNN
F 1 "LED" V 8755 3830 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm_Clear" V 8800 3900 50  0001 C CNN
F 3 "~" V 8800 3900 50  0001 C CNN
	1    8800 3900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7750 4000 7750 4250
Wire Wire Line
	7750 4250 7950 4250
Wire Wire Line
	7900 4000 7900 4200
Wire Wire Line
	7900 4200 8050 4200
Wire Wire Line
	8050 4200 8050 4250
Wire Wire Line
	8050 4000 8050 4150
Wire Wire Line
	8050 4150 8150 4150
Wire Wire Line
	8150 4150 8150 4250
Wire Wire Line
	8200 4000 8200 4100
Wire Wire Line
	8200 4100 8250 4100
Wire Wire Line
	8250 4100 8250 4250
Wire Wire Line
	8350 4000 8350 4250
Wire Wire Line
	8800 4000 8800 4250
Wire Wire Line
	8800 4250 8650 4250
Wire Wire Line
	8650 4000 8650 4200
Wire Wire Line
	8650 4200 8550 4200
Wire Wire Line
	8550 4200 8550 4250
Wire Wire Line
	8500 4000 8500 4150
Wire Wire Line
	8500 4150 8450 4150
Wire Wire Line
	8450 4150 8450 4250
Text GLabel 8650 4750 3    50   Input ~ 0
GND
Wire Wire Line
	8650 4750 8650 4650
Text GLabel 5550 6500 3    50   Input ~ 0
GND
Wire Wire Line
	5550 6400 5550 6500
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
	5250 1450 5900 1450
Wire Wire Line
	5900 1550 5350 1550
Wire Wire Line
	5450 1650 5900 1650
Wire Wire Line
	5900 1750 5550 1750
$Comp
L 74xx:74LS173 U2
U 1 1 60F321DA
P 6600 3050
F 0 "U2" H 6850 3950 50  0000 C CNN
F 1 "74LS173" H 6850 3850 50  0000 C CNN
F 2 "" H 6600 3050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS173" H 6600 3050 50  0001 C CNN
	1    6600 3050
	1    0    0    -1  
$EndComp
Text GLabel 6500 2150 0    50   Input ~ 0
VCC
Wire Wire Line
	6500 2150 6600 2150
Text GLabel 6500 3950 0    50   Input ~ 0
GND
Wire Wire Line
	6500 3950 6600 3950
Text GLabel 6000 3650 0    50   Input ~ 0
RESET
Wire Wire Line
	6000 3650 6100 3650
Text GLabel 6000 3450 0    50   Input ~ 0
CLOCK
Wire Wire Line
	6000 3450 6100 3450
Text GLabel 6000 3300 0    50   Input ~ 0
~SIG_IN
Wire Wire Line
	6000 3300 6100 3300
Wire Wire Line
	6100 3300 6100 3250
Wire Wire Line
	6100 3300 6100 3350
Connection ~ 6100 3300
Text GLabel 6000 3000 0    50   Input ~ 0
GND
Wire Wire Line
	6000 3000 6100 3000
Wire Wire Line
	6100 3000 6100 2950
Wire Wire Line
	6100 3050 6100 3000
Connection ~ 6100 3000
$Comp
L 74xx:74LS173 U4
U 1 1 60F96036
P 6600 5000
F 0 "U4" H 6850 5900 50  0000 C CNN
F 1 "74LS173" H 6850 5800 50  0000 C CNN
F 2 "" H 6600 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS173" H 6600 5000 50  0001 C CNN
	1    6600 5000
	1    0    0    -1  
$EndComp
Text GLabel 6500 4100 0    50   Input ~ 0
VCC
Wire Wire Line
	6500 4100 6600 4100
Text GLabel 6500 5900 0    50   Input ~ 0
GND
Wire Wire Line
	6500 5900 6600 5900
Text GLabel 6000 5600 0    50   Input ~ 0
RESET
Wire Wire Line
	6000 5600 6100 5600
Text GLabel 6000 5400 0    50   Input ~ 0
CLOCK
Wire Wire Line
	6000 5400 6100 5400
Text GLabel 6000 5250 0    50   Input ~ 0
~SIG_IN
Wire Wire Line
	6000 5250 6100 5250
Wire Wire Line
	6100 5250 6100 5200
Wire Wire Line
	6100 5250 6100 5300
Connection ~ 6100 5250
Text GLabel 6000 4950 0    50   Input ~ 0
GND
Wire Wire Line
	6000 4950 6100 4950
Wire Wire Line
	6100 4950 6100 4900
Wire Wire Line
	6100 5000 6100 4950
Connection ~ 6100 4950
Wire Wire Line
	4850 2450 6100 2450
Wire Wire Line
	4950 2550 6100 2550
Wire Wire Line
	5050 2650 6100 2650
Wire Wire Line
	5150 2750 6100 2750
Wire Wire Line
	4850 2450 4850 6000
Wire Wire Line
	5550 1750 5550 4700
Wire Wire Line
	4950 2550 4950 6000
Wire Wire Line
	5050 2650 5050 6000
Wire Wire Line
	5150 2750 5150 6000
Wire Wire Line
	5250 1450 5250 4400
Wire Wire Line
	5350 1550 5350 4500
Wire Wire Line
	5450 1650 5450 4600
Connection ~ 5250 4400
Wire Wire Line
	5250 4400 5250 6000
Connection ~ 5350 4500
Wire Wire Line
	5350 4500 5350 6000
Connection ~ 5450 4600
Wire Wire Line
	5450 4600 5450 6000
Connection ~ 5550 4700
Wire Wire Line
	5550 4700 5550 6000
Wire Wire Line
	5250 4400 6100 4400
Wire Wire Line
	5350 4500 6100 4500
Wire Wire Line
	5450 4600 6100 4600
Wire Wire Line
	5550 4700 6100 4700
Wire Wire Line
	7100 2550 8650 2550
Wire Wire Line
	7100 2650 8500 2650
Wire Wire Line
	7100 2750 8350 2750
Wire Wire Line
	7100 4400 7100 2850
Wire Wire Line
	7100 2850 8200 2850
Wire Wire Line
	7100 4500 7200 4500
Wire Wire Line
	7200 4500 7200 2950
Wire Wire Line
	7200 2950 8050 2950
Wire Wire Line
	7100 4600 7300 4600
Wire Wire Line
	7300 4600 7300 3050
Wire Wire Line
	7300 3050 7900 3050
Wire Wire Line
	7100 4700 7400 4700
Wire Wire Line
	7400 4700 7400 3150
Wire Wire Line
	7400 3150 7750 3150
Wire Wire Line
	7100 2450 8800 2450
Wire Wire Line
	8800 3800 8800 2450
Connection ~ 8800 2450
Wire Wire Line
	8800 2450 9600 2450
Wire Wire Line
	8650 3800 8650 2550
Connection ~ 8650 2550
Wire Wire Line
	8650 2550 9600 2550
Wire Wire Line
	8500 3800 8500 2650
Connection ~ 8500 2650
Wire Wire Line
	8500 2650 9600 2650
Wire Wire Line
	8350 3800 8350 2750
Connection ~ 8350 2750
Wire Wire Line
	8350 2750 9600 2750
Wire Wire Line
	8200 3800 8200 2850
Connection ~ 8200 2850
Wire Wire Line
	8200 2850 9600 2850
Wire Wire Line
	8050 3800 8050 2950
Connection ~ 8050 2950
Wire Wire Line
	8050 2950 9600 2950
Wire Wire Line
	7900 3800 7900 3050
Connection ~ 7900 3050
Wire Wire Line
	7900 3050 9600 3050
Wire Wire Line
	7750 3800 7750 3150
Connection ~ 7750 3150
Wire Wire Line
	7750 3150 9600 3150
$Comp
L 74xx:74HC04 U1
U 7 1 61102B7B
P 1550 3900
F 0 "U1" H 1780 3946 50  0000 L CNN
F 1 "74HC04" H 1780 3855 50  0000 L CNN
F 2 "" H 1550 3900 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 1550 3900 50  0001 C CNN
	7    1550 3900
	1    0    0    -1  
$EndComp
Text GLabel 1550 3300 1    50   Input ~ 0
VCC
Wire Wire Line
	1550 3300 1550 3400
Text GLabel 1550 4500 3    50   Input ~ 0
GND
Wire Wire Line
	1550 4500 1550 4400
$Comp
L 74xx:74HC04 U1
U 1 1 61124608
P 2850 3250
F 0 "U1" H 2850 3567 50  0000 C CNN
F 1 "74HC04" H 2850 3476 50  0000 C CNN
F 2 "" H 2850 3250 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 2850 3250 50  0001 C CNN
	1    2850 3250
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U1
U 2 1 6112572C
P 2850 3800
F 0 "U1" H 2850 4117 50  0000 C CNN
F 1 "74HC04" H 2850 4026 50  0000 C CNN
F 2 "" H 2850 3800 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 2850 3800 50  0001 C CNN
	2    2850 3800
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U1
U 3 1 61127B79
P 2850 4350
F 0 "U1" H 2850 4667 50  0000 C CNN
F 1 "74HC04" H 2850 4576 50  0000 C CNN
F 2 "" H 2850 4350 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 2850 4350 50  0001 C CNN
	3    2850 4350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U1
U 4 1 6112957B
P 2850 4900
F 0 "U1" H 2850 5217 50  0000 C CNN
F 1 "74HC04" H 2850 5126 50  0000 C CNN
F 2 "" H 2850 4900 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 2850 4900 50  0001 C CNN
	4    2850 4900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U1
U 5 1 6112A564
P 2850 5450
F 0 "U1" H 2850 5767 50  0000 C CNN
F 1 "74HC04" H 2850 5676 50  0000 C CNN
F 2 "" H 2850 5450 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 2850 5450 50  0001 C CNN
	5    2850 5450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U1
U 6 1 6112B9AD
P 2850 6000
F 0 "U1" H 2850 6317 50  0000 C CNN
F 1 "74HC04" H 2850 6226 50  0000 C CNN
F 2 "" H 2850 6000 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 2850 6000 50  0001 C CNN
	6    2850 6000
	1    0    0    -1  
$EndComp
Text GLabel 2450 3800 0    50   Input ~ 0
SIG_IN
Wire Wire Line
	2450 3800 2550 3800
Text GLabel 2450 3250 0    50   Input ~ 0
SIG_OUT
Wire Wire Line
	2450 3250 2550 3250
Text GLabel 3250 3800 2    50   Input ~ 0
~SIG_IN
Wire Wire Line
	3250 3800 3150 3800
Text GLabel 3250 3250 2    50   Input ~ 0
~SIG_OUT
Wire Wire Line
	3250 3250 3150 3250
Wire Wire Line
	2550 4350 2450 4350
Wire Wire Line
	2450 4350 2450 4900
Text GLabel 2450 6250 3    50   Input ~ 0
GND
Wire Wire Line
	2550 4900 2450 4900
Connection ~ 2450 4900
Wire Wire Line
	2450 4900 2450 5450
Wire Wire Line
	2550 5450 2450 5450
Connection ~ 2450 5450
Wire Wire Line
	2450 5450 2450 6000
Wire Wire Line
	2550 6000 2450 6000
Connection ~ 2450 6000
Wire Wire Line
	2450 6000 2450 6250
NoConn ~ 3150 4350
NoConn ~ 3150 4900
NoConn ~ 3150 5450
NoConn ~ 3150 6000
$EndSCHEMATC
