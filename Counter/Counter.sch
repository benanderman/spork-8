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
U 1 1 5F814225
P 1300 1550
F 0 "J1" H 1150 2500 50  0000 L CNN
F 1 "Conn_01x16" H 900 2400 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Horizontal" H 1300 1550 50  0001 C CNN
F 3 "~" H 1300 1550 50  0001 C CNN
	1    1300 1550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x16 J2
U 1 1 5F815EE2
P 1550 1650
F 0 "J2" H 1350 600 50  0000 C CNN
F 1 "Conn_01x16" H 1350 700 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Horizontal" H 1550 1650 50  0001 C CNN
F 3 "~" H 1550 1650 50  0001 C CNN
	1    1550 1650
	-1   0    0    1   
$EndComp
Text GLabel 1000 850  0    50   Input ~ 0
GND
Text GLabel 1000 950  0    50   Input ~ 0
VCC
Text GLabel 1000 1150 0    50   Input ~ 0
CLOCK
Text GLabel 1000 1050 0    50   Input ~ 0
RESET
Text GLabel 1000 1250 0    50   Input ~ 0
SIG_OUT
Text GLabel 1000 1350 0    50   Input ~ 0
SIG_IN
Text GLabel 1000 1450 0    50   Input ~ 0
SIG0
Text GLabel 1000 1550 0    50   Input ~ 0
SIG1
Text GLabel 1000 1650 0    50   Input ~ 0
BUS0
Text GLabel 1000 1750 0    50   Input ~ 0
BUS1
Text GLabel 1000 1850 0    50   Input ~ 0
BUS2
Text GLabel 1000 1950 0    50   Input ~ 0
BUS3
Text GLabel 1000 2050 0    50   Input ~ 0
BUS4
Text GLabel 1000 2150 0    50   Input ~ 0
BUS5
Text GLabel 1000 2250 0    50   Input ~ 0
BUS6
Text GLabel 1000 2350 0    50   Input ~ 0
BUS7
Text GLabel 1850 850  2    50   Input ~ 0
GND
Text GLabel 1850 950  2    50   Input ~ 0
VCC
Text GLabel 1850 1150 2    50   Input ~ 0
CLOCK
Text GLabel 1850 1050 2    50   Input ~ 0
RESET
Text GLabel 1850 1250 2    50   Input ~ 0
SIG_OUT
Text GLabel 1850 1350 2    50   Input ~ 0
SIG_IN
Text GLabel 1850 1450 2    50   Input ~ 0
SIG0
Text GLabel 1850 1550 2    50   Input ~ 0
SIG1
Text GLabel 1850 1650 2    50   Input ~ 0
BUS0
Text GLabel 1850 1750 2    50   Input ~ 0
BUS1
Text GLabel 1850 1850 2    50   Input ~ 0
BUS2
Text GLabel 1850 1950 2    50   Input ~ 0
BUS3
Text GLabel 1850 2050 2    50   Input ~ 0
BUS4
Text GLabel 1850 2150 2    50   Input ~ 0
BUS5
Text GLabel 1850 2250 2    50   Input ~ 0
BUS6
Text GLabel 1850 2350 2    50   Input ~ 0
BUS7
Wire Wire Line
	1750 850  1850 850 
Wire Wire Line
	1750 950  1850 950 
Wire Wire Line
	1750 1050 1850 1050
Wire Wire Line
	1750 1150 1850 1150
Wire Wire Line
	1750 1250 1850 1250
Wire Wire Line
	1750 1350 1850 1350
Wire Wire Line
	1750 1450 1850 1450
Wire Wire Line
	1750 1550 1850 1550
Wire Wire Line
	1750 1650 1850 1650
Wire Wire Line
	1750 1750 1850 1750
Wire Wire Line
	1750 1850 1850 1850
Wire Wire Line
	1750 1950 1850 1950
Wire Wire Line
	1750 2050 1850 2050
Wire Wire Line
	1750 2150 1850 2150
Wire Wire Line
	1750 2250 1850 2250
Wire Wire Line
	1750 2350 1850 2350
Wire Wire Line
	1000 850  1100 850 
Wire Wire Line
	1000 950  1100 950 
Wire Wire Line
	1000 1050 1100 1050
Wire Wire Line
	1000 1150 1100 1150
Wire Wire Line
	1000 1250 1100 1250
Wire Wire Line
	1000 1350 1100 1350
Wire Wire Line
	1000 1450 1100 1450
Wire Wire Line
	1000 1550 1100 1550
Wire Wire Line
	1000 1650 1100 1650
Wire Wire Line
	1000 1750 1100 1750
Wire Wire Line
	1000 1850 1100 1850
Wire Wire Line
	1000 1950 1100 1950
Wire Wire Line
	1000 2050 1100 2050
Wire Wire Line
	1000 2150 1100 2150
Wire Wire Line
	1000 2250 1100 2250
Wire Wire Line
	1000 2350 1100 2350
$Comp
L 74xx:74LS161 U4
U 1 1 5F824DC5
P 5550 1400
F 0 "U4" H 5800 2200 50  0000 C CNN
F 1 "74LS161" H 5800 2100 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5550 1400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 5550 1400 50  0001 C CNN
	1    5550 1400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x16 J4
U 1 1 5F829F36
P 3400 1050
F 0 "J4" H 3200 0   50  0000 C CNN
F 1 "Conn_01x16" H 3200 100 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x16_P2.54mm_Horizontal" H 3400 1050 50  0001 C CNN
F 3 "~" H 3400 1050 50  0001 C CNN
	1    3400 1050
	0    1    1    0   
$EndComp
Text GLabel 2600 750  1    50   Input ~ 0
A0
Text GLabel 2700 750  1    50   Input ~ 0
A1
Wire Wire Line
	2600 750  2600 850 
Wire Wire Line
	2700 750  2700 850 
