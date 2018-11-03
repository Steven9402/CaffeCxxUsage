add_executable(classification_demo main.cpp)
target_link_libraries(classification_demo
        CuiZhouCaffeClassification
        caffe
        glog
        ${OpenCV_LIBS}
        boost_system
        /usr/local/cuda-8.0/lib64/libcudnn.so
        myfutils)