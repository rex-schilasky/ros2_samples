#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"

class PointCloudSubscriber : public rclcpp::Node
{
public:
  PointCloudSubscriber()
  : Node("pointcloud_subscriber")
  {
    auto subscription_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
      "PointCloud2",
      10,
      [this](sensor_msgs::msg::PointCloud2::UniquePtr /* msg */) {
        RCLCPP_INFO(this->get_logger(), "Received a message");
      });
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PointCloudSubscriber>());
  rclcpp::shutdown();
  return 0;
}
