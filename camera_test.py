import cv2
import numpy as np
import math

vid = cv2.VideoCapture(0)

while(True):
    ret,frame = vid.read()
    
    lower_blue = np.array([130,0,0])
    upper_blue = np.array([255,180,120])
    maskblue = cv2.inRange(frame, lower_blue, upper_blue)
    blue = cv2.bitwise_and(frame, frame, mask =  maskblue)
    
    ret,th = cv2.threshold(maskblue,180,255,cv2.THRESH_BINARY_INV)
    contours, hierarchy = cv2.findContours(th,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    
    for cont in range(len(contours)):
        contour = contours[cont]
        area = cv2.contourArea(contour)
        perimeter = cv2.arcLength(contour, True)
        if area > 0 and perimeter > 0:
            factor = 4 * math.pi * area / perimeter**2

        if   factor > 0.25 and factor < 50 and area > 150:
            cv2.drawContours(frame, [contour], -1, (0,255,255), 3)
    
    cv2.imshow('frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('b'):
        break
vid.release()
cv2.destroyAllWindows()