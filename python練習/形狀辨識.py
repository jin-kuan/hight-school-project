import cv2

abc=cv2.imread('eheheh.jpg')
a=cv2.cvtColor(abc,cv2.COLOR_BGR2GRAY)
b=cv2.Canny(a,100,80 )
ab=abc.copy()

contours,hierarchy=cv2.findContours(b,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)#偵測外輪廓

for cnt in contours:
    cv2.drawContours(ab,cnt,-1,(255,0,0),4)#劃出輪廓
    
    big=(cv2.contourArea(cnt))#面積
    if big>500:
        #print(cv2.contourArea(cnt))#面積
        #print(cv2.arcLength(cnt,True))#邊長
        pri=(cv2.arcLength(cnt,True))
        cc=cv2.approxPolyDP(cnt,pri *2/100,True)#頂點
        print(len(cc))
        x,y,w,h=cv2.boundingRect(cc)
        cv2.rectangle(ab,(x,y),(x+w,y+h),(0,255,0),4)#把圖形框起來


cv2.imshow("a",abc)
cv2.imshow("a",a)
cv2.imshow('b',b)
cv2.imshow('c',ab)


cv2.waitKey(0)
