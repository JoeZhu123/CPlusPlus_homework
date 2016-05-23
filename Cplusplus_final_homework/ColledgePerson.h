#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "ColledgePerson.h"
#include "LinkList.h"

using namespace std;
using std::string;

//Simple base class : ColledgePerson
class ColledgePerson
{
public:
	string m_name;
	int m_age;
	int m_ID_Number;
	string m_gender;
	ColledgePerson *next;
	ColledgePerson *pre;
	ColledgePerson(unsigned int id = 0, const string & name = "none", string gender = "none", unsigned int age = 0);
	~ColledgePerson();
	virtual void InsertData();
	virtual void Information_P();	
};

//Simple derived class : undergraduate
class undergraduate : public ColledgePerson
{
public:
	undergraduate(unsigned int id = 0, const string & name = "none", string gender = "none", unsigned int age = 0, int grade = 0, const string & major = "none");
	undergraduate(ColledgePerson & CP,int grade = 0, const string & major = "none");
	~undergraduate();
	virtual void InsertData();
	virtual void Information_P();

private:
	int m_grade;
	string m_major;
};

//Simple derived class : postgraduate
class postgraduate : public ColledgePerson
{
public:
	postgraduate(unsigned int id = 0, const string & name = "none", string gender = "none", unsigned int age = 0,int scholarship = 0,const string & advisor = "none");
	postgraduate(ColledgePerson & CP, int scholarship = 0, const string & advisor = "none");
	~postgraduate();
	virtual void InsertData();
	virtual void Information_P();
private:
	int m_scholarship;
	string m_advisor;
};

//Simple derived class : workers
class workers : public ColledgePerson
{
public:
	workers(unsigned int id = 0, const string & name = "none", string gender = "none", unsigned int age = 0, int salary = 0, const string & post = "none");
	workers(ColledgePerson & CP, int salary = 0, const string & post = "none");
	~workers();
	virtual void InsertData();
	virtual void Information_P();

private:
	int m_salary;
	string m_post;
};
