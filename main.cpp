#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>
using namespace cv;
using namespace std;
class Fidelity{
public:
    double ems,SNR;
    Fidelity(){this->ems=0;this->SNR=0;}
    void Fidelity_Criteria(const Mat &compressed, const Mat &decompressed);
};

void Fidelity::Fidelity_Criteria(const Mat &compressed,const Mat& decompressed)
{
    if (compressed.size!=decompressed.size)
    {
        cout<<"the compressed and decoompressed images are not in the same szie"<<endl
           <<"Please input check your two images "<<endl;
        return ;
    }

    SNR=norm(decompressed,NORM_L2);
    ems=norm(compressed,decompressed,NORM_L2);
    SNR=pow((SNR/ems),2);
    ems=sqrt(ems*ems/(compressed.rows*compressed.cols));
}

int main(int argc, char *argv[])
{
    Mat decompress = imread("/home/timlentse/Qtproject/1.tif",CV_LOAD_IMAGE_GRAYSCALE);
    Mat compressed = imread("/home/timlentse/Qtproject/noise.tif",CV_LOAD_IMAGE_GRAYSCALE);
    Fidelity obj;
    obj.Fidelity_Criteria(compressed,decompress);
    cout<< "the ems of the images ="<<obj.ems<<endl<<"Now the SNR ="<<obj.SNR<<endl;
    return 0;
}
