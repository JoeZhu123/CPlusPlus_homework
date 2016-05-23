// Cplusplus_homework4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class T>
class MyMatrix
{
public:
	T **PP_matrix;
	T *p;
private:
	int length;
	int PP_rows;
	int PP_cols;
public:
	MyMatrix(int r, int c)
	{
		PP_rows = r;
		PP_cols = c;
		PP_matrix = new T*[PP_rows];
		if (PP_matrix == NULL) //判断空间分配是否成功
		{
			cerr << "分配空间失败!" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i<PP_rows; i++)
		{
			PP_matrix[i] = new T[PP_cols];
			if (PP_matrix[i] == NULL)
			{
				cerr << "分配空间失败!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		for (int i = 0; i<PP_rows; i++)//将矩阵元素默认值设置为-1
			for (int j = 0; j<PP_cols; j++)
				PP_matrix[i][j] = -1;
	}

	MyMatrix(const MyMatrix &PP)
	{
		PP_rows = PP.PP_rows;
		PP_cols = PP.PP_cols;
		PP_matrix = new T*[PP_rows];
		if (PP_matrix == NULL) //判断空间分配是否成功
		{
			cerr << "分配空间失败!" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i<PP_rows; i++)
		{
			PP_matrix[i] = new T[PP_cols];
			if (PP_matrix[i] == NULL)
			{
				cerr << "分配空间失败!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		for (int i = 0; i<PP_rows; i++)   //复制矩阵元素
			for (int j = 0; j<PP_cols; j++)
				PP_matrix[i][j] = PP.PP_matrix[i][j];
	}

	~MyMatrix()
	{
		for (int i = 0; i<PP_rows; i++)
			delete[]PP_matrix[i];
		delete[]PP_matrix;
	}

	void Input()
	{
		cout << "This is a matrix of " << PP_rows << " rows " << PP_cols << " cols." << endl;
		cout << "Please Input:" << endl;
		for (int i = 0; i<PP_rows; i++)
			for (int j = 0; j<PP_cols; j++)
			{
				cout << "The " << i << " row " << j << " col " << "[" << i << "][" << j << "]:";
				cin >> PP_matrix[i][j];
			}
	}

	void Show()
	{
		for (int i = 0; i<PP_rows; i++)
		{
			for (int j = 0; j<PP_cols; j++)
				cout << PP_matrix[i][j] << ' ';
			cout << endl;
		}
		cout << "\n" << "Show_Done" << endl;
	}
	//以下函数定义矩阵的加减乘除运算
	MyMatrix operator +(const MyMatrix &PP) const
	{
		if (PP_rows != PP.PP_rows || PP_cols != PP.PP_cols)
		{
			cout << "两个矩阵大小不一致,加法操作失败" << endl;
			//return MyMatrix();
		}

		MyMatrix temp(PP_rows, PP_cols);//创建临时对象存储两矩阵的和
		for (int i = 0; i<PP_rows; i++)
			for (int j = 0; j<PP_cols; j++)
				temp.PP_matrix[i][j] = PP_matrix[i][j] + PP.PP_matrix[i][j];
		return temp;
	}

	MyMatrix operator -(const MyMatrix &PP)const
	{
		if (PP_rows != PP.PP_rows || PP_cols != PP.PP_cols)
		{
			cout << "两个矩阵大小不一致,减法操作失败" << endl;
			//return MyMatrix();
		}

		MyMatrix temp(PP_rows, PP_cols);//创建临时对象存储两矩阵的差
		for (int i = 0; i<PP_rows; i++)
			for (int j = 0; j<PP_cols; j++)
				temp.PP_matrix[i][j] = PP_matrix[i][j] - PP.PP_matrix[i][j];
		return temp;
	}

	MyMatrix operator*(const MyMatrix &PP) const
	{
		if (PP_cols != PP.PP_rows)
		{
			cout << "两个矩阵行列不匹配,乘法操作失败" << endl;
			//return MyMatrix();
		}

		MyMatrix temp(PP_rows, PP.PP_cols);//创建临时对象存储两矩阵的积
		for (int i = 0; i<PP_rows; i++)
			for (int j = 0; j<PP.PP_cols; j++)
			{
				int sum = 0;
				for (int k = 0; k<PP_cols; k++)
					sum += PP_matrix[i][k] * PP.PP_matrix[k][j];
				temp.PP_matrix[i][j] = sum;
			}

		return temp;
	}

	MyMatrix& operator =(const MyMatrix &PP)
	{
		if (this == &PP)     //防止自身赋值
			return *this;

		for (int i = 0; i<PP_rows; i++)//释放原矩阵空间
			delete[]PP_matrix[i];
		delete[]PP_matrix;

		PP_rows = PP.PP_rows;
		PP_cols = PP.PP_cols;
		PP_matrix = new T*[PP_rows];   //分配PP_rows个T*空间
		if (PP_matrix == NULL) //判断空间分配是否成功
		{
			cerr << "分配空间失败!" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i<PP_rows; i++)
		{
			PP_matrix[i] = new T[PP_cols];//让每一行的指针指向一个PP_cols大小的空间
			if (PP_matrix[i] == NULL)
			{
				cerr << "分配空间失败!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		for (int i = 0; i<PP_rows; i++)   //复制矩阵元素
			for (int j = 0; j<PP_cols; j++)
				PP_matrix[i][j] = PP.PP_matrix[i][j];


		return *this;
	}

	void convert()
	{
		int temp_H = PP_rows;//存储矩阵的行
		int temp_L = PP_cols; //存储矩阵的列
		MyMatrix temp(PP_cols, PP_rows); //创建临时对象存储矩阵的转置
		for (int i = 0; i<PP_rows; i++)
			for (int j = 0; j<PP_cols; j++)
				temp.PP_matrix[j][i] = PP_matrix[i][j];

		for (int i = 0; i<PP_rows; i++)
			delete[]PP_matrix[i];
		delete[]PP_matrix;

		PP_rows = temp_L;
		PP_cols = temp_H;

		PP_matrix = new T*[PP_rows];   //分配PP_rows个T*空间
		if (PP_matrix == NULL) //判断空间分配是否成功
		{
			cerr << "分配空间失败!" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i<PP_rows; i++)
		{
			PP_matrix[i] = new T[PP_cols];//让每一行的指针指向一个PP_cols大小的空间
			if (PP_matrix[i] == NULL)
			{
				cerr << "分配空间失败!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		*this = temp;
	}
};

int main()
{
	int PP1_Rows, PP1_Cols;
	cout << "请定义PP1的行:" << endl;
	cin >> PP1_Rows;
	cout << "请定义PP1的列:" << endl;
	cin >> PP1_Cols;
	MyMatrix<double> PP1(PP1_Rows, PP1_Cols);
	MyMatrix<double> PP2(PP1_Rows, PP1_Cols);
	MyMatrix<double> PP3(PP1_Rows, PP1_Cols);
	cout << "请为PP1输入元素:" << endl;
	PP1.Input();
	cout << "请为PP2输入元素:" << endl;
	PP2.Input();
	cout << "PP1:" << endl;
	PP1.Show();
	cout << "PP2:" << endl;
	PP2.Show();
	cout << "PP1和PP2的和是:" << endl;
	PP3 = PP1 + PP2;
	PP3.Show();
	cout << "PP1和PP2的差是:" << endl;
	PP3 = PP1 - PP2;
	PP3.Show();

	int PP4_Rows, PP4_Cols;
	cout << "请定义PP4的行:" << endl;
	cin >> PP4_Rows;
	cout << "请定义PP4的列:" << endl;
	cin >> PP4_Cols;
	MyMatrix<double> PP4(PP4_Rows, PP4_Cols);
	MyMatrix<double> PP5(PP1_Rows, PP4_Cols);
	cout << "请为PP4输入元素:" << endl;
	PP4.Input();
	cout << "PP1与PP4的积是:" << endl;
	PP5 = PP1 * PP4;
	PP5.Show();
	cout << "PP1的转置是:" << endl;
	PP1.convert();
	PP1.Show();
	return 0;
}

