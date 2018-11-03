cmake_minimum_required(VERSION 3.5)
project(CuizhouObjDetect)

# c++11 required
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# OpenVC3 required
set(CMAKE_PREFIX_PATH /home/cuizhou/Downloads/opencv-3.4.0/build)
find_package(OpenCV 3 REQUIRED)

# boost
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

include_directories(
        3rdParties/caffe/include
        /usr/local/cuda-8.0/include
        src
)

link_directories(3rdParties/caffe/lib)


add_subdirectory(src)
add_subdirectory(executable)