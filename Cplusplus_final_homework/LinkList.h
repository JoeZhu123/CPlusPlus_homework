//单链表的头文件
#pragma once
#include "stdafx.h"
#include <iostream>
#include "LinkList.h"
#include "ColledgePerson.h"
using namespace std;

template <class Type>
class LinkList //链表类
{
public:
	LinkList();
	~LinkList();	
	void create_List(Type *head, Type *present);
	void add_Data(Type *head, Type *present);
	void delete_Data();
	void find_Data();
	void show_AllData();	
	bool check_Data();	
};