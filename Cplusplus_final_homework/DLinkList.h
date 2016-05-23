#pragma once
#include "stdafx.h"
#include <iostream>
#include "DLinkList.h"
using namespace std;

template <class Type> class DblList;

template <class Type> class DblNode {
	friend class DblList<Type>;
private:
	Type data;                                      //Êý¾Ý
	DblNode<Type> *lLink, *rLink;   //Ö¸Õë
	DblNode(Type value,
		DblNode<Type> *left, *right) :
		data(value), lLink(left), rLink(right) { }
	DblNode(Type value) : data(value),
		lLink(NULL), rLink(NULL) { }
};

template <class Type> class DblList {
public:
	DblLIst(Type uniqueVal);
	~DblList();
	int Length() const;
	int IsEmpty()
	{
		return first¡úrlink == first;
	}
	int Find(const Type & target);
	Type getData() {} const;
	void Firster() { current = first; }
	int First();
	int Next();
	int Prior();
	int operator ! ()
	{
		return current != NULL;
	}
	void Insert(const Type & value);
	void Remove();
private:
	DblNode<Type> *first, *current;
};

