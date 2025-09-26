#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::placeholders;

class CppNode : public rclcpp::Node 
{
public:
    CppNode() : Node("cppnode") 
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::String>(
            "message", 10,
            std::bind(&CppNode::callbackMessage, this, _1));
        RCLCPP_INFO(this->get_logger(),"started");
    }
private:
    void callbackMessage(const example_interfaces::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(),"%s", msg->data.c_str());
    }

    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CppNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}