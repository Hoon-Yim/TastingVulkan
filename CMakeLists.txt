cmake_minimum_required(VERSION 3.20)
project(VulkanTutorial)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
set(GLFW_H /usr/local/Cellar/glfw/3.3.4/include)
include_directories(${GLFW_H})

set(GLFW_LINK /usr/local/Cellar/glfw/3.3.4/lib/libglfw.3.dylib)
link_libraries(${GLFW_LINK} Vulkan::Vulkan)

add_executable(VulkanTutorial main.cpp VeWindow.cpp VeWindow.h VeApplication.cpp VeApplication.h VeDevice.h VeDevice.cpp)
