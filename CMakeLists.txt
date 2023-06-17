cmake_minimum_required(VERSION 3.10.0)
project(vision)

find_package(OpenCV REQUIRED)


include_directories(${OpenCV_INCLUDE_DIRS})

link_directories ( ${OpenCV_LIBRARY_DIRS} )

add_executable( imshow src/imshow.cpp)
add_executable( videoplayer src/videoplayer.cpp)

target_link_libraries(videoplayer ${OpenCV_LIBRARIES})
target_link_libraries(imshow ${OpenCV_LIBRARIES})

