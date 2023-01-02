#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "dummy1_msg/msg/pid.hpp"

using namespace std::chrono_literals;

class PIDsetting : public rclcpp::Node {
    public:
        PIDsetting() : Node("PID_setting"), count_(0) {
            publisher_ = this -> create_publisher < dummy1_msg::msg::PID > ("pid_topic", 10);
        }
    private:
        rclcpp::Publisher< dummy1_msg::msg::PID >::SharedPtr publisher_;
        size_t count_;
};

int main(int argc,char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PIDsetting>());
    rclcpp::shutdown();
    return 0;
}

