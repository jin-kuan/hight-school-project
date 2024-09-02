import cv2
abc = cv2.imread('7818cd.png')
if abc is None:
    print("Failed to load image")
else:
    cv2.imshow('abc', abc)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
