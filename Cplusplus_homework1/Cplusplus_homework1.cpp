// Cplusplus_homework1.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
class Max_Min
{
public:
	T *N_array;
private:
	int size;
public:
	Max_Min() { size = 5; }
	~Max_Min() {}
	T Max(T *N_array)
	{
		T max_num = N_array[0];
		/*�ҳ������е����ֵ*/
		for(int j = 0; j < size; j++)
		{
			if (N_array[j] > max_num)
			{
				max_num = N_array[j];
			}
		}
		return max_num;
	}
	T Min(T *N_array)
	{
		T min_num = N_array[0];
		/*�ҳ������е���Сֵ*/
		for(int i = 0; i < size; i++)
		{
			if (N_array[i] < min_num)
			{
				min_num = N_array[i];
			}
		}
		return min_num;
	}
};


int main()
{
	int N1[5];
	float N2[5];
	int length = 5;
	cout << "�������������飺" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> N1[i];
	}	
	cout << "������ʵ�����飺" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> N2[i];
	}	
	Max_Min <int> NN;
	Max_Min <float> NF;
	cout << "������������ֵ��" << NN.Max(N1) << endl;
	cout << "�����������Сֵ��" << NN.Min(N1) << endl;
	cout << "ʵ����������ֵ��" << NF.Max(N2) << endl;
	cout << "ʵ���������Сֵ��" << NF.Min(N2) << endl;
	cout << "Done." << endl;
	return 0;
}

