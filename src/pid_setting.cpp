#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

using namespace std::chrono_literals;

class PIDsetting : public rclcpp::Node {
    public:
        PIDsetting() : Node("PID_setting"){
            publisher_p = this -> create_publisher < std_msgs::msg::Float64 > ("p_vel", 10);
            publisher_i = this -> create_publisher < std_msgs::msg::Float64 > ("i_vel", 10);
            publisher_d = this -> create_publisher < std_msgs::msg::Float64 > ("d_vel", 10);
        }
    private:
        rclcpp::Publisher< std_msgs::msg::Float64 >::SharedPtr publisher_p;
        rclcpp::Publisher< std_msgs::msg::Float64 >::SharedPtr publisher_i;
        rclcpp::Publisher< std_msgs::msg::Float64 >::SharedPtr publisher_d;
};

int main(int argc,char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PIDsetting>());
    rclcpp::shutdown();
    return 0;
}

