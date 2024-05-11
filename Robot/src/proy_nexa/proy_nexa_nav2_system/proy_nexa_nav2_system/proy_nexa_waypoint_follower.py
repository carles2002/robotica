import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from nav2_msgs.action import FollowWaypoints
from geometry_msgs.msg._pose_stamped import PoseStamped
from geometry_msgs.msg import Twist

class WayPointFollower(Node):
    def __init__(self):
        super().__init__('way_point_follower')
        self._action_client = ActionClient(self, FollowWaypoints, 'follow_waypoints')
      
      

    def define_waypoints(self, waypoints):
        goal = FollowWaypoints.Goal()
        goal.poses = waypoints
        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal,feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

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

   
    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg
        self.get_logger().info('Received feedback: {0}'.format(feedback))
        


def main(args=None):
    rclpy.init(args=args)
    waypoint_follower = WayPointFollower()
     
    waypoints = []
    waypoint1 = PoseStamped()
    waypoint1.header.frame_id='map'
    waypoint1.pose.position.x = 0.2
    waypoint1.pose.position.y = 0.0
    waypoint1.pose.position.z = 0.0
    waypoints.append(waypoint1)

    waypoint2 = PoseStamped()
    waypoint2.header.frame_id='map'
    waypoint2.pose.position.x = 0.4
    waypoint2.pose.position.y = 0.2
    waypoint2.pose.position.z = 0.0
    waypoints.append(waypoint2)
    
    waypoint_follower.define_waypoints(waypoints)

    rclpy.spin(waypoint_follower)

if __name__ == '__main__':
    main()