Text GLabel 2800 750  1    50   Input ~ 0
A2
Text GLabel 2900 750  1    50   Input ~ 0
A3
Text GLabel 3000 750  1    50   Input ~ 0
A4
Text GLabel 3100 750  1    50   Input ~ 0
A5
Text GLabel 3200 750  1    50   Input ~ 0
A6
Text GLabel 3300 750  1    50   Input ~ 0
A7
Text GLabel 3400 750  1    50   Input ~ 0
A8
Text GLabel 3500 750  1    50   Input ~ 0
A9
Text GLabel 3600 750  1    50   Input ~ 0
A10
Text GLabel 3700 750  1    50   Input ~ 0
A11
Text GLabel 3800 750  1    50   Input ~ 0
A12
Text GLabel 3900 750  1    50   Input ~ 0
A13
Text GLabel 4000 750  1    50   Input ~ 0
A14
Text GLabel 4100 750  1    50   Input ~ 0
A15
Wire Wire Line
	2800 850  2800 750 
Wire Wire Line
	2900 850  2900 750 
Wire Wire Line
	3000 850  3000 750 
Wire Wire Line
	3100 850  3100 750 
Wire Wire Line
	3200 850  3200 750 
Wire Wire Line
	3300 850  3300 750 
Wire Wire Line
	3400 850  3400 750 
Wire Wire Line
	3500 850  3500 750 
Wire Wire Line
	3600 850  3600 750 
Wire Wire Line
	3700 850  3700 750 
Wire Wire Line
	3800 850  3800 750 
Wire Wire Line
	3900 850  3900 750 
Wire Wire Line
	4000 850  4000 750 
Wire Wire Line
	4100 850  4100 750 
$Comp
L 74xx:74LS161 U5
U 1 1 5F8388F3
P 5550 3200
F 0 "U5" H 5800 4000 50  0000 C CNN
F 1 "74LS161" H 5800 3900 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5550 3200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 5550 3200 50  0001 C CNN
	1    5550 3200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS161 U6
U 1 1 5F8395FD
P 5550 5000
F 0 "U6" H 5800 5800 50  0000 C CNN
F 1 "74LS161" H 5800 5700 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5550 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 5550 5000 50  0001 C CNN
	1    5550 5000
	1    0    0    -1  
$EndComp
Text GLabel 5450 2200 0    50   Input ~ 0
GND
Wire Wire Line
	5450 2200 5550 2200
Text GLabel 5450 4000 0    50   Input ~ 0
GND
Wire Wire Line
	5450 4000 5550 4000
Text GLabel 5450 5800 0    50   Input ~ 0
GND
Wire Wire Line
	5450 5800 5550 5800
Text GLabel 5450 600  0    50   Input ~ 0
VCC
Wire Wire Line
	5450 600  5550 600 
Text GLabel 5450 2400 0    50   Input ~ 0
VCC
Wire Wire Line
	5450 2400 5550 2400
Text GLabel 5450 4200 0    50   Input ~ 0
VCC
Wire Wire Line
	5450 4200 5550 4200
$Comp
L 74xx:74LS161 U7
U 1 1 5F84B796
P 5550 6800
F 0 "U7" H 5800 7600 50  0000 C CNN
F 1 "74LS161" H 5800 7500 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5550 6800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS161" H 5550 6800 50  0001 C CNN
	1    5550 6800
	1    0    0    -1  
$EndComp
Text GLabel 5450 7600 0    50   Input ~ 0
GND
Wire Wire Line
	5450 7600 5550 7600
Text GLabel 5450 6000 0    50   Input ~ 0
VCC
Wire Wire Line
	5450 6000 5550 6000
$Comp
L 74xx:74LS245 U10
U 1 1 5F8532C2
P 10300 3350
F 0 "U10" H 10550 4150 50  0000 C CNN
F 1 "74LS245" H 10550 4050 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm" H 10300 3350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS245" H 10300 3350 50  0001 C CNN
	1    10300 3350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS157 U9
U 1 1 5F854BCF
P 8300 5150
F 0 "U9" H 8550 6050 50  0000 C CNN
F 1 "74LS157" H 8550 5950 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 8300 5150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS157" H 8300 5150 50  0001 C CNN
	1    8300 5150
	1    0    0    -1  
$EndComp
Text GLabel 8200 4250 0    50   Input ~ 0
VCC
Wire Wire Line
	8200 4250 8300 4250
Text GLabel 8200 6150 0    50   Input ~ 0
GND
Wire Wire Line
	8200 6150 8300 6150
Text GLabel 7700 5850 0    50   Input ~ 0
GND
Wire Wire Line
	7700 5850 7800 5850
Text GLabel 7700 5750 0    50   Input ~ 0
SIG1
Wire Wire Line
	7700 5750 7800 5750
Wire Wire Line
	7400 5550 7800 5550
Wire Wire Line
	7350 5250 7800 5250
Wire Wire Line
	7300 4950 7800 4950
Wire Wire Line
	7250 4650 7800 4650
Wire Wire Line
	6050 3000 7100 3000
Wire Wire Line
	7100 5450 7800 5450
Wire Wire Line
	7800 5150 7150 5150
Wire Wire Line
	7150 2900 6050 2900
Wire Wire Line
	7800 4850 7200 4850
Wire Wire Line
	7200 2800 6050 2800
Wire Wire Line
	6050 2700 7250 2700
Wire Wire Line
	7250 4550 7800 4550
$Comp
L 74xx:74LS157 U8
U 1 1 5F8BA91D
P 8300 1650
F 0 "U8" H 8550 2550 50  0000 C CNN
F 1 "74LS157" H 8550 2450 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 8300 1650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS157" H 8300 1650 50  0001 C CNN
	1    8300 1650
	1    0    0    -1  
$EndComp
Text GLabel 8200 750  0    50   Input ~ 0
VCC
Wire Wire Line
	8200 750  8300 750 
Text GLabel 8200 2650 0    50   Input ~ 0
GND
Wire Wire Line
	8200 2650 8300 2650
Text GLabel 7700 2350 0    50   Input ~ 0
GND
Wire Wire Line
	7700 2350 7800 2350
Text GLabel 7700 2250 0    50   Input ~ 0
SIG1
Wire Wire Line
	7700 2250 7800 2250
Wire Wire Line
	6050 4800 6950 4800
Wire Wire Line
	6950 2050 7800 2050
