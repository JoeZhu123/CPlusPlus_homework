// Cplusplus_homework2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "MyMatrix.h"

using namespace std;

int const M = 3;
int main()
{	
	int PP1_Rows, PP1_Cols;
	cout << "�붨��PP1����:" << endl;
	cin >> PP1_Rows;
	cout << "�붨��PP1����:" << endl;
	cin >> PP1_Cols;
	MyMatrix PP1(PP1_Rows, PP1_Cols);
	MyMatrix PP2(PP1_Rows, PP1_Cols);
	MyMatrix PP3(PP1_Rows, PP1_Cols);
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
	MyMatrix PP4(PP4_Rows, PP4_Cols);
	MyMatrix PP5(PP1_Rows, PP4_Cols);
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

