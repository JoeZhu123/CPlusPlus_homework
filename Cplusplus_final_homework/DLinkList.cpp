#include "stdafx.h"
#include <iostream>
#include "DLinkList.h"
using namespace std;

template <class Type> int DblList<Type>::Find(const Type & target) {
	//��˫��ѭ��������������target�Ľ�㣬
	//�����ɹ�����1�����򷵻�0��
	DblNode<Type> *p = first��rLink;
	while (p != first && p��data != target)
		p = p��rLink;	 //ѭ������
	if (p != first) { current = p;  return 1; }
	return 0;
}

template <class Type> void DblList<Type>::Insert(const Type & value) {
	if (current == NULL)          //�ձ�����
		current = first��rLink = new DblNode(value, first, first);
	else {                                      //�ǿձ�����
		current��rLink = new DblNode(value, current, current��rLink);
		current = current��rLink;
	}
	current��rLink��lLink = current;
}

template <class Type>
void DblList<Type>::Remove() {
	if (current != NULL) {
		DblNode *temp = current;
		current = current��rLink;
		current��lLink = temp��lLink;
		temp��lLink��rLink = current;
		delete temp;
		if (current == first)
			if (IsEmpty()) current = NULL;
			else  current = current��rLink;
	}
}

template <class Type>
DblList<Type>::DblLIst(Type uniqueVal) {
	//˫��ѭ������Ĺ��캯��, ������ͷ���
	first = new DblNode<Type>(uniqueVal);
	first��rLink = first��lLink = first;
	current = NULL;
}

template<class Type>
DblList<Type>::~DblList()
{
}

template <class Type>
int DblList<Type>::Length() const {
	//��˫��ѭ������ĳ���(���Ʊ�ͷ���)
	DblNode<Type> * p = first��rLink;
	int count = 0;
	while (p != first)
	{
		p = p��rLink;  count++;
	}
	return count;
}

template <class Type>
int DblList<Type>::First() {
	if (!IsEmpty())
	{
		current = first��rLink;  return 1;
	}
	current = NULL;  return 0;
}

template <class Type>
int DblList<Type>::Next() {
	if (current��rLink == first)
	{
		current = NULL;  return 0;
	}
	current = current��rLink;  return 1;
}

template <class Type>
int DblList<Type>::Prior() {
	if (current��lLink == first)
	{
		current = NULL;  return 0;
	}
	current = current��lLink;  return 1;
}