Wire Wire Line
	6050 4700 6900 4700
Wire Wire Line
	6900 1750 7800 1750
Wire Wire Line
	6050 4600 6850 4600
Wire Wire Line
	6850 1450 7800 1450
Wire Wire Line
	6050 4500 6800 4500
Wire Wire Line
	6800 1150 7800 1150
Wire Wire Line
	6750 1350 7800 1350
Wire Wire Line
	6700 1650 7800 1650
Wire Wire Line
	6650 1950 7800 1950
Wire Wire Line
	7250 6100 7250 4650
Wire Wire Line
	6050 6400 6500 6400
Wire Wire Line
	6500 6400 6500 6150
Wire Wire Line
	6500 6150 7300 6150
Wire Wire Line
	7300 6150 7300 4950
Wire Wire Line
	6050 6500 6550 6500
Wire Wire Line
	6550 6500 6550 6200
Wire Wire Line
	6550 6200 7350 6200
Wire Wire Line
	7350 6200 7350 5250
Wire Wire Line
	6050 6600 6600 6600
Wire Wire Line
	6600 6600 6600 6250
Wire Wire Line
	6600 6250 7400 6250
Wire Wire Line
	7400 6250 7400 5550
Wire Wire Line
	6650 1200 6050 1200
Wire Wire Line
	6650 1200 6650 1950
Wire Wire Line
	6050 1100 6700 1100
Wire Wire Line
	6700 1100 6700 1650
Wire Wire Line
	6750 1000 6050 1000
Wire Wire Line
	6750 1000 6750 1350
Wire Wire Line
	6050 900  6800 900 
Wire Wire Line
	6800 900  6800 1050
Wire Wire Line
	6800 1050 7800 1050
Wire Wire Line
	6050 2300 4450 2300
Wire Wire Line
	6050 1400 6050 2300
Wire Wire Line
	7250 2700 7250 4550
Wire Wire Line
	7200 2800 7200 4850
Wire Wire Line
	7150 2900 7150 5150
Wire Wire Line
	7100 3000 7100 5450
Text Label 6150 900  0    50   ~ 0
A0
Text Label 6150 1000 0    50   ~ 0
A1
Text Label 6150 1100 0    50   ~ 0
A2
Text Label 6150 1200 0    50   ~ 0
A3
Text Label 6150 2700 0    50   ~ 0
A4
Text Label 6150 2800 0    50   ~ 0
A5
Text Label 6150 2900 0    50   ~ 0
A6
Text Label 6150 3000 0    50   ~ 0
A7
Wire Wire Line
	6800 4500 6800 1150
Wire Wire Line
	6850 4600 6850 1450
Wire Wire Line
	6900 4700 6900 1750
Wire Wire Line
	6950 4800 6950 2050
Wire Wire Line
	6050 3200 6050 4100
Wire Wire Line
	6050 5000 6050 5900
Wire Wire Line
	6050 5900 4450 5900
Text Label 6150 4500 0    50   ~ 0
A8
Text Label 6150 4600 0    50   ~ 0
A9
Text Label 6150 4700 0    50   ~ 0
A10
Text Label 6150 4800 0    50   ~ 0
A11
Wire Wire Line
	6050 6300 6450 6300
Wire Wire Line
	6450 6300 6450 6100
Wire Wire Line
	6450 6100 7250 6100
Text Label 6150 6300 0    50   ~ 0
A12
Text Label 6150 6400 0    50   ~ 0
A13
Text Label 6150 6500 0    50   ~ 0
A14
Text Label 6150 6600 0    50   ~ 0
A15
Text GLabel 4950 900  0    50   Input ~ 0
BUS0
Text GLabel 4950 1000 0    50   Input ~ 0
BUS1
Text GLabel 4950 1100 0    50   Input ~ 0
BUS2
Text GLabel 4950 1200 0    50   Input ~ 0
BUS3
Wire Wire Line
	4950 900  5050 900 
Wire Wire Line
	4950 1000 5050 1000
Wire Wire Line
	4950 1100 5050 1100
Wire Wire Line
	4950 1200 5050 1200
Text GLabel 4950 4500 0    50   Input ~ 0
BUS0
Text GLabel 4950 4600 0    50   Input ~ 0
BUS1
Text GLabel 4950 4700 0    50   Input ~ 0
BUS2
Text GLabel 4950 4800 0    50   Input ~ 0
BUS3
Wire Wire Line
	4950 4500 5050 4500
Wire Wire Line
	4950 4600 5050 4600
Wire Wire Line
	4950 4700 5050 4700
Wire Wire Line
	4950 4800 5050 4800
Text GLabel 4950 2700 0    50   Input ~ 0
BUS4
Text GLabel 4950 2800 0    50   Input ~ 0
BUS5
Text GLabel 4950 2900 0    50   Input ~ 0
BUS6
Text GLabel 4950 3000 0    50   Input ~ 0
BUS7
Wire Wire Line
	4950 2700 5050 2700
Wire Wire Line
	4950 2800 5050 2800
Wire Wire Line
	4950 2900 5050 2900
Wire Wire Line
	4950 3000 5050 3000
Text GLabel 4950 6300 0    50   Input ~ 0
BUS4
Text GLabel 4950 6400 0    50   Input ~ 0
BUS5
Text GLabel 4950 6500 0    50   Input ~ 0
BUS6
Text GLabel 4950 6600 0    50   Input ~ 0
BUS7
Wire Wire Line
	4950 6300 5050 6300
Wire Wire Line
	4950 6400 5050 6400
Wire Wire Line
	4950 6500 5050 6500
Wire Wire Line
	4950 6600 5050 6600
NoConn ~ 6050 6800
Text GLabel 9700 3750 0    50   Input ~ 0
VCC
Wire Wire Line
	9700 3750 9800 3750
