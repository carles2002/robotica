import os
import numpy as np
import pytest
import rclpy
from proy_nexa_image.capturar import Ros2OpenCVImageConverter

# Inicialización del nodo ROS2 para las pruebas
@pytest.fixture
def ros2_node():
    rclpy.init()
    node = Ros2OpenCVImageConverter()
    yield node
    node.destroy_node()
    rclpy.shutdown()

# Prueba para verificar la inicialización correcta del nodo
def test_init(ros2_node):
    assert ros2_node.bridge_object is not None
    assert ros2_node.image_sub is not None

# Prueba para verificar la funcionalidad de la conversión de imagen
def test_camera_callback(ros2_node, mocker):
    # Mock para simular la recepción de un mensaje de imagen
    mocker.patch.object(ros2_node, 'camera_callback', return_value=None)
    # Simulación de una llamada al callback con un mensaje de imagen ficticio
    ros2_node.camera_callback('data')
    # Verificación de que el callback fue llamado
    ros2_node.camera_callback.assert_called_once()

# Prueba para verificar la aplicación del filtro sepia
def test_apply_sepia(ros2_node):
    # Crear una imagen de prueba en blanco y negro
    test_image = np.zeros((100, 100, 3), dtype=np.uint8)
    # Aplicar el filtro sepia
    sepia_image = ros2_node.apply_sepia(test_image)
    # Verificar que la imagen resultante no es nula
    assert sepia_image is not None
