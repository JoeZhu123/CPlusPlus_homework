// Cplusplus_final_homework.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "LinkList.h"
#include "ColledgePerson.h"
#include <conio.h>
using namespace std;

void Welcome();
void Exit();
void Inheritance();

int main()
{
	Welcome();
	system("cls");	

	
	LinkList<ColledgePerson> Spl;
	ColledgePerson CP;
	int num = 0,index = 0;
	char choice;
	Spl.create_List(CP.pre, CP.next);
	while (true)
	{
		system("cls");
		cout << "=======================" << endl;
		puts("1、浏览所有信息");
		puts("2、添加信息");
		puts("3、删除信息");
		puts("4、修改信息");
		puts("5、查找信息");
		puts("6、保存信息");
		puts("0、退出");
		cout << "=======================" << endl;
		cout << "请选择您的操作：" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("cls");
			Spl.show_AllData();
			system("pause");
			break;
		case '2':
			system("cls");
			Spl.add_Data(CP.pre, CP.next);
			system("pause");
			break;
		case '3':
			system("cls");
			Spl.delete_Data();
			system("pause");
			break;
		case '4':

			break;
		case '5':
			system("cls");
			Spl.find_Data();
			system("pause");
			break;
		case '6':

			break;
		case '0':
			system("cls");
			Exit();
			break;
		default:
			system("cls");
			cout << "对不起，请输入正确的功能序号！^-^ " << endl;
			system("pause");
			break;
		}
		if (choice == '0')
			break;
	}

    return 0;
}

void Welcome()
{
	printf("\n\n");
	printf("  \t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("  \t┃ *********************************************************┃\n");
	printf("  \t┃***┏━━━━━━━━━━━━━━━━━━━━━━━━┓***┃\n");
	printf("  \t┃***┃************************************************┃***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃***     欢迎使用学校成员信息管理系统        ****┃***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃***                朱幸尔                   **** |***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃***              2016.01.18                 ****┃***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃************************************************┃***┃\n");
	printf("  \t┃***┗━━━━━━━━━━━━━━━━━━━━━━━━┛***┃\n");
	printf("  \t┃ *********************************************************┃\n");
	printf("  \t┗━━━━━━━━━━━按任意键继续━━━━━━━━━━━━┛\n");
	_getch();
}
void Exit()
{
	printf("\n\n");
	printf("  \t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("  \t┃ *********************************************************┃\n");
	printf("  \t┃***┏━━━━━━━━━━━━━━━━━━━━━━━━┓***┃\n");
	printf("  \t┃***┃************************************************┃***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃***         退出学校成员信息管理系统        ****┃***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃***                朱幸尔                   **** |***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃***              2016.01.18                 ****┃***┃\n");
	printf("  \t┃***┃***                                         ****┃***┃\n");
	printf("  \t┃***┃************************************************┃***┃\n");
	printf("  \t┃***┗━━━━━━━━━━━━━━━━━━━━━━━━┛***┃\n");
	printf("  \t┃ *********************************************************┃\n");
	printf("  \t┗━━━━━━━━━━━按任意键结束━━━━━━━━━━━━┛\n");
}
void Inheritance()
{
	//类继承的例程演示
	ColledgePerson stu1(21525118, "zhu", "male", 22);
	undergraduate stu2(21525119, "zhu", "male", 22, 100, "computer science");
	postgraduate stu3(21525120, "zhu", "male", 22, 1000, "Professor Liu");
	workers stu4(21525121, "zhu", "male", 22, 10000, "Manager");
	stu1.Information_P();
	stu2.Information_P();
	stu3.Information_P();
	stu4.Information_P();
}