Text GLabel 8300 3850 0    50   Input ~ 0
SIG_OUT
Text GLabel 10900 2850 2    50   Input ~ 0
BUS0
Text GLabel 10900 2950 2    50   Input ~ 0
BUS1
Text GLabel 10900 3050 2    50   Input ~ 0
BUS2
Text GLabel 10900 3150 2    50   Input ~ 0
BUS3
Text GLabel 10900 3250 2    50   Input ~ 0
BUS4
Text GLabel 10900 3350 2    50   Input ~ 0
BUS5
Text GLabel 10900 3450 2    50   Input ~ 0
BUS6
Text GLabel 10900 3550 2    50   Input ~ 0
BUS7
Wire Wire Line
	10800 2850 10900 2850
Wire Wire Line
	10800 2950 10900 2950
Wire Wire Line
	10800 3050 10900 3050
Wire Wire Line
	10800 3150 10900 3150
Wire Wire Line
	10800 3250 10900 3250
Wire Wire Line
	10800 3350 10900 3350
Wire Wire Line
	10800 3450 10900 3450
Wire Wire Line
	10800 3550 10900 3550
Text GLabel 10200 2550 0    50   Input ~ 0
VCC
Wire Wire Line
	10200 2550 10300 2550
Text GLabel 10200 4150 0    50   Input ~ 0
GND
Wire Wire Line
	10200 4150 10300 4150
Wire Wire Line
	8800 5450 9300 5450
Wire Wire Line
	9300 5450 9300 3550
Wire Wire Line
	9300 3550 9800 3550
Wire Wire Line
	8800 5150 9250 5150
Wire Wire Line
	9250 5150 9250 3450
Wire Wire Line
	9250 3450 9800 3450
Wire Wire Line
	8800 4850 9200 4850
Wire Wire Line
	9200 4850 9200 3350
Wire Wire Line
	9200 3350 9800 3350
Wire Wire Line
	8800 4550 9150 4550
Wire Wire Line
	9150 4550 9150 3250
Wire Wire Line
	9150 3250 9800 3250
Wire Wire Line
	8800 1950 9150 1950
Wire Wire Line
	9150 1950 9150 3150
Wire Wire Line
	9150 3150 9800 3150
Wire Wire Line
	9800 3050 9200 3050
Wire Wire Line
	9200 3050 9200 1650
Wire Wire Line
	9200 1650 8800 1650
Wire Wire Line
	8800 1350 9250 1350
Wire Wire Line
	9250 1350 9250 2950
Wire Wire Line
	9250 2950 9800 2950
Wire Wire Line
	9800 2850 9300 2850
Wire Wire Line
	9300 2850 9300 1050
Wire Wire Line
	9300 1050 8800 1050
Text GLabel 4950 1900 0    50   Input ~ 0
~RESET
Wire Wire Line
	4950 1900 5050 1900
Text GLabel 4950 3700 0    50   Input ~ 0
~RESET
Wire Wire Line
	4950 3700 5050 3700
Text GLabel 4950 5500 0    50   Input ~ 0
~RESET
Wire Wire Line
	4950 5500 5050 5500
Text GLabel 4950 7300 0    50   Input ~ 0
~RESET
Wire Wire Line
	4950 7300 5050 7300
Wire Wire Line
	6050 4100 4450 4100
Text GLabel 4950 1550 0    50   Input ~ 0
SIG0
Wire Wire Line
	4950 1550 5050 1550
Wire Wire Line
	5050 1550 5050 1500
Wire Wire Line
	5050 1550 5050 1600
Connection ~ 5050 1550
Text GLabel 4950 1700 0    50   Input ~ 0
CLOCK
Wire Wire Line
	4950 1700 5050 1700
Text GLabel 4950 3500 0    50   Input ~ 0
CLOCK
Wire Wire Line
	4950 3500 5050 3500
Text GLabel 4950 5300 0    50   Input ~ 0
CLOCK
Wire Wire Line
	4950 5300 5050 5300
Text GLabel 4950 7100 0    50   Input ~ 0
CLOCK
Wire Wire Line
	4950 7100 5050 7100
Text GLabel 2150 4200 0    50   Input ~ 0
SIG_IN
Text GLabel 2150 4800 0    50   Input ~ 0
SIG_IN
Wire Wire Line
	2150 4800 2250 4800
Wire Wire Line
	2150 4200 2250 4200
Wire Wire Line
	2150 4400 2250 4400
Wire Wire Line
	2150 5000 2250 5000
Text GLabel 2150 3050 0    50   Input ~ 0
SIG1
Wire Wire Line
	2150 3050 2250 3050
Text GLabel 2950 3050 2    50   Input ~ 0
~SIG1
Wire Wire Line
	2950 3050 2850 3050
Text GLabel 2950 4300 2    50   Input ~ 0
~SIG_IN_0
Wire Wire Line
	2950 4300 2850 4300
Text GLabel 2950 4900 2    50   Input ~ 0
~SIG_IN_1
Wire Wire Line
	2950 4900 2850 4900
Text GLabel 4950 1400 0    50   Input ~ 0
~SIG_IN_0
Wire Wire Line
	4950 1400 5050 1400
Text GLabel 4950 3200 0    50   Input ~ 0
~SIG_IN_0
Wire Wire Line
	4950 3200 5050 3200
Text GLabel 4950 5000 0    50   Input ~ 0
~SIG_IN_1
Wire Wire Line
	4950 5000 5050 5000
Text GLabel 4950 6800 0    50   Input ~ 0
~SIG_IN_1
Wire Wire Line
	4950 6800 5050 6800
Text GLabel 2150 3600 0    50   Input ~ 0
RESET
Wire Wire Line
	2150 3600 2250 3600
Text GLabel 2950 3600 2    50   Input ~ 0
~RESET
Wire Wire Line
	2950 3600 2850 3600
Text GLabel 1100 4050 0    50   Input ~ 0
VCC
Wire Wire Line
	1100 4050 1200 4050
Text GLabel 1100 5050 0    50   Input ~ 0
GND
Wire Wire Line
	1100 5050 1200 5050
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5FC7093E
P 3800 3450
F 0 "#FLG0101" H 3800 3525 50  0001 C CNN
F 1 "PWR_FLAG" H 3800 3623 50  0000 C CNN
F 2 "" H 3800 3450 50  0001 C CNN
F 3 "~" H 3800 3450 50  0001 C CNN
	1    3800 3450
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5FC71B73
P 3800 3000
F 0 "#FLG0102" H 3800 3075 50  0001 C CNN
F 1 "PWR_FLAG" H 3800 3173 50  0000 C CNN
F 2 "" H 3800 3000 50  0001 C CNN
F 3 "~" H 3800 3000 50  0001 C CNN
	1    3800 3000
	-1   0    0    1   
