cmake_minimum_required(VERSION 3.8)
project(cpppackage)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(cppnode src/cppnode.cpp)
ament_target_dependencies(cppnode rclcpp example_interfaces)

install(TARGETS
  cppnode
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
