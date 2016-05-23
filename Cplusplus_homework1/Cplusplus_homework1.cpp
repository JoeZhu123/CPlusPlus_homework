// Cplusplus_homework1.cpp : 定义控制台应用程序的入口点。
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
		/*找出数组中的最大值*/
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
		/*找出数组中的最小值*/
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
	cout << "请输入整数数组：" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> N1[i];
	}	
	cout << "请输入实数数组：" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> N2[i];
	}	
	Max_Min <int> NN;
	Max_Min <float> NF;
	cout << "整数数组的最大值：" << NN.Max(N1) << endl;
	cout << "整数数组的最小值：" << NN.Min(N1) << endl;
	cout << "实数数组的最大值：" << NF.Max(N2) << endl;
	cout << "实数数组的最小值：" << NF.Min(N2) << endl;
	cout << "Done." << endl;
	return 0;
}