$EndComp
Text GLabel 3800 3550 3    50   Input ~ 0
GND
Wire Wire Line
	3800 3550 3800 3450
Text GLabel 3800 2900 1    50   Input ~ 0
VCC
Wire Wire Line
	3800 2900 3800 3000
$Comp
L Device:LED_Small_ALT D1
U 1 1 5FCA57C8
P 1050 6650
F 0 "D1" V 1096 6580 50  0000 R CNN
F 1 "LED" V 1005 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 1050 6650 50  0001 C CNN
F 3 "~" V 1050 6650 50  0001 C CNN
	1    1050 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D2
U 1 1 5FCA6D8D
P 1200 6650
F 0 "D2" V 1246 6580 50  0000 R CNN
F 1 "LED" V 1155 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 1200 6650 50  0001 C CNN
F 3 "~" V 1200 6650 50  0001 C CNN
	1    1200 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D3
U 1 1 5FCA7173
P 1350 6650
F 0 "D3" V 1396 6580 50  0000 R CNN
F 1 "LED" V 1305 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 1350 6650 50  0001 C CNN
F 3 "~" V 1350 6650 50  0001 C CNN
	1    1350 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D4
U 1 1 5FCA7559
P 1500 6650
F 0 "D4" V 1546 6580 50  0000 R CNN
F 1 "LED" V 1455 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 1500 6650 50  0001 C CNN
F 3 "~" V 1500 6650 50  0001 C CNN
	1    1500 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D5
U 1 1 5FCA9BF0
P 1650 6650
F 0 "D5" V 1696 6580 50  0000 R CNN
F 1 "LED" V 1605 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 1650 6650 50  0001 C CNN
F 3 "~" V 1650 6650 50  0001 C CNN
	1    1650 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D6
U 1 1 5FCA9BF6
P 1800 6650
F 0 "D6" V 1846 6580 50  0000 R CNN
F 1 "LED" V 1755 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 1800 6650 50  0001 C CNN
F 3 "~" V 1800 6650 50  0001 C CNN
	1    1800 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D7
U 1 1 5FCA9BFC
P 1950 6650
F 0 "D7" V 1996 6580 50  0000 R CNN
F 1 "LED" V 1905 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 1950 6650 50  0001 C CNN
F 3 "~" V 1950 6650 50  0001 C CNN
	1    1950 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D8
U 1 1 5FCA9C02
P 2100 6650
F 0 "D8" V 2146 6580 50  0000 R CNN
F 1 "LED" V 2055 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 2100 6650 50  0001 C CNN
F 3 "~" V 2100 6650 50  0001 C CNN
	1    2100 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D9
U 1 1 5FCBF633
P 2250 6650
F 0 "D9" V 2296 6580 50  0000 R CNN
F 1 "LED" V 2205 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 2250 6650 50  0001 C CNN
F 3 "~" V 2250 6650 50  0001 C CNN
	1    2250 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D10
U 1 1 5FCBF639
P 2400 6650
F 0 "D10" V 2446 6580 50  0000 R CNN
F 1 "LED" V 2355 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 2400 6650 50  0001 C CNN
F 3 "~" V 2400 6650 50  0001 C CNN
	1    2400 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D11
U 1 1 5FCBF63F
P 2550 6650
F 0 "D11" V 2596 6580 50  0000 R CNN
F 1 "LED" V 2505 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 2550 6650 50  0001 C CNN
F 3 "~" V 2550 6650 50  0001 C CNN
	1    2550 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D12
U 1 1 5FCBF645
P 2700 6650
F 0 "D12" V 2746 6580 50  0000 R CNN
F 1 "LED" V 2655 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 2700 6650 50  0001 C CNN
F 3 "~" V 2700 6650 50  0001 C CNN
	1    2700 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D13
U 1 1 5FCBF64B
P 2850 6650
F 0 "D13" V 2896 6580 50  0000 R CNN
F 1 "LED" V 2805 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 2850 6650 50  0001 C CNN
F 3 "~" V 2850 6650 50  0001 C CNN
	1    2850 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D14
U 1 1 5FCBF651
P 3000 6650
F 0 "D14" V 3046 6580 50  0000 R CNN
F 1 "LED" V 2955 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 3000 6650 50  0001 C CNN
F 3 "~" V 3000 6650 50  0001 C CNN
	1    3000 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D15
U 1 1 5FCBF657
P 3150 6650
F 0 "D15" V 3196 6580 50  0000 R CNN
F 1 "LED" V 3105 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 3150 6650 50  0001 C CNN
F 3 "~" V 3150 6650 50  0001 C CNN
	1    3150 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Small_ALT D16
U 1 1 5FCBF65D
P 3300 6650
F 0 "D16" V 3346 6580 50  0000 R CNN
F 1 "LED" V 3255 6580 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" V 3300 6650 50  0001 C CNN
F 3 "~" V 3300 6650 50  0001 C CNN
	1    3300 6650
	0    -1   -1   0   
$EndComp
Text GLabel 3300 6450 1    50   Input ~ 0
A0
Text GLabel 3150 6450 1    50   Input ~ 0
A1
Text GLabel 3000 6450 1    50   Input ~ 0
A2
Text GLabel 2850 6450 1    50   Input ~ 0
A3
Text GLabel 2700 6450 1    50   Input ~ 0
A4
Text GLabel 2550 6450 1    50   Input ~ 0
A5
Text GLabel 2400 6450 1    50   Input ~ 0
A6
Text GLabel 2250 6450 1    50   Input ~ 0
A7
Text GLabel 2100 6450 1    50   Input ~ 0
A8
Text GLabel 1950 6450 1    50   Input ~ 0
A9
Text GLabel 1800 6450 1    50   Input ~ 0
A10
Text GLabel 1650 6450 1    50   Input ~ 0
A11
Text GLabel 1500 6450 1    50   Input ~ 0
A12
Text GLabel 1350 6450 1    50   Input ~ 0
A13
Text GLabel 1200 6450 1    50   Input ~ 0
A14
Text GLabel 1050 6450 1    50   Input ~ 0
A15
Wire Wire Line
	1050 6450 1050 6550
