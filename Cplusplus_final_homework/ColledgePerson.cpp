#include "stdafx.h"
#include <iostream>
#include <string>
#include "ColledgePerson.h"
#include "LinkList.h"

using namespace std;

//Simple base class : ColledgePerson
ColledgePerson::ColledgePerson(unsigned int id, const string & name , string gender, unsigned int age):m_ID_Number(id),m_name(name),m_gender(gender),m_age(age)
{
	m_name = name;
	m_age = age;
	m_ID_Number = id;
	m_gender = gender;
}

ColledgePerson::~ColledgePerson()
{

}

void ColledgePerson::InsertData()
{
	cout << "Input ID Number: " << endl;
	cin >> m_ID_Number;
	cout << "Input Name: " << endl;
	cin >> m_name;
	cout << "Input Gender:" << endl;
	cin >> m_gender;
	cout << "Input Age: " << endl;
	cin >> m_age;
}

void ColledgePerson::Information_P()
{
	cout << "=======================" << endl;
	cout << "ID Number: " << m_ID_Number << endl;
	cout << "Name: " << m_name << endl;
	if (m_gender == "male")
	{
		cout << "Gender: Male" << endl;
	}
	else
	{
		cout << "Gender: Female" << endl;
	}
	cout << "Age: " << m_age << endl;
}


//Simple derived class : undergraduate
undergraduate::undergraduate(unsigned int id, const string & name, string gender, unsigned int age, int grade, const string & major):ColledgePerson(id,name,gender,age)
{
	m_grade = grade;
	m_major = major;
}

undergraduate::undergraduate(ColledgePerson & CP, int grade, const string & major):ColledgePerson(CP), m_grade(grade), m_major(major)
{
	m_grade = grade;
	m_major = major;
}
undergraduate::~undergraduate()
{

}

void undergraduate::InsertData()
{
	ColledgePerson::InsertData();//input base information
	cout << "Input Major: " << endl;
	cin >> m_major;
	cout << "Input Grade: " << endl;
	cin >> m_grade;
}
void undergraduate::Information_P()
{
	ColledgePerson::Information_P();//display base information
	cout << "Major: " << m_major << endl;
	cout << "Grade: " << m_grade << endl;
}

//Simple derived class : postgraduate
postgraduate::postgraduate(unsigned int id, const string & name, string gender, unsigned int age, int scholarship, const string & advisor) :ColledgePerson(id, name, gender, age)
{
	m_scholarship = scholarship;
	m_advisor = advisor;
}
postgraduate::postgraduate(ColledgePerson & CP, int scholarship, const string & advisor) : ColledgePerson(CP), m_scholarship(scholarship), m_advisor(advisor)
{
	m_scholarship = scholarship;
	m_advisor = advisor;
}
postgraduate::~postgraduate()
{
}

void postgraduate::InsertData()
{
	ColledgePerson::InsertData();//input base information
	cout << "Input Scholarship: " << endl;
	cin >> m_scholarship;
	cout << "Input Advisor: " << endl;
	cin >> m_advisor;
}
void postgraduate::Information_P()
{
	ColledgePerson::Information_P();//display base information
	cout << "Scholarship: " << m_scholarship << endl;
	cout << "Advisor: " << m_advisor << endl;
}
//Simple derived class : workers
workers::workers(unsigned int id, const string & name, string gender, unsigned int age, int salary, const string & post) :ColledgePerson(id, name, gender, age)
{
	m_salary = salary;
	m_post = post;
}
workers::workers(ColledgePerson & CP, int salary, const string & post) : ColledgePerson(CP), m_salary(salary), m_post(post)
{
	m_salary = salary;
	m_post = post;
}
workers::~workers()
{

}

void workers::InsertData()
{
	ColledgePerson::InsertData();//input base information
	cout << "Input Salary: " << endl;
	cin >> m_salary;
	cout << "Input Post: " << endl;
	cin >> m_post;
}
void workers::Information_P()
{
	ColledgePerson::Information_P();//display base information
	cout << "Salary: " << m_salary << endl;
	cout << "Post: " << m_post << endl;
}
