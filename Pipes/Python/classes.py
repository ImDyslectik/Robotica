#print statements will be replaced to sends a signal to a pipe which will be read to control the robot
#TODO change prints to signal to pipe to control engines

#high quality drawing of my robot motor vision
# M1 ---- M2
#    front
#
# M3 ---- M4
#    back

class Motor:
    def __init__(self, motor):
        self.motor = motor
    def forward(self):
        print("forward on :", self.motor)

    def backward(self):
        print("backward on : ", self.motor)

class Movement:
    def __init__(self, motor1, motor2):
        self.motor1 = motor1
        self.motor2 = motor2
    def Left(self):
        self.motor1.backward()
        self.motor2.forward()
    def Right(self):
        self.motor1.forward()
        self.motor2.backward()
    def Forward(self):
        self.motor1.forward()
        self.motor2.forward()
    def Backward(self):
        self.motor1.backward()
        self.motor2.backward()