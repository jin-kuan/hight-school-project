import cv2
import numpy as np

def empty(v):
    pass


#a=cv2.imread('bbbbb.jpg')
#a=cv2.resize(a,(0,0),fx=0.25,fy=0.25)

p=cv2.VideoCapture(0)

cv2.namedWindow('abc')#新增視窗
cv2.resizeWindow('abc',640,320 )#改變大小

cv2.createTrackbar('hun min','abc',0,179,empty)#新增控制條 名稱 在哪 最小值 最大值 
cv2.createTrackbar('hun max','abc',179,179,empty)
cv2.createTrackbar('sat min','abc',0,255,empty)
cv2.createTrackbar('sat max','abc',255,255,empty)
cv2.createTrackbar('hun min','abc',0,255,empty)
cv2.createTrackbar('val min','abc',0,255,empty)
cv2.createTrackbar('val max','abc',255,255,empty)


#b=cv2.cvtColor(a,cv2.COLOR_BGR2HSV)#轉換成HSV

while True:
    h_min=cv2.getTrackbarPos('hun min','abc') #讀取控制條
    h_max=cv2.getTrackbarPos('hun max','abc')
    s_min=cv2.getTrackbarPos('sat min','abc')
    s_max=cv2.getTrackbarPos('sat max','abc')
    v_min=cv2.getTrackbarPos('val min','abc')
    v_max=cv2.getTrackbarPos('val max','abc')
    
    print(h_min,h_max,s_min,s_max,v_min,v_max)

    ret,a=p.read()
    b=cv2.cvtColor(a,cv2.COLOR_BGR2HSV)#轉換成HSV
    
    
    lower=np.array([h_min,s_min,v_min])
    upper=np.array([h_max,s_max,v_max])
    c=cv2.inRange(b,lower,upper)
    d=cv2.bitwise_and(a,a,mask=c)
    
    #cv2.imshow('a',a)
    #cv2.imshow('b',b)
    #cv2.imshow('c',c)
    cv2.imshow('d',d)
   
    cv2.waitKey(10)
