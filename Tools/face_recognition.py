import cv2 as cv
import numpy as np


def rescaleFrame(frame, scale=0.50):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimension = (width, height)
    return cv.resize(frame, dimension, interpolation = cv.INTER_AREA)


haar_cascade = cv.CascadeClassifier('haarcascade_frontalface_default.xml')

people = ['gorakh', 'mehak', 'ragini', 'roshni']
# features = np.load('features.npy')
# labels = np.load('labels.npy')


face_recognizer = cv.face.LBPHFaceRecognizer_create()
face_recognizer.read('face_trained.yml')


img = cv.imread('images/human6.jpg')
img = rescaleFrame(img, 0.12)
grey = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Grey', grey)


# Detect Face

faces_rect = haar_cascade.detectMultiScale(grey, scaleFactor= 1.1, minNeighbors=4)

for (x, y, w, h) in faces_rect:
    faces_roi = grey[y:y+h, x:x+w]

    label, confidence = face_recognizer.predict(faces_roi)
    print(f'Label = {people[label]} Confidence = {confidence}')

    cv.putText(img, str(people[label]), (20,20), cv.FONT_HERSHEY_COMPLEX, 1.0, (0,255,0), 2)
    cv.rectangle(img, (x, y), (x+w, y+h), (0,255,0), thickness=2)


cv.imshow('detect', img)

cv.waitKey(0)
cv.destroyAllWindows()