Wire Wire Line
	1200 6450 1200 6550
Wire Wire Line
	1350 6450 1350 6550
Wire Wire Line
	1500 6450 1500 6550
Wire Wire Line
	1650 6450 1650 6550
Wire Wire Line
	1800 6450 1800 6550
Wire Wire Line
	1950 6450 1950 6550
Wire Wire Line
	2100 6450 2100 6550
Wire Wire Line
	2250 6450 2250 6550
Wire Wire Line
	2400 6450 2400 6550
Wire Wire Line
	2550 6450 2550 6550
Wire Wire Line
	2700 6450 2700 6550
Wire Wire Line
	2850 6450 2850 6550
Wire Wire Line
	3000 6450 3000 6550
Wire Wire Line
	3150 6450 3150 6550
Wire Wire Line
	3300 6450 3300 6550
$Comp
L Device:R_Network08 RN1
U 1 1 5FD81B08
P 1500 7250
F 0 "RN1" H 1020 7204 50  0000 R CNN
F 1 "1k" H 1020 7295 50  0000 R CNN
F 2 "Resistor_THT:R_Array_SIP9" V 1975 7250 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 1500 7250 50  0001 C CNN
	1    1500 7250
	-1   0    0    1   
$EndComp
Wire Wire Line
	1050 6750 1050 7050
Wire Wire Line
	1050 7050 1200 7050
Wire Wire Line
	1200 6750 1200 7000
Wire Wire Line
	1200 7000 1300 7000
Wire Wire Line
	1300 7000 1300 7050
Wire Wire Line
	1350 6750 1350 6950
Wire Wire Line
	1350 6950 1400 6950
Wire Wire Line
	1400 6950 1400 7050
Wire Wire Line
	1500 6750 1500 7050
Wire Wire Line
	1650 6750 1650 6900
Wire Wire Line
	1650 6900 1600 6900
Wire Wire Line
	1600 6900 1600 7050
Wire Wire Line
	1800 6750 1800 6950
Wire Wire Line
	1800 6950 1700 6950
Wire Wire Line
	1700 6950 1700 7050
Wire Wire Line
	2100 6750 2100 7050
Wire Wire Line
	2100 7050 1900 7050
Wire Wire Line
	1950 6750 1950 7000
Wire Wire Line
	1950 7000 1800 7000
Wire Wire Line
	1800 7000 1800 7050
$Comp
L Device:R_Network08 RN2
U 1 1 5FE61F51
P 2700 7250
F 0 "RN2" H 2220 7204 50  0000 R CNN
F 1 "1k" H 2220 7295 50  0000 R CNN
F 2 "Resistor_THT:R_Array_SIP9" V 3175 7250 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 2700 7250 50  0001 C CNN
	1    2700 7250
	-1   0    0    1   
$EndComp
Wire Wire Line
	2250 6750 2250 7050
Wire Wire Line
	2250 7050 2400 7050
Wire Wire Line
	2400 6750 2400 7000
Wire Wire Line
	2400 7000 2500 7000
Wire Wire Line
	2500 7000 2500 7050
Wire Wire Line
	2550 6750 2550 6950
Wire Wire Line
	2550 6950 2600 6950
Wire Wire Line
	2600 6950 2600 7050
Wire Wire Line
	2700 6750 2700 7050
Wire Wire Line
	2850 6750 2850 6900
Wire Wire Line
	2850 6900 2800 6900
Wire Wire Line
	2800 6900 2800 7050
Wire Wire Line
	3000 6750 3000 6950
Wire Wire Line
	3000 6950 2900 6950
Wire Wire Line
	2900 6950 2900 7050
Wire Wire Line
	3300 6750 3300 7050
Wire Wire Line
	3300 7050 3100 7050
Wire Wire Line
	3150 6750 3150 7000
Wire Wire Line
	3150 7000 3000 7000
Wire Wire Line
	3000 7000 3000 7050
Text GLabel 1800 7450 0    50   Input ~ 0
GND
Wire Wire Line
	1800 7450 1900 7450
Text GLabel 3000 7450 0    50   Input ~ 0
GND
Wire Wire Line
	3000 7450 3100 7450
$Comp
L Device:C_Small C1
U 1 1 5FED4298
P 650 5700
F 0 "C1" H 742 5746 50  0000 L CNN
F 1 "100nF" H 742 5655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 650 5700 50  0001 C CNN
F 3 "~" H 650 5700 50  0001 C CNN
	1    650  5700
	1    0    0    -1  
$EndComp
Text GLabel 650  5900 3    50   Input ~ 0
GND
Wire Wire Line
	650  5900 650  5800
Text GLabel 650  5500 1    50   Input ~ 0
VCC
Wire Wire Line
	650  5500 650  5600
$Comp
L Device:C_Small C2
U 1 1 5FF08494
P 1050 5700
F 0 "C2" H 1142 5746 50  0000 L CNN
F 1 "100nF" H 1142 5655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 1050 5700 50  0001 C CNN
F 3 "~" H 1050 5700 50  0001 C CNN
	1    1050 5700
	1    0    0    -1  
$EndComp
Text GLabel 1050 5900 3    50   Input ~ 0
GND
Wire Wire Line
	1050 5900 1050 5800
Text GLabel 1050 5500 1    50   Input ~ 0
VCC
Wire Wire Line
	1050 5500 1050 5600
$Comp
L Device:C_Small C3
U 1 1 5FF220F5
P 1450 5700
F 0 "C3" H 1542 5746 50  0000 L CNN
F 1 "100nF" H 1542 5655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 1450 5700 50  0001 C CNN
F 3 "~" H 1450 5700 50  0001 C CNN
	1    1450 5700
	1    0    0    -1  
