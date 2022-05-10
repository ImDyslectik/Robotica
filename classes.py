#print statements will sends a signal to a pipe which will be read to control the robot
#TODO change prints to signal to pipe


class Motor():
    def Forward(seconds):
        print('going forwards')

    def Backward(seconds):
        print('going backwards')

    def Left(seconds):
        print('going Left')

    def Right(seconds):
        print('going Right')
