import numpy as np
import cv2 as cv

#create videocapture device and check if camera is working
#also reduce width and height for increased performance
cap = cv.VideoCapture(0)
if not cap.isOpened():
    print("Cannot open camera")
    exit()
width = cap.get(cv.CAP_PROP_FRAME_WIDTH)
height = cap.get(cv.CAP_PROP_FRAME_HEIGHT)

lower = np.array([30,50,30])
upper = np.array([80,255,255])

print("{} {}".format(width, height))
while True:
    ret, frame = cap.read()
    
    if not ret:
        print("cannot recieve frame")
        break
    
    ROI = frame[420:480, 0:640]
    hsv = cv.cvtColor(ROI, cv.COLOR_BGR2HSV)

    mask = cv.inRange(hsv, lower, upper)

    res = cv.bitwise_and(ROI,ROI, mask= mask)
    
    ret, thresh = cv.threshold(mask, 127, 255, 0)
    
    contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)

    for cnt in contours:
        area = cv.contourArea(cnt)
        if area < 500:
            continue
        M = cv.moments(cnt)
        cx = int(M['m10']/M['m00'])
        cy = int(M['m01']/M['m00'])

        cv.circle(ROI, (cx, cy), 2, (0,255,255), 2)

        cv.drawContours(ROI, [cnt], -1, (0,255,255), 2)

    cv.imshow("frame", ROI)
    if cv.waitKey(1) == ord('q'):
        break

cap.release()
cv.destroyAllWindows()