$EndComp
Text GLabel 1450 5900 3    50   Input ~ 0
GND
Wire Wire Line
	1450 5900 1450 5800
Text GLabel 1450 5500 1    50   Input ~ 0
VCC
Wire Wire Line
	1450 5500 1450 5600
$Comp
L Device:C_Small C4
U 1 1 5FF3C1EB
P 1850 5700
F 0 "C4" H 1942 5746 50  0000 L CNN
F 1 "100nF" H 1942 5655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 1850 5700 50  0001 C CNN
F 3 "~" H 1850 5700 50  0001 C CNN
	1    1850 5700
	1    0    0    -1  
$EndComp
Text GLabel 1850 5900 3    50   Input ~ 0
GND
Wire Wire Line
	1850 5900 1850 5800
Text GLabel 1850 5500 1    50   Input ~ 0
VCC
Wire Wire Line
	1850 5500 1850 5600
$Comp
L Device:C_Small C5
U 1 1 5FF8E37A
P 2250 5700
F 0 "C5" H 2342 5746 50  0000 L CNN
F 1 "100nF" H 2342 5655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 2250 5700 50  0001 C CNN
F 3 "~" H 2250 5700 50  0001 C CNN
	1    2250 5700
	1    0    0    -1  
$EndComp
Text GLabel 2250 5900 3    50   Input ~ 0
GND
Wire Wire Line
	2250 5900 2250 5800
Text GLabel 2250 5500 1    50   Input ~ 0
VCC
Wire Wire Line
	2250 5500 2250 5600
$Comp
L Device:C_Small C6
U 1 1 5FF8E384
P 2650 5700
F 0 "C6" H 2742 5746 50  0000 L CNN
F 1 "100nF" H 2742 5655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 2650 5700 50  0001 C CNN
F 3 "~" H 2650 5700 50  0001 C CNN
	1    2650 5700
	1    0    0    -1  
$EndComp
Text GLabel 2650 5900 3    50   Input ~ 0
GND
Wire Wire Line
	2650 5900 2650 5800
Text GLabel 2650 5500 1    50   Input ~ 0
VCC
Wire Wire Line
	2650 5500 2650 5600
$Comp
L Device:C_Small C7
U 1 1 5FF8E38E
P 3050 5700
F 0 "C7" H 3142 5746 50  0000 L CNN
F 1 "100nF" H 3142 5655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 3050 5700 50  0001 C CNN
F 3 "~" H 3050 5700 50  0001 C CNN
	1    3050 5700
	1    0    0    -1  
$EndComp
Text GLabel 3050 5900 3    50   Input ~ 0
GND
Wire Wire Line
	3050 5900 3050 5800
Text GLabel 3050 5500 1    50   Input ~ 0
VCC
Wire Wire Line
	3050 5500 3050 5600
$Comp
L Device:C_Small C8
U 1 1 5FF8E398
P 3450 5700
F 0 "C8" H 3542 5746 50  0000 L CNN
F 1 "100nF" H 3542 5655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 3450 5700 50  0001 C CNN
F 3 "~" H 3450 5700 50  0001 C CNN
	1    3450 5700
	1    0    0    -1  
$EndComp
Text GLabel 3450 5900 3    50   Input ~ 0
GND
Wire Wire Line
	3450 5900 3450 5800
Text GLabel 3450 5500 1    50   Input ~ 0
VCC
Wire Wire Line
	3450 5500 3450 5600
Text GLabel 2150 5000 0    50   Input ~ 0
SIG1
Text GLabel 2150 4400 0    50   Input ~ 0
~SIG1
$Comp
L 74xx:74LS00 U1
U 5 1 6023E5AE
P 1200 4550
F 0 "U1" H 1430 4596 50  0000 L CNN
F 1 "74LS00" H 1430 4505 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 1200 4550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 1200 4550 50  0001 C CNN
	5    1200 4550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x16 J3
U 1 1 5F82E9E0
P 3300 1600
F 0 "J3" H 3100 550 50  0000 C CNN
F 1 "Conn_01x16" H 3100 650 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x16_P2.54mm_Horizontal" H 3300 1600 50  0001 C CNN
F 3 "~" H 3300 1600 50  0001 C CNN
	1    3300 1600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2600 1900 2600 1800
Wire Wire Line
	2700 1900 2700 1800
Wire Wire Line
	2800 1900 2800 1800
Wire Wire Line
	2900 1900 2900 1800
Wire Wire Line
	3000 1900 3000 1800
Wire Wire Line
	3100 1900 3100 1800
Wire Wire Line
	3200 1900 3200 1800
Wire Wire Line
	3300 1900 3300 1800
Wire Wire Line
	3400 1900 3400 1800
Wire Wire Line
	3500 1900 3500 1800
Wire Wire Line
	3600 1900 3600 1800
Wire Wire Line
	3700 1900 3700 1800
Wire Wire Line
	3800 1900 3800 1800
Wire Wire Line
	3900 1900 3900 1800
Wire Wire Line
	4000 1900 4000 1800
Wire Wire Line
	4100 1900 4100 1800
Text GLabel 2600 1900 3    50   Input ~ 0
A0
Text GLabel 2700 1900 3    50   Input ~ 0
A1
Text GLabel 2800 1900 3    50   Input ~ 0
A2
Text GLabel 2900 1900 3    50   Input ~ 0
A3
Text GLabel 3000 1900 3    50   Input ~ 0
A4
Text GLabel 3100 1900 3    50   Input ~ 0
A5
Text GLabel 3200 1900 3    50   Input ~ 0
A6
Text GLabel 3300 1900 3    50   Input ~ 0
A7
Text GLabel 3400 1900 3    50   Input ~ 0
A8
Text GLabel 3500 1900 3    50   Input ~ 0
A9
Text GLabel 3600 1900 3    50   Input ~ 0
A10
Text GLabel 3700 1900 3    50   Input ~ 0
A11
Text GLabel 3800 1900 3    50   Input ~ 0
A12
Text GLabel 3900 1900 3    50   Input ~ 0
A13
Text GLabel 4000 1900 3    50   Input ~ 0
A14
Text GLabel 4100 1900 3    50   Input ~ 0
A15
Text Notes 2550 1400 0    50   ~ 0
These provide the value directly to an adjacent\nmodule, to be used as a memory address.
Text Notes 750  2700 0    50   ~ 0
SIG0 = Enable count\nSIG1 = Byte select for IO
$Comp
L 74xx:74LS00 U1
U 2 1 601D1B1D
P 2550 4900
F 0 "U1" H 2550 5225 50  0000 C CNN
F 1 "74LS00" H 2550 5134 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2550 4900 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 2550 4900 50  0001 C CNN
	2    2550 4900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS00 U1
