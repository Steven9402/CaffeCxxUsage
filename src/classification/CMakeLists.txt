add_library(CuiZhouCaffeClassification SHARED
        Classifier.cpp)
target_link_libraries(CuiZhouCaffeClassification
        caffe
        glog
        ${OpenCV_LIBS}
        boost_system
        /usr/local/cuda-8.0/lib64/libcudnn.so)