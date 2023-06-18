cmake_minimum_required(VERSION 3.10.0)
project(vision)

find_package(OpenCV REQUIRED)


include_directories(${OpenCV_INCLUDE_DIRS})
include_directories( include)
link_directories ( ${OpenCV_LIBRARY_DIRS} )

add_executable( imshow src/imshow.cpp)
add_executable( videoplayer src/videoplayer.cpp)
add_executable( main src/main.cpp include/videoplayer.cpp include/videoplayer.hpp)
target_link_libraries(videoplayer ${OpenCV_LIBRARIES})
target_link_libraries(imshow ${OpenCV_LIBRARIES})
target_link_libraries(main ${OpenCV_LIBRARIES})

