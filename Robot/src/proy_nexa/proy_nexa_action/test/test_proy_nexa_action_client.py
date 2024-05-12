import pytest
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from nav2_msgs.action import NavigateToPose
from action_msgs.msg import GoalStatus

class TestActionClient(Node):
    def __init__(self):
        super().__init__('test_action_client')
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

    def send_goal(self):
        goal_pose = NavigateToPose.Goal()
        goal_pose.pose.header.frame_id = 'map'
        goal_pose.pose.pose.position.x = 3.0
        goal_pose.pose.pose.position.y = -2.0
        goal_pose.pose.pose.position.z = 0.0
        goal_pose.pose.pose.orientation.x = 0.0
        goal_pose.pose.pose.orientation.y = 0.0
        goal_pose.pose.pose.orientation.z = 0.0
        goal_pose.pose.pose.orientation.w = 1.0

        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal_pose)

        self._send_goal_future.add_done_callback(self.goal_response_callback)
        return self._send_goal_future

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Result: {0}'.format(result.status))
        rclpy.shutdown()

@pytest.fixture
def test_action_client():
    rclpy.init()
    client = TestActionClient()
    yield client
    client.destroy_node()
    rclpy.shutdown()

def test_send_goal(test_action_client):
    print("Prueba de que es capaz de mandar una posicion deseada. Esta es: ")
    print("X= 3.0")
    print("Y= -2.0")
    print("Z= 0.0")

    future = test_action_client.send_goal()
    rclpy.spin_until_future_complete(test_action_client, future)
    assert future.result().accepted == True
