import time
import pytest
from proy_nexa_interface.srv import MyMoveMsg
import rclpy
from rclpy.node import Node

class Client(Node):
    def __init__(self):
        super().__init__('test_client')
        self.cli = self.create_client(MyMoveMsg, 'movement')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')

    def send_request(self, move):
        req = MyMoveMsg.Request()
        req.move = move
        self.future = self.cli.call_async(req)

@pytest.fixture
def test_client():
    rclpy.init()
    client = Client()
    yield client
    client.destroy_node()
    rclpy.shutdown()

def test_movement_derecha(test_client):
    print("Prueba de movimiento hacia la derecha")
    test_client.send_request("derecha")
    rclpy.spin_until_future_complete(test_client, test_client.future)
    assert test_client.future.result().success == True
    time.sleep(5)

def test_movement_izquierda(test_client):
    print("Prueba de movimiento hacia la izquierda")
    test_client.send_request("izquierda")
    rclpy.spin_until_future_complete(test_client, test_client.future)
    assert test_client.future.result().success == True
    time.sleep(5)

def test_movement_delante(test_client):
    print("Prueba de movimiento hacia delante")
    test_client.send_request("delante")
    rclpy.spin_until_future_complete(test_client, test_client.future)
    assert test_client.future.result().success == True
    time.sleep(5)

def test_movement_atras(test_client):
    print("Prueba de movimiento hacia atras")
    test_client.send_request("atras")
    rclpy.spin_until_future_complete(test_client, test_client.future)
    assert test_client.future.result().success == True
    time.sleep(5)

def test_movement_parar(test_client):
    print("Prueba de movimiento para parar")
    test_client.send_request("parar")
    rclpy.spin_until_future_complete(test_client, test_client.future)
    assert test_client.future.result().success == True
    time.sleep(5)

def test_movement_invalid(test_client):
    print("Prueba de movimiento con orden invalida")
    test_client.send_request("invalid")
    rclpy.spin_until_future_complete(test_client, test_client.future)
    assert test_client.future.result().success == False