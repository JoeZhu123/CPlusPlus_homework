//MyMatrix.cpp��ĳ�Ա����
#include "stdafx.h"
#include <iostream>
#include "MyMatrix.h"

using namespace std;


MyMatrix::MyMatrix(int r, int c)
{
	PP_rows = r;
	PP_cols = c;
	PP_matrix = new int*[PP_rows];
	if (PP_matrix == NULL) //�жϿռ�����Ƿ�ɹ�
	{
		cerr << "����ռ�ʧ��!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<PP_rows; i++)
	{
		PP_matrix[i] = new int[PP_cols];
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

MyMatrix::MyMatrix(const MyMatrix &PP)
{
	PP_rows = PP.PP_rows;
	PP_cols = PP.PP_cols;
	PP_matrix = new int*[PP_rows];
	if (PP_matrix == NULL) //�жϿռ�����Ƿ�ɹ�
	{
		cerr << "����ռ�ʧ��!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<PP_rows; i++)
	{
		PP_matrix[i] = new int[PP_cols];
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

MyMatrix::~MyMatrix()
{
	for (int i = 0; i<PP_rows; i++)
		delete[]PP_matrix[i];
	delete[]PP_matrix;
}

void MyMatrix::Input()
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

void MyMatrix::Show()
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
MyMatrix MyMatrix::operator +(const MyMatrix &PP) const
{
	if (PP_rows != PP.PP_rows || PP_cols != PP.PP_cols)
	{
		cout << "���������С��һ��,�ӷ�����ʧ��" << endl;
		return MyMatrix();
	}

	MyMatrix temp(PP_rows, PP_cols);//������ʱ����洢������ĺ�
	for (int i = 0; i<PP_rows; i++)
		for (int j = 0; j<PP_cols; j++)
			temp.PP_matrix[i][j] = PP_matrix[i][j] + PP.PP_matrix[i][j];
	return temp;
}

MyMatrix MyMatrix::operator -(const MyMatrix &PP)const
{
	if (PP_rows != PP.PP_rows || PP_cols != PP.PP_cols)
	{
		cout << "���������С��һ��,��������ʧ��" << endl;
		return MyMatrix();
	}

	MyMatrix temp(PP_rows, PP_cols);//������ʱ����洢������Ĳ�
	for (int i = 0; i<PP_rows; i++)
		for (int j = 0; j<PP_cols; j++)
			temp.PP_matrix[i][j] = PP_matrix[i][j] - PP.PP_matrix[i][j];
	return temp;
}

MyMatrix MyMatrix::operator *(const MyMatrix &PP) const
{
	if (PP_cols != PP.PP_rows)
	{
		cout << "�����������в�ƥ��,�˷�����ʧ��" << endl;
		return MyMatrix();
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

MyMatrix& MyMatrix::operator =(const MyMatrix &PP)
{
	if (this == &PP)     //��ֹ����ֵ
		return *this;

	for (int i = 0; i<PP_rows; i++)//�ͷ�ԭ����ռ�
		delete[]PP_matrix[i];
	delete[]PP_matrix;

	PP_rows = PP.PP_rows;
	PP_cols = PP.PP_cols;
	PP_matrix = new int*[PP_rows];   //����PP_rows��int*�ռ�
	if (PP_matrix == NULL) //�жϿռ�����Ƿ�ɹ�
	{
		cerr << "����ռ�ʧ��!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<PP_rows; i++)
	{
		PP_matrix[i] = new int[PP_cols];//��ÿһ�е�ָ��ָ��һ��PP_cols��С�Ŀռ�
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

void MyMatrix::convert()
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

	PP_matrix = new int*[PP_rows];   //����PP_rows��int*�ռ�
	if (PP_matrix == NULL) //�жϿռ�����Ƿ�ɹ�
	{
		cerr << "����ռ�ʧ��!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<PP_rows; i++)
	{
		PP_matrix[i] = new int[PP_cols];//��ÿһ�е�ָ��ָ��һ��PP_cols��С�Ŀռ�
		if (PP_matrix[i] == NULL)
		{
			cerr << "����ռ�ʧ��!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	*this = temp;
}