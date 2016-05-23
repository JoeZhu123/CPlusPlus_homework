//MyMatrix.h MyMatrix��ͷ�ļ�
#pragma once
#include <iostream>
#include "MyMatrix.h"

class MyMatrix
{
public:
	int **PP_matrix;
	int *p;
private:
	int length;
	int PP_rows;
	int PP_cols;
public:
	MyMatrix(int r = 0, int c = 0);
	MyMatrix(const MyMatrix &PP);
	~MyMatrix();

	void Input();
	void Show();
	MyMatrix operator+(const MyMatrix &PP)const;  //���ز����� '+' ʵ�������������
	MyMatrix operator-(const MyMatrix &PP)const;  //���ز����� '-' ʵ�������������
	MyMatrix operator*(const MyMatrix &PP)const;  //���ز����� '*' ʵ�������������
	MyMatrix& operator=(const MyMatrix &PP);    //���ظ�ֵ������ '=' ʵ�־���֮��ĸ�ֵ
	void convert();     //����ת�ú���
};