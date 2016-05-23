// Cplusplus_homework2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "MyMatrix.h"

using namespace std;

int const M = 3;
int main()
{	
	int PP1_Rows, PP1_Cols;
	cout << "请定义PP1的行:" << endl;
	cin >> PP1_Rows;
	cout << "请定义PP1的列:" << endl;
	cin >> PP1_Cols;
	MyMatrix PP1(PP1_Rows, PP1_Cols);
	MyMatrix PP2(PP1_Rows, PP1_Cols);
	MyMatrix PP3(PP1_Rows, PP1_Cols);
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
	MyMatrix PP4(PP4_Rows, PP4_Cols);
	MyMatrix PP5(PP1_Rows, PP4_Cols);
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

