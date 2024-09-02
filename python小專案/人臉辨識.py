import cv2
img=cv2.imread('w.jpg')
img=cv2.resize(img,(0,0),fx=0.5,fy=0.5)
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
face=cv2.CascadeClassifier('f.xml')

facereat=face.detectMultiScale(gray,1.1,3)#要偵測的圖片 每次放大的倍數 要被偵測幾次
print(len(facereat))

for (x,y,m,h)  in facereat:
    cv2.rectangle(img,(x,y),(x+m,y+h),(0,255,0),2)#把臉框起來


cv2.imshow('img',img)
cv2.waitKey(0)