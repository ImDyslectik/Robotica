import math
import sys
import time
from grove.adc import ADC
 
 #set file path so that we can open it later and write to the file
Pipe = '/tmp/command'
 
 #code to use grove library
class GroveSensor(ADC):
    def __init__(self, channel):
        self.channel = channel
        self.adc = ADC()
 
    @property
    def value(self):
        return self.adc.read(self.channel)
 

class GroveSend:
    ax = []
    def __init__(self):
        pass
    #methode om naar links te sturen
    def left():
        ax = []
        ax.append("S1")
        return str(ax)
    #methode om naar rechts te sturen
    def right():
        ax = []
        ax.append("S3")
        return str(ax)
    #methode om niet te sturen
    def stationair():
        ax = []
        ax.append("S2")
        return str(ax)
    #methode om aan te geven dat de lucht schoon is
    def good():
        ax = []
        ax.append("A1")
        return str(ax)
    #methode om aan te geven dat de lucht vervuild is
    def bad():
        ax = []
        ax.append("A2")
        return str(ax)

Grove = GroveSensor
send = GroveSend

 
def main():
    mode = send.stationair()
    modeAir = send.good()
    currentMode = send.right()
    currentModeAir = send.bad()
    #potmeter aansluiten op A1
    angleSensor = GroveSensor(1)
    #airquality meter aansluiten op A2
    airSensor = GroveSensor(2)
 
    while True: 
        with open(Pipe,"w") as ax:
            #als de knik links van het midden staat, stuur naar rechts 
            if (angleSensor.value < 401):
                mode = send.left()
            #als de knik rechts van het midden staat, stuur naar links
            if (angleSensor.value > 551):
                mode = send.right()
                #als de knik recht staat, niet sturen
            if (angleSensor.value >400 and angleSensor.value < 550):
                mode = send.stationair()
            #lucht kwaliteit doorgeven
            if airSensor.value > 100:
                modeAir = send.bad()
            if airSensor.value < 99:
                modeAir = send.good()
            if(mode != currentMode):
                ax.write(mode)
                print(mode)
                print(angleSensor.value)
                currentMode = mode
            if(modeAir != currentModeAir):
                ax.write(modeAir)
                print(modeAir)
                currentModeAir = modeAir
            time.sleep(.1)


 
if __name__ == '__main__':
    main()
