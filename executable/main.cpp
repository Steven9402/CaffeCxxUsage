//
// Created by cuizhou on 18-3-4.
//

#include "../src/classification/Classifier.h"
#include "../src/myfUtils/FileOperator.h"

using namespace cv;
using namespace std;

int main(int argc,char** argv){

    ::google::InitGoogleLogging(argv[0]);

    string model_file   = "../../res/models/traffic_sign_binary_model/deploy.prototxt";
    string trained_file = "../../res/models/traffic_sign_binary_model/_iter_20000.caffemodel";
    string mean_file    = "../../res/models/traffic_sign_binary_model/mean.binaryproto";
    string label_file   = "../../res/models/traffic_sign_binary_model/label.txt";;
    Classifier classifier(model_file, trained_file, mean_file, label_file);

    char* img_dir = "../../data/binarytask";
    vector<string> filenames =  myf::readFileList(img_dir);

    for (auto filename:filenames){
        std::cout << "---------- Prediction for "
                  << filename << " ----------" << std::endl;

        string img_dir_=img_dir;
        Mat srcImage = imread(img_dir_+"/"+filename);
        CHECK(!srcImage.empty()) << "Unable to decode image " << filename;
        std::vector<Prediction> predictions = classifier.Classify(srcImage);

        /* Print the top N predictions. */
        for (size_t i = 0; i < predictions.size(); ++i) {
            Prediction p = predictions[i];
            std::cout << std::fixed << std::setprecision(4) << p.second << " - \""
                      << p.first << "\"" << std::endl;
        }

        if(predictions.size()>0){
            ostringstream oo;
            oo<<predictions[0].first<<" - "<<predictions[0].second;
            resize(srcImage,srcImage,Size(300,300));
            putText(srcImage,oo.str(),Point(5,50),FONT_HERSHEY_COMPLEX,1.0,Scalar(0,255,0),1,8,0);

            imshow("result",srcImage);
            waitKey(0);
        }

    }

    return 1;
}
