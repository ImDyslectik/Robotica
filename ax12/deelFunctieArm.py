#import serial
#import time
#import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)

port = serial.Serial("/dev/ttyAMA0", baudrate=1000000, timeout=3.0)
print("dit programma is")

for x in range(3):
        GPIO.output(18, GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF 15 07 03 1E 05 02 00 01 BA"))
        time.sleep(0.0000001)
        GPIO.output(18, GPIO.LOW)
        while port.in_waiting:
            print(port.read())
        print("Boven_Motor_21")

        GPIO.output(18, GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF 10 07 03 1E 05 02 00 01 BF"))
        time.sleep(0.0000001)
        GPIO.output(18, GPIO.LOW)
        while port.in_waiting:
            print(port.read())
        print("Boven_Motor_2")


        print("Rechts_Motor_2")

        time.sleep(3)

        GPIO.output(18,GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF 15 07 03 1E CD 00 00 01 F4"))
        time.sleep(0.0000001)
        GPIO.output(18,GPIO.LOW)
        while port.in_waiting:
            print(port.read())
        print("Rechts_Motor_21")

        GPIO.output(18,GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF 10 07 03 1E CD 00 00 01 F9"))
        time.sleep(0.0000001)
        GPIO.output(18,GPIO.LOW)
        while port.in_waiting:
            print(port.read())
        print("Rechts_Motor_2")

        time.sleep(3)
        print(x)

GPIO.cleanup()
