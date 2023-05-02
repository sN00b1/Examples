import cv2

face_cascades = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontface_default.xml')

cv2.imread('face.jpg')

cap = cv2.VideoCapture(0)

while True:
    succsess, frame = cap.read()
    cv2.imshow('Camera', frame)
    if cv2.waitKey(1) & 0xff == ord('q'):
        break
    