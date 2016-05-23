//MyMatrix.h MyMatrix的头文件
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
	MyMatrix operator+(const MyMatrix &PP)const;  //重载操作符 '+' 实现两个矩阵相加
	MyMatrix operator-(const MyMatrix &PP)const;  //重载操作符 '-' 实现两个矩阵相加
	MyMatrix operator*(const MyMatrix &PP)const;  //重载操作符 '*' 实现两个矩阵相加
	MyMatrix& operator=(const MyMatrix &PP);    //重载赋值操作符 '=' 实现矩阵之间的赋值
	void convert();     //矩阵转置函数
};