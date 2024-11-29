#include "rclcpp/rclcpp.hpp"
#include "practice/msg/system_status.hpp"
#include "statgrab.h"
#include "sys/utsname.h"
#include "chrono"

using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;

struct utsname sysinfo;

class node_of_system : public Node
{
    public:
        explicit node_of_system(const string& node_name) : Node(node_name)
        {
            publisher_ = this->create_publisher<practice::msg::SystemStatus>("check_system", 10);
            timer_ = this->create_wall_timer(1000ms, bind(&node_of_system::timer_callback, this));
        }

        void timer_callback()
        {
            auto msg = practice::msg::SystemStatus();
            if (uname(&sysinfo) == 0) {
                msg.host_name = sysinfo.nodename;
            }
            else {
                RCLCPP_ERROR(this->get_logger(), "Fail to get system info");
            }
            sg_init(0);
            size_t entries;
            sg_cpu_stats *cpu_stats = sg_get_cpu_stats(&entries);
            sg_mem_stats *mem_stats = sg_get_mem_stats(&entries);

            if (cpu_stats && mem_stats) {
                msg.cpu_percent = cpu_stats->user + cpu_stats->kernel;
                msg.cpu_available = cpu_stats->idle;
                msg.memory_percent = (mem_stats->used / (float)mem_stats->total) * 100;
                msg.memory_total = mem_stats->total / 1024;
                msg.memory_available = mem_stats->free / 1024;

                RCLCPP_INFO(this->get_logger(), "System name is %s", sysinfo.sysname);
                RCLCPP_INFO(this->get_logger(), "CPU percent is %.0f", msg.cpu_percent);
                RCLCPP_INFO(this->get_logger(), "CPU available is %.0f", msg.cpu_available);
                RCLCPP_INFO(this->get_logger(), "Memory total is %.0f", msg.memory_total);
                RCLCPP_INFO(this->get_logger(), "Memory percent is %.2f", msg.memory_percent);
                RCLCPP_INFO(this->get_logger(), "Memory available is %.0f", msg.memory_available);
            }
            else {
                RCLCPP_ERROR(this->get_logger(), "Fail to get CPU or MEMORY status");
            }
            sg_shutdown();
            publisher_->publish(msg);
        }
    private:
        Publisher<practice::msg::SystemStatus>::SharedPtr publisher_;
        TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv)
{
    init(argc, argv);
    auto node = make_shared<node_of_system>("node_publish_sysinfo");
    spin(node);
    shutdown();
}