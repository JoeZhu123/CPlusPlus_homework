// Cplusplus_homework4.cpp : �������̨Ӧ�ó������ڵ㡣
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
		if (PP_matrix == NULL) //�жϿռ�����Ƿ�ɹ�
		{
			cerr << "����ռ�ʧ��!" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i<PP_rows; i++)
		{
			PP_matrix[i] = new T[PP_cols];
			if (PP_matrix[i] == NULL)
			{
				cerr << "����ռ�ʧ��!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		for (int i = 0; i<PP_rows; i++)//������Ԫ��Ĭ��ֵ����Ϊ-1
			for (int j = 0; j<PP_cols; j++)
				PP_matrix[i][j] = -1;
	}

	MyMatrix(const MyMatrix &PP)
	{
		PP_rows = PP.PP_rows;
		PP_cols = PP.PP_cols;
		PP_matrix = new T*[PP_rows];
		if (PP_matrix == NULL) //�жϿռ�����Ƿ�ɹ�
		{
			cerr << "����ռ�ʧ��!" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i<PP_rows; i++)
		{
			PP_matrix[i] = new T[PP_cols];
			if (PP_matrix[i] == NULL)
			{
				cerr << "����ռ�ʧ��!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		for (int i = 0; i<PP_rows; i++)   //���ƾ���Ԫ��
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
	//���º����������ļӼ��˳�����
	MyMatrix operator +(const MyMatrix &PP) const
	{
		if (PP_rows != PP.PP_rows || PP_cols != PP.PP_cols)
		{
			cout << "���������С��һ��,�ӷ�����ʧ��" << endl;
			//return MyMatrix();
		}

		MyMatrix temp(PP_rows, PP_cols);//������ʱ����洢������ĺ�
		for (int i = 0; i<PP_rows; i++)
			for (int j = 0; j<PP_cols; j++)
				temp.PP_matrix[i][j] = PP_matrix[i][j] + PP.PP_matrix[i][j];
		return temp;
	}

	MyMatrix operator -(const MyMatrix &PP)const
	{
		if (PP_rows != PP.PP_rows || PP_cols != PP.PP_cols)
		{
			cout << "���������С��һ��,��������ʧ��" << endl;
			//return MyMatrix();
		}

		MyMatrix temp(PP_rows, PP_cols);//������ʱ����洢������Ĳ�
		for (int i = 0; i<PP_rows; i++)
			for (int j = 0; j<PP_cols; j++)
				temp.PP_matrix[i][j] = PP_matrix[i][j] - PP.PP_matrix[i][j];
		return temp;
	}

	MyMatrix operator*(const MyMatrix &PP) const
	{
		if (PP_cols != PP.PP_rows)
		{
			cout << "�����������в�ƥ��,�˷�����ʧ��" << endl;
			//return MyMatrix();
		}

		MyMatrix temp(PP_rows, PP.PP_cols);//������ʱ����洢������Ļ�
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
		if (this == &PP)     //��ֹ����ֵ
			return *this;

		for (int i = 0; i<PP_rows; i++)//�ͷ�ԭ����ռ�
			delete[]PP_matrix[i];
		delete[]PP_matrix;

		PP_rows = PP.PP_rows;
		PP_cols = PP.PP_cols;
		PP_matrix = new T*[PP_rows];   //����PP_rows��T*�ռ�
		if (PP_matrix == NULL) //�жϿռ�����Ƿ�ɹ�
		{
			cerr << "����ռ�ʧ��!" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i<PP_rows; i++)
		{
			PP_matrix[i] = new T[PP_cols];//��ÿһ�е�ָ��ָ��һ��PP_cols��С�Ŀռ�
			if (PP_matrix[i] == NULL)
			{
				cerr << "����ռ�ʧ��!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		for (int i = 0; i<PP_rows; i++)   //���ƾ���Ԫ��
			for (int j = 0; j<PP_cols; j++)
				PP_matrix[i][j] = PP.PP_matrix[i][j];


		return *this;
	}

	void convert()
	{
		int temp_H = PP_rows;//�洢�������
		int temp_L = PP_cols; //�洢�������
		MyMatrix temp(PP_cols, PP_rows); //������ʱ����洢�����ת��
		for (int i = 0; i<PP_rows; i++)
			for (int j = 0; j<PP_cols; j++)
				temp.PP_matrix[j][i] = PP_matrix[i][j];

		for (int i = 0; i<PP_rows; i++)
			delete[]PP_matrix[i];
		delete[]PP_matrix;

		PP_rows = temp_L;
		PP_cols = temp_H;

		PP_matrix = new T*[PP_rows];   //����PP_rows��T*�ռ�
		if (PP_matrix == NULL) //�жϿռ�����Ƿ�ɹ�
		{
			cerr << "����ռ�ʧ��!" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i<PP_rows; i++)
		{
			PP_matrix[i] = new T[PP_cols];//��ÿһ�е�ָ��ָ��һ��PP_cols��С�Ŀռ�
			if (PP_matrix[i] == NULL)
			{
				cerr << "����ռ�ʧ��!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		*this = temp;
	}
};

int main()
{
	int PP1_Rows, PP1_Cols;
	cout << "�붨��PP1����:" << endl;
	cin >> PP1_Rows;
	cout << "�붨��PP1����:" << endl;
	cin >> PP1_Cols;
	MyMatrix<double> PP1(PP1_Rows, PP1_Cols);
	MyMatrix<double> PP2(PP1_Rows, PP1_Cols);
	MyMatrix<double> PP3(PP1_Rows, PP1_Cols);
	cout << "��ΪPP1����Ԫ��:" << endl;
	PP1.Input();
	cout << "��ΪPP2����Ԫ��:" << endl;
	PP2.Input();
	cout << "PP1:" << endl;
	PP1.Show();
	cout << "PP2:" << endl;
	PP2.Show();
	cout << "PP1��PP2�ĺ���:" << endl;
	PP3 = PP1 + PP2;
	PP3.Show();
	cout << "PP1��PP2�Ĳ���:" << endl;
	PP3 = PP1 - PP2;
	PP3.Show();

	int PP4_Rows, PP4_Cols;
	cout << "�붨��PP4����:" << endl;
	cin >> PP4_Rows;
	cout << "�붨��PP4����:" << endl;
	cin >> PP4_Cols;
	MyMatrix<double> PP4(PP4_Rows, PP4_Cols);
	MyMatrix<double> PP5(PP1_Rows, PP4_Cols);
	cout << "��ΪPP4����Ԫ��:" << endl;
	PP4.Input();
	cout << "PP1��PP4�Ļ���:" << endl;
	PP5 = PP1 * PP4;
	PP5.Show();
	cout << "PP1��ת����:" << endl;
	PP1.convert();
	PP1.Show();
	return 0;
}