U 1 1 601CEFCA
P 2550 4300
F 0 "U1" H 2550 4625 50  0000 C CNN
F 1 "74LS00" H 2550 4534 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2550 4300 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 2550 4300 50  0001 C CNN
	1    2550 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C9
U 1 1 6033881B
P 3850 5700
F 0 "C9" H 3942 5746 50  0000 L CNN
F 1 "100nF" H 3942 5655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 3850 5700 50  0001 C CNN
F 3 "~" H 3850 5700 50  0001 C CNN
	1    3850 5700
	1    0    0    -1  
$EndComp
Text GLabel 3850 5900 3    50   Input ~ 0
GND
Wire Wire Line
	3850 5900 3850 5800
Text GLabel 3850 5500 1    50   Input ~ 0
VCC
Wire Wire Line
	3850 5500 3850 5600
Text GLabel 1100 2850 0    50   Input ~ 0
VCC
Wire Wire Line
	1100 2850 1200 2850
Text GLabel 1100 3850 0    50   Input ~ 0
GND
Wire Wire Line
	1100 3850 1200 3850
Wire Wire Line
	9000 3850 9800 3850
Wire Wire Line
	8400 3850 8300 3850
$Comp
L 74xx:74LS04 U2
U 7 1 60403DA6
P 1200 3350
F 0 "U2" H 1430 3396 50  0000 L CNN
F 1 "74LS04" H 1430 3305 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 1200 3350 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 1200 3350 50  0001 C CNN
	7    1200 3350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U2
U 1 1 6040575F
P 2550 3050
F 0 "U2" H 2550 3367 50  0000 C CNN
F 1 "74LS04" H 2550 3276 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2550 3050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 2550 3050 50  0001 C CNN
	1    2550 3050
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U2
U 2 1 60406BD2
P 2550 3600
F 0 "U2" H 2550 3917 50  0000 C CNN
F 1 "74LS04" H 2550 3826 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2550 3600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 2550 3600 50  0001 C CNN
	2    2550 3600
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U2
U 3 1 604082BB
P 8700 3850
F 0 "U2" H 8700 4167 50  0000 C CNN
F 1 "74LS04" H 8700 4076 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 8700 3850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 8700 3850 50  0001 C CNN
	3    8700 3850
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U2
U 4 1 607EDE23
P 10250 5000
F 0 "U2" H 10250 5317 50  0000 C CNN
F 1 "74LS04" H 10250 5226 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 10250 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 10250 5000 50  0001 C CNN
	4    10250 5000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U2
U 5 1 607EF49E
P 10250 5500
F 0 "U2" H 10250 5817 50  0000 C CNN
F 1 "74LS04" H 10250 5726 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 10250 5500 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 10250 5500 50  0001 C CNN
	5    10250 5500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U2
U 6 1 607F1889
P 10250 6000
F 0 "U2" H 10250 6317 50  0000 C CNN
F 1 "74LS04" H 10250 6226 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 10250 6000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 10250 6000 50  0001 C CNN
	6    10250 6000
	1    0    0    -1  
$EndComp
Text GLabel 9850 5000 0    50   Input ~ 0
GND
Wire Wire Line
	9850 5000 9950 5000
Text GLabel 9850 5500 0    50   Input ~ 0
GND
Wire Wire Line
	9850 5500 9950 5500
Text GLabel 9850 6000 0    50   Input ~ 0
GND
Wire Wire Line
	9850 6000 9950 6000
NoConn ~ 10550 5000
NoConn ~ 10550 5500
NoConn ~ 10550 6000
$Comp
L 74xx:74LS00 U1
U 3 1 608BA8BA
P 10350 1250
F 0 "U1" H 10350 1575 50  0000 C CNN
F 1 "74LS00" H 10350 1484 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 10350 1250 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 10350 1250 50  0001 C CNN
	3    10350 1250
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS00 U1
U 4 1 608BDA9C
P 10350 1850
F 0 "U1" H 10350 2175 50  0000 C CNN
F 1 "74LS00" H 10350 2084 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 10350 1850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 10350 1850 50  0001 C CNN
	4    10350 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 1150 10050 1250
Wire Wire Line
	10050 1750 10050 1850
Wire Wire Line
	10050 1250 9950 1250
Connection ~ 10050 1250
Wire Wire Line
	10050 1250 10050 1350
Wire Wire Line
	10050 1850 9950 1850
Connection ~ 10050 1850
Wire Wire Line
	10050 1850 10050 1950
Text GLabel 9950 1850 0    50   Input ~ 0
GND
Text GLabel 9950 1250 0    50   Input ~ 0
GND
NoConn ~ 10650 1250
NoConn ~ 10650 1850
Wire Wire Line
	5050 7000 5050 6950
Wire Wire Line
	5050 6950 4450 6950
Wire Wire Line
	4450 5900 4450 6950
Connection ~ 5050 6950
Wire Wire Line
	5050 6950 5050 6900
Wire Wire Line
	5050 5200 5050 5150
Wire Wire Line
	5050 5150 4450 5150
Wire Wire Line
	4450 4100 4450 5150
Connection ~ 5050 5150
Wire Wire Line
	5050 5150 5050 5100
Wire Wire Line
	5050 3400 5050 3350
Wire Wire Line
	5050 3350 4450 3350
Wire Wire Line
	4450 2300 4450 3350
Connection ~ 5050 3350
Wire Wire Line
	5050 3350 5050 3300
$EndSCHEMATC
