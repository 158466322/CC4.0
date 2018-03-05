

#include "caffe/cc/core/cc_matrix.h"
#include <highgui.h>

using namespace cv;

namespace cc{

	//��ͼƬ���ݹ���
	Matrix::Matrix(cbytes image_data, size_t length, int color_flags){
		init();

		//Ŀǰ��Ĭ��Ϊͼ�����
		try{
			data = cv::imdecode(Mat(1, length, CV_8U, (void*)image_data), color_flags);
		}
		catch (...){}
	}

	//��Mat����
	Matrix::Matrix(const Mat& mat, bool copy_data){
		init();

		CvMat m = mat;
		data = Mat(&m, copy_data);
	}

	//���ļ����죬�����ͼƬ�ļ���color_flags����imread�Ĳ�����������Զ����ʽ����û������
	Matrix::Matrix(const char* file, int color_flags){
		init();

		data = cv::imread(file, color_flags);
	}

	//��Matrix����
	Matrix::Matrix(const Matrix& other, bool copy_data){
		init();

		CvMat m = other.data;
		this->data = Mat(&m, copy_data);
		copyFrom(other);
	}

	Matrix::Matrix(){
		init();
	}

	void Matrix::init(){
	}

	Matrix& Matrix::operator = (const Matrix& other){
		this->data = other.data;
		copyFrom(other);
		return *this;
	}

	Matrix& Matrix::operator = (const Mat& other){
		this->data = other;
		return *this;
	}

	Matrix::operator Mat(){
		return this->data;
	}

	void Matrix::copyFrom(const Matrix& other){

	}
};
