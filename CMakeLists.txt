cmake_minimum_required(VERSION 3.3)

project(slope)

find_package(OpenCV REQUIRED)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBRARIES})