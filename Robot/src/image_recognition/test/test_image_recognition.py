import pytest
from keras.models import load_model
import cv2
import numpy as np
import os

# Cargar el modelo y las etiquetas
package_share_directory = '../resource'
model_path = os.path.join(package_share_directory, 'keras_model.h5')
labels_path = os.path.join(package_share_directory, 'labels.txt')
model = load_model(model_path, compile=False)
with open(labels_path, "r") as f:
    class_names = [line.strip() for line in f.readlines()]

# Función para preprocesar la imagen
def preprocess_image(image_path):
    image = cv2.imread(image_path)
    image = cv2.resize(image, (224, 224), interpolation=cv2.INTER_AREA)
    image = np.asarray(image, dtype=np.float32).reshape(1, 224, 224, 3)
    image = (image / 127.5) - 1
    return image

# Test para la jirafa
def test_giraffe():
    image = preprocess_image('test_resources/jirafa.jpg')
    prediction = model.predict(image)
    index = np.argmax(prediction)
    assert class_names[index] == 'Jirafa', f"Expected 'Jirafa', got '{class_names[index]}'"
    print(f"Se esperaba 'Jirafa', se obtuvo '{class_names[index]}'")

# Test para el león
def test_lion():
    image = preprocess_image('test_resources/leon.jpg')
    prediction = model.predict(image)
    index = np.argmax(prediction)
    assert class_names[index] == 'Leon', f"Expected 'Leon', got '{class_names[index]}'"
    print(f"Se esperaba 'Leon', se obtuvo '{class_names[index]}'")

# Test para el mono
def test_monkey():
    image = preprocess_image('test_resources/mono.jpg')
    prediction = model.predict(image)
    index = np.argmax(prediction)
    assert class_names[index] == 'Mono', f"Expected 'Mono', got '{class_names[index]}'"
    print(f"Se esperaba 'Mono', se obtuvo '{class_names[index]}'")
    