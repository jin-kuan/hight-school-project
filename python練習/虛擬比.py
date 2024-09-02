import cv2
import numpy as np
cap=cv2.VideoCapture(0)

def finPen(img):
   
   hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)#轉換成HSV
    
    
   lower=np.array([93,88,41])
   upper=np.array([179,255,191])
   mask=cv2.inRange(hsv,lower,upper)
   result=cv2.bitwise_and(img,img,mask=mask)
   findConur(mask)
   cv2.imshow('result',result)

def findConur(img):
   contours,hierarchy=cv2.findContours(img,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)#偵測外輪廓

   for cnt in contours:
      cv2.drawContours(imgContour,cnt,-1,(255,0,0),4)#劃出輪廓
    
      area=(cv2.contourArea(cnt))#面積
      if area>500:
        prei=(cv2.arcLength(cnt,True))
        vertices=cv2.approxPolyDP(cnt,prei *2/100,True)#頂點
        x,y,w,h=cv2.boundingRect(vertices)
        

while True:

    ret, frame =cap.read()   # ret(下一張圖片有沒有取得成功)、fram(下一張的圖片)
    if ret:#有數字

      imgContour=frame.copy
      finPen(frame)
      cv2.imshow('video',frame) 
      cv2.imshow("contour",imgContour)
      
    else:
       break#結束
    if cv2.waitKey(1 )== ord(' '):
       break 
