// Cplusplus_final_homework.cpp : �������̨Ӧ�ó������ڵ㡣
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
		puts("1�����������Ϣ");
		puts("2�������Ϣ");
		puts("3��ɾ����Ϣ");
		puts("4���޸���Ϣ");
		puts("5��������Ϣ");
		puts("6��������Ϣ");
		puts("0���˳�");
		cout << "=======================" << endl;
		cout << "��ѡ�����Ĳ�����" << endl;
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
			cout << "�Բ�����������ȷ�Ĺ�����ţ�^-^ " << endl;
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
	printf("  \t��������������������������������������������������������������\n");
	printf("  \t�� *********************************************************��\n");
	printf("  \t��***����������������������������������������������������***��\n");
	printf("  \t��***��************************************************��***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��***     ��ӭʹ��ѧУ��Ա��Ϣ����ϵͳ        ****��***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��***                ���Ҷ�                   **** |***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��***              2016.01.18                 ****��***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��************************************************��***��\n");
	printf("  \t��***����������������������������������������������������***��\n");
	printf("  \t�� *********************************************************��\n");
	printf("  \t�������������������������������������������������������������\n");
	_getch();
}
void Exit()
{
	printf("\n\n");
	printf("  \t��������������������������������������������������������������\n");
	printf("  \t�� *********************************************************��\n");
	printf("  \t��***����������������������������������������������������***��\n");
	printf("  \t��***��************************************************��***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��***         �˳�ѧУ��Ա��Ϣ����ϵͳ        ****��***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��***                ���Ҷ�                   **** |***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��***              2016.01.18                 ****��***��\n");
	printf("  \t��***��***                                         ****��***��\n");
	printf("  \t��***��************************************************��***��\n");
	printf("  \t��***����������������������������������������������������***��\n");
	printf("  \t�� *********************************************************��\n");
	printf("  \t�������������������������������������������������������������\n");
}
void Inheritance()
{
	//��̳е�������ʾ
	ColledgePerson stu1(21525118, "zhu", "male", 22);
	undergraduate stu2(21525119, "zhu", "male", 22, 100, "computer science");
	postgraduate stu3(21525120, "zhu", "male", 22, 1000, "Professor Liu");
	workers stu4(21525121, "zhu", "male", 22, 10000, "Manager");
	stu1.Information_P();
	stu2.Information_P();
	stu3.Information_P();
	stu4.Information_P();
}