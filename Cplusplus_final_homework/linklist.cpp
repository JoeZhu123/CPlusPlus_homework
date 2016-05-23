#include "stdafx.h"
#include <iostream>
#include <string>
#include<iomanip>
#include "LinkList.h"
#include "ColledgePerson.h"
using namespace std;

template <class Type>LinkList<Type>::LinkList()  //往链表尾添加节点
{

}
template <class Type>LinkList<Type>::~LinkList()  //往链表尾添加节点
{

}
template <class Type>void LinkList<Type>::create_List(Type *head, Type *present)//创建链表
{
	present = new Type;
	head = present;
	present->next = NULL;
	present->pre = NULL;
}
template <class Type>void LinkList<Type>::add_Data(Type *head, Type *present)  //往链表尾添加信息数据
{
	present = new Type;
	head->pre = present;
	present->next = head;
	head = present;
	present->pre = NULL;
	present->InsertData();
}
template <class Type>void LinkList<Type>::delete_Data() //删除链表中的信息数据
{
	cout << "Input ID_Number which need to delete: ";
	if (check_Data()) 
	{
		delete present;
		cout << "Delete success!" << endl;		
	}
	else 
		cout << "Delete Failure." << endl;

}
template <class Type>void LinkList<Type>::find_Data() //查找链表中的信息数据
{
	cout << "Input ID_Number which need to find: ";
	if (check_Data())
	{
		cout << "Find successfully!" << endl;
	}
	else
		cout << "Can not find!." << endl;

}
template <class Type>bool LinkList<Type>::check_Data()
{
	present = head;
	int the_data;
	cin >> the_data;
	while (present->next != NULL)
	{
		if (the_data == present->m_ID_Number) 
		{
			present->Information_P();
			return true;
		}
		else 
		{
			present = present->next;
			continue;
		}
	}
	cout << "No such information!" << endl;
	return false;
}

template <class Type>void LinkList<Type>::show_AllData()//遍历链表信息
{
	present = head;
	if (present == NULL) 
		cout << "Empty List!" << endl;
	else
	{
		while (present->next != NULL)
		{
			present->Information_P();
			present = present->next;
		}
	}
}
