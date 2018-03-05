
#ifndef CC_MATRIX_H
#define CC_MATRIX_H

#include <cv.h>

using cv::Mat;

namespace cc{

	typedef const char* cbytes;

	class Matrix{

	public:
		//ƾ�չ���
		Matrix();

		//�����ݹ���
		Matrix(cbytes image_data, size_t length, int color_flags = 1);
		
		//��Mat����
		Matrix(const Mat& mat, bool copy_data = false);

		//���ļ����죬�����ͼƬ�ļ���color_flags����imread�Ĳ�����������Զ����ʽ����û������
		Matrix(const char* file, int color_flags = 1);

		//��Matrix����
		Matrix(const Matrix& other, bool copy_data = false);

		operator Mat();
		Matrix& operator = (const Matrix& other);
		Matrix& operator = (const Mat& other);
		const Mat mat() { return this->data; }
		Mat mutable_mat() { return this->data; }

	private:
		void init();


	private:
		Mat data;
		void copyFrom(const Matrix& other);
	};
};
#endif //CC_MATRIX_H