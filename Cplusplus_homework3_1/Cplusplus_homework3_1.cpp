// Cplusplus_homework3_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class JuZhen
{
private:
	int Hang;       //矩阵的行数
	int Lie;        //矩阵的列数
	int **ptr;      //用于动态分配矩阵空间所定义的指针

public:
	JuZhen(int H = 0, int L = 0);   //构造函数,动态分配内存存储矩阵元素
	JuZhen(const JuZhen &JZ);   //拷贝构造函数
	~JuZhen();           //析构函数,注意释放内存

	void InPut();       //输入矩阵元素
	void Show()const;   //显示矩阵内容
	JuZhen operator+(const JuZhen &JZ)const;  //重载操作符 '+' 实现两个矩阵相加
	JuZhen operator-(const JuZhen &JZ)const;  //重载操作符 '-' 实现两个矩阵相加
	JuZhen operator*(const JuZhen &JZ)const;  //重载操作符 '*' 实现两个矩阵相加
	JuZhen& operator=(const JuZhen &JZ);    //重载赋值操作符 '=' 实现矩阵之间的赋值
	void convert();     //矩阵转置函数
};

JuZhen::JuZhen(int H, int L)
{
	Hang = H;
	Lie = L;
	ptr = new int*[Hang];   //分配Hang个int*空间
	if (ptr == NULL) //判断空间分配是否成功
	{
		cerr << "分配空间失败!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<Hang; i++)
	{
		ptr[i] = new int[Lie];//让每一行的指针指向一个Lie大小的空间
		if (ptr[i] == NULL)
		{
			cerr << "分配空间失败!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i<Hang; i++)//将矩阵元素默认值设置为-1
		for (int j = 0; j<Lie; j++)
			ptr[i][j] = -1;
}

JuZhen::JuZhen(const JuZhen &JZ)
{
	Hang = JZ.Hang;
	Lie = JZ.Lie;
	ptr = new int*[Hang];   //分配Hang个int*空间
	if (ptr == NULL) //判断空间分配是否成功
	{
		cerr << "分配空间失败!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<Hang; i++)
	{
		ptr[i] = new int[Lie];//让每一行的指针指向一个Lie大小的空间
		if (ptr[i] == NULL)
		{
			cerr << "分配空间失败!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i<Hang; i++)   //复制矩阵元素
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
	cout << "这是一个 " << Hang << " 行 " << Lie << " 列的矩阵." << endl;
	cout << "请输入:" << endl;
	for (int i = 0; i<Hang; i++)
		for (int j = 0; j<Lie; j++)
		{
			cout << "第" << i << "行" << j << "列元素" << "[" << i << "][" << j << "]:";
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
		cout << "两个矩阵大小不一致,加法操作失败" << endl;
		return JuZhen();
	}

	JuZhen temp(Hang, Lie);//创建临时对象存储两矩阵的和
	for (int i = 0; i<Hang; i++)
		for (int j = 0; j<Lie; j++)
			temp.ptr[i][j] = ptr[i][j] + JZ.ptr[i][j];
	return temp;
}

JuZhen JuZhen::operator -(const JuZhen &JZ)const
{
	if (Hang != JZ.Hang || Lie != JZ.Lie)
	{
		cout << "两个矩阵大小不一致,减法操作失败" << endl;
		return JuZhen();
	}

	JuZhen temp(Hang, Lie);//创建临时对象存储两矩阵的差
	for (int i = 0; i<Hang; i++)
		for (int j = 0; j<Lie; j++)
			temp.ptr[i][j] = ptr[i][j] - JZ.ptr[i][j];
	return temp;
}

JuZhen JuZhen::operator *(const JuZhen &JZ) const
{
	if (Lie != JZ.Hang)
	{
		cout << "两个矩阵行列不匹配,乘法操作失败" << endl;
		return JuZhen();
	}

	JuZhen temp(Hang, JZ.Lie);//创建临时对象存储两矩阵的积
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
	if (this == &JZ)     //防止自身赋值
		return *this;

	for (int i = 0; i<Hang; i++)//释放原矩阵空间
		delete[]ptr[i];
	delete[]ptr;

	Hang = JZ.Hang;
	Lie = JZ.Lie;
	ptr = new int*[Hang];   //分配Hang个int*空间
	if (ptr == NULL) //判断空间分配是否成功
	{
		cerr << "分配空间失败!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<Hang; i++)
	{
		ptr[i] = new int[Lie];//让每一行的指针指向一个Lie大小的空间
		if (ptr[i] == NULL)
		{
			cerr << "分配空间失败!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i<Hang; i++)   //复制矩阵元素
		for (int j = 0; j<Lie; j++)
			ptr[i][j] = JZ.ptr[i][j];


	return *this;
}

void JuZhen::convert()
{
	int temp_H = Hang;//存储矩阵的行
	int temp_L = Lie; //存储矩阵的列
	JuZhen temp(Lie, Hang); //创建临时对象存储矩阵的转置
	for (int i = 0; i<Hang; i++)
		for (int j = 0; j<Lie; j++)
			temp.ptr[j][i] = ptr[i][j];

	for (int i = 0; i<Hang; i++)
		delete[]ptr[i];
	delete[]ptr;

	Hang = temp_L;
	Lie = temp_H;

	ptr = new int*[Hang];   //分配Hang个int*空间
	if (ptr == NULL) //判断空间分配是否成功
	{
		cerr << "分配空间失败!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<Hang; i++)
	{
		ptr[i] = new int[Lie];//让每一行的指针指向一个Lie大小的空间
		if (ptr[i] == NULL)
		{
			cerr << "分配空间失败!" << endl;
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
	cout << "请为JZ1输入元素:" << endl;
	JZ1.InPut();
	cout << "请为JZ2输入元素:" << endl;
	JZ2.InPut();
	cout << "JZ1:" << endl;
	JZ1.Show();
	cout << "JZ2:" << endl;
	JZ2.Show();
	cout << "JZ1和JZ2的和是:" << endl;
	JZ3 = JZ1 + JZ2;
	JZ3.Show();
	cout << "JZ1和JZ2的差是:" << endl;
	JZ3 = JZ1 - JZ2;
	JZ3.Show();
	cout << "请为JZ4输入元素:" << endl;
	JZ4.InPut();
	cout << "JZ1与JZ4的积是:" << endl;
	JZ5 = JZ1 * JZ4;
	JZ5.Show();
	cout << "JZ1的转置是:" << endl;
	JZ1.convert();
	JZ1.Show();

	cout << "Done" << endl;
}