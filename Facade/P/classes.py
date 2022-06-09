"""--------------------------------------------------------------------------
initialize pin, pin being the engine.
we then need to combine the int and str into a string so that it can be returned
we do this since we can't have an array with a str and int
--------------------------------------------------------------------------"""       

class Motor:
    def __init__(self, pin):
        self.pin = pin
    def forward(self,pin):
        output = ("F"+str(pin))
        return output
    def backward(self,pin):
        output = ("B"+str(pin))
        return output

"""--------------------------------------------------------------------------
initialize self, motor1 and motor2 to be used in the directions
after initializing these, every direction can put the preditermined commands
into an array and return these.
--------------------------------------------------------------------------"""       

class Movement:
    def __init__(self, motor1, motor2):
        self.motor1 = motor1
        self.motor2 = motor2
    def Left(self):
        command = []
        command.append(self.motor1.backward(1))
        command.append(self.motor2.forward(2))
        return str(command)
    def Right(self):
        command = []
        command.append(self.motor1.forward(1))
        command.append(self.motor2.backward(2))
        return str(command)
    def Forward(self):
        command = []
        command.append(self.motor1.forward(1))
        command.append(self.motor2.forward(2))
        return str(command)
    def Backward(self):
        command = []
        command.append(self.motor1.backward(1))
        command.append(self.motor2.backward(2))
        return str(command)
