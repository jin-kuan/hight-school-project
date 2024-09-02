import mediapipe as mp

import cv2

cap=cv2.VideoCapture(0)

mpHands=mp.solutions.hands

while True:
    ret,img=cap.read()
    if ret:
        imgRGB=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)     
        result= hands.process(imgRGB)
        print(result)
        cv2.imshow('img',img)

    if cv2.waitKey(1)==ord('q'):
        break
   


    