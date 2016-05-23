// Cplusplus_homework3_1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class JuZhen
{
private:
	int Hang;       //���������
	int Lie;        //���������
	int **ptr;      //���ڶ�̬�������ռ��������ָ��

public:
	JuZhen(int H = 0, int L = 0);   //���캯��,��̬�����ڴ�洢����Ԫ��
	JuZhen(const JuZhen &JZ);   //�������캯��
	~JuZhen();           //��������,ע���ͷ��ڴ�

	void InPut();       //�������Ԫ��
	void Show()const;   //��ʾ��������
	JuZhen operator+(const JuZhen &JZ)const;  //���ز����� '+' ʵ�������������
	JuZhen operator-(const JuZhen &JZ)const;  //���ز����� '-' ʵ�������������
	JuZhen operator*(const JuZhen &JZ)const;  //���ز����� '*' ʵ�������������
	JuZhen& operator=(const JuZhen &JZ);    //���ظ�ֵ������ '=' ʵ�־���֮��ĸ�ֵ
	void convert();     //����ת�ú���
};

JuZhen::JuZhen(int H, int L)
{
	Hang = H;
	Lie = L;
	ptr = new int*[Hang];   //����Hang��int*�ռ�
	if (ptr == NULL) //�жϿռ�����Ƿ�ɹ�
	{
		cerr << "����ռ�ʧ��!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<Hang; i++)
	{
		ptr[i] = new int[Lie];//��ÿһ�е�ָ��ָ��һ��Lie��С�Ŀռ�
		if (ptr[i] == NULL)
		{
			cerr << "����ռ�ʧ��!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i<Hang; i++)//������Ԫ��Ĭ��ֵ����Ϊ-1
		for (int j = 0; j<Lie; j++)
			ptr[i][j] = -1;
}

JuZhen::JuZhen(const JuZhen &JZ)
{
	Hang = JZ.Hang;
	Lie = JZ.Lie;
	ptr = new int*[Hang];   //����Hang��int*�ռ�
	if (ptr == NULL) //�жϿռ�����Ƿ�ɹ�
	{
		cerr << "����ռ�ʧ��!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<Hang; i++)
	{
		ptr[i] = new int[Lie];//��ÿһ�е�ָ��ָ��һ��Lie��С�Ŀռ�
		if (ptr[i] == NULL)
		{
			cerr << "����ռ�ʧ��!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i<Hang; i++)   //���ƾ���Ԫ��
		for (int j = 0; j<Lie; j++)
			ptr[i][j] = JZ.ptr[i][j];
}

JuZhen::~JuZhen()
{
	for (int i = 0; i<Hang; i++)
		delete[]ptr[i];
	delete[]ptr;
}

void JuZhen::InPut()
{
	cout << "����һ�� " << Hang << " �� " << Lie << " �еľ���." << endl;
	cout << "������:" << endl;
	for (int i = 0; i<Hang; i++)
		for (int j = 0; j<Lie; j++)
		{
			cout << "��" << i << "��" << j << "��Ԫ��" << "[" << i << "][" << j << "]:";
			cin >> ptr[i][j];
		}
}

void JuZhen::Show() const
{
	for (int i = 0; i<Hang; i++)
	{
		for (int j = 0; j<Lie; j++)
			cout << ptr[i][j] << ' ';
		cout << endl;
	}
}

JuZhen JuZhen::operator +(const JuZhen &JZ) const
{
	if (Hang != JZ.Hang || Lie != JZ.Lie)
	{
		cout << "���������С��һ��,�ӷ�����ʧ��" << endl;
		return JuZhen();
	}

	JuZhen temp(Hang, Lie);//������ʱ����洢������ĺ�
	for (int i = 0; i<Hang; i++)
		for (int j = 0; j<Lie; j++)
			temp.ptr[i][j] = ptr[i][j] + JZ.ptr[i][j];
	return temp;
}

JuZhen JuZhen::operator -(const JuZhen &JZ)const
{
	if (Hang != JZ.Hang || Lie != JZ.Lie)
	{
		cout << "���������С��һ��,��������ʧ��" << endl;
		return JuZhen();
	}

	JuZhen temp(Hang, Lie);//������ʱ����洢������Ĳ�
	for (int i = 0; i<Hang; i++)
		for (int j = 0; j<Lie; j++)
			temp.ptr[i][j] = ptr[i][j] - JZ.ptr[i][j];
	return temp;
}

JuZhen JuZhen::operator *(const JuZhen &JZ) const
{
	if (Lie != JZ.Hang)
	{
		cout << "�����������в�ƥ��,�˷�����ʧ��" << endl;
		return JuZhen();
	}

	JuZhen temp(Hang, JZ.Lie);//������ʱ����洢������Ļ�
	for (int i = 0; i<Hang; i++)
		for (int j = 0; j<JZ.Lie; j++)
		{
			int sum = 0;
			for (int k = 0; k<Lie; k++)
				sum += ptr[i][k] * JZ.ptr[k][j];
			temp.ptr[i][j] = sum;
		}

	return temp;
}

JuZhen& JuZhen::operator =(const JuZhen &JZ)
{
	if (this == &JZ)     //��ֹ����ֵ
		return *this;

	for (int i = 0; i<Hang; i++)//�ͷ�ԭ����ռ�
		delete[]ptr[i];
	delete[]ptr;

	Hang = JZ.Hang;
	Lie = JZ.Lie;
	ptr = new int*[Hang];   //����Hang��int*�ռ�
	if (ptr == NULL) //�жϿռ�����Ƿ�ɹ�
	{
		cerr << "����ռ�ʧ��!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<Hang; i++)
	{
		ptr[i] = new int[Lie];//��ÿһ�е�ָ��ָ��һ��Lie��С�Ŀռ�
		if (ptr[i] == NULL)
		{
			cerr << "����ռ�ʧ��!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i<Hang; i++)   //���ƾ���Ԫ��
		for (int j = 0; j<Lie; j++)
			ptr[i][j] = JZ.ptr[i][j];


	return *this;
}

void JuZhen::convert()
{
	int temp_H = Hang;//�洢�������
	int temp_L = Lie; //�洢�������
	JuZhen temp(Lie, Hang); //������ʱ����洢�����ת��
	for (int i = 0; i<Hang; i++)
		for (int j = 0; j<Lie; j++)
			temp.ptr[j][i] = ptr[i][j];

	for (int i = 0; i<Hang; i++)
		delete[]ptr[i];
	delete[]ptr;

	Hang = temp_L;
	Lie = temp_H;

	ptr = new int*[Hang];   //����Hang��int*�ռ�
	if (ptr == NULL) //�жϿռ�����Ƿ�ɹ�
	{
		cerr << "����ռ�ʧ��!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<Hang; i++)
	{
		ptr[i] = new int[Lie];//��ÿһ�е�ָ��ָ��һ��Lie��С�Ŀռ�
		if (ptr[i] == NULL)
		{
			cerr << "����ռ�ʧ��!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	*this = temp;
}

void main()
{
	JuZhen JZ1(3, 5);
	JuZhen JZ2(3, 5);
	JuZhen JZ3(3, 5);
	JuZhen JZ4(5, 4);
	JuZhen JZ5(3, 4);
	cout << "��ΪJZ1����Ԫ��:" << endl;
	JZ1.InPut();
	cout << "��ΪJZ2����Ԫ��:" << endl;
	JZ2.InPut();
	cout << "JZ1:" << endl;
	JZ1.Show();
	cout << "JZ2:" << endl;
	JZ2.Show();
	cout << "JZ1��JZ2�ĺ���:" << endl;
	JZ3 = JZ1 + JZ2;
	JZ3.Show();
	cout << "JZ1��JZ2�Ĳ���:" << endl;
	JZ3 = JZ1 - JZ2;
	JZ3.Show();
	cout << "��ΪJZ4����Ԫ��:" << endl;
	JZ4.InPut();
	cout << "JZ1��JZ4�Ļ���:" << endl;
	JZ5 = JZ1 * JZ4;
	JZ5.Show();
	cout << "JZ1��ת����:" << endl;
	JZ1.convert();
	JZ1.Show();

	cout << "Done" << endl;
}