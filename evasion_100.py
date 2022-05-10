from GPIOEmulator.EmulatorGUI import GPIO
import time

#setup pins, 
GPIO.setmode(GPIO.BCM)
TRIG = 23
ECHO = 24
GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)
GPIO.output(TRIG, False)
while(True):
  print ("Waiting For Sensor To Settle")
  time.sleep(2)
  GPIO.output(TRIG, True)
  time.sleep(0.00001)
  GPIO.output(TRIG, False)
  while GPIO.input(ECHO)==0:
    pulse_start = time.time()

  #wait for input on the pin 24 until it gives back distance  
  while GPIO.input(ECHO)==1:
    pulse_end = time.time()
    pulse_duration = pulse_end - pulse_start
    distance = pulse_duration * 17150
    distance = round(distance, 2)
    if(distance < 4000):
      #needs real envirment testing to determine braking distance
      #make motor slowly wind down if within within maximum braking distance
      print ("Distance:",distance,"cm")
  GPIO.cleanup()