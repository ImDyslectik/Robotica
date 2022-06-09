import math
import sys
import time
from grove.adc import ADC
 
 
class GroveAirQualitySensor:
 
    def __init__(self, channel):
        self.channel = channel
        self.adc = ADC()
 
    @property
    def value(self):
        return self.adc.read(self.channel)
 
Grove = GroveAirQualitySensor
 
 
def main():
    if len(sys.argv) < 2:
        print('Usage: {} adc_channel'.format(sys.argv[0]))
        sys.exit(1)
 
    sensor = GroveAirQualitySensor(int(sys.argv[1]))
 
    print('Detecting ...') 
    while True:
        value = sensor.value        
        if value > 100:
            print("{}, High Pollution.".format(value))
        else:
            print("{}, Air Quality OK.".format(value))
 
        time.sleep(.1)
 
if __name__ == '__main__':
    main()
