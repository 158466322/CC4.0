#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

namespace caffe {
#ifdef USE_OPENCV
	//��ͼ����
	//�ṩ��ͼ�����ṩ0-1��Χ��ֵ��ͼƬ
	namespace GlobalAugmented{

		//�����������С���������ṩ��ͼȫ����float��
		void noize(Mat& img);
		//���Դ
		void pointLight(Mat& img, float minLimit, float maxLimit);
		//��ʵ���������ͼ���ǲ����ܳ��ֳ���1��
		void limitRange(Mat& img);
		void globalLight(Mat& img);
		void augment(Mat& img, float minLimit = -1, float maxLimit = 1);
	}
#endif
}  // namespace caffe
