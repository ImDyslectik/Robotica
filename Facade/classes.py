#print statements will sends a signal to a pipe which will be read to control the robot
#TODO change prints to signal to pipe to control engines

#high quality drawing of my robot motor vision
# M1 ---- M2
#
#
# M3 ---- M4

#------------------------------------------------------------------------------------------------------
#TODO at line 13 and 16 add pin number for clear indication of which engine is being controlled and how
#------------------------------------------------------------------------------------------------------

class Motor:
    def __init__(self, pin):
        self.pin = pin
        Motor.__init__(self,pin)
    def forward():
        print("forward on :")

    def backward(self):
        print("backward on : ")



class Movement:
    def __init__(self, motor1, motor2, motor3, motor4):
        self.motor1 = motor1
        self.motor2 = motor2
        self.motor3 = motor3
        self.motor4 = motor4
    def Left(self):
        self.motor1.backward
        self.motor2.forward
        self.motor3.backward
        self.motor4.forward
    def Right(self):
        self.motor1.forward()
        self.motor2.backward()
        self.motor3.forward()
        self.motor4.backward()
