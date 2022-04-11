cmake_minimum_required(VERSION 2.8)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0")

project(testPnP)

find_package(OpenCV REQUIRED)

# include_directories("/usr/local/include/opencv4")
# include_directories("/usr/include/opencv4")
# include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(testPnP slovePnP/solvePnP.cpp)

# link_directories(${OpenCV_LIBRARY_DIRS})

target_link_libraries(testPnP ${OpenCV_LIBS})