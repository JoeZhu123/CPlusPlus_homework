// Cplusplus_homework3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

class CMatrix
{
	int m_Rows;
	int m_Cols;
	float *m_P;
public:
	CMatrix(int i = 0, int j = 0);
	~CMatrix();
	void Init();
	void Show();
	CMatrix operator+(CMatrix &rc);
	CMatrix operator*(CMatrix &rc);
	CMatrix operator-(CMatrix &rc);
	CMatrix & operator=(CMatrix &rc);
	CMatrix(CMatrix &rc);
};
CMatrix::CMatrix(int i, int j)
{
	int m, n;
	m_P = 0;
	if (i<0 || j<0)
		return;
	m_Rows = i;
	m_Cols = j;
	m_P = new float[m_Rows*m_Cols];
	for (m = 0; m<i; m++)
		for (n = 0; n<j; n++)
			m_P[m*m_Cols + n] = 0;
}
void CMatrix::Init()
{
	int i, j;
	for (i = 0; i<m_Rows; i++)
		for (j = 0; j<m_Cols; j++)
		{
			cout << "请输入矩阵元素[" << i << "][" << j << "]:";
			cin >> m_P[i*m_Cols + j];
		}
}
void CMatrix::Show()
{
	int i, j;
	for (i = 0; i<m_Rows; i++)
	{
		for (j = 0; j<m_Cols; j++)
			cout << "  " << m_P[i*m_Cols + j];
		cout << endl;
	}
}
CMatrix CMatrix::operator*(CMatrix &rc)
{
	int i, j, k;
	if (m_Cols != rc.m_Rows)
		return CMatrix();
	CMatrix r(m_Rows, rc.m_Cols);
	for (i = 0; i<m_Rows; i++)
		for (j = 0; j<rc.m_Cols; j++)
			for (k = 0; k<m_Cols; k++)
				r.m_P[i*rc.m_Cols + j] += m_P[i*m_Cols + k] * rc.m_P[k*rc.m_Cols + j];
	return r;
}
CMatrix CMatrix::operator+(CMatrix &rc)
{
	if (m_Rows != rc.m_Rows || m_Cols != rc.m_Cols)
		return CMatrix();
	CMatrix r(m_Rows, m_Cols);
	for (int i = 0; i<m_Rows; i++)
		for (int j = 0; j<rc.m_Cols; j++)
			r.m_P[i*m_Cols + j] = m_P[i*m_Cols + j] + rc.m_P[i*m_Cols + j];
	return r;
}
CMatrix CMatrix::operator-(CMatrix &rc)
{
	if (m_Rows != rc.m_Rows || m_Cols != rc.m_Cols)
		return CMatrix();
	CMatrix r(m_Rows, m_Cols);
	for (int i = 0; i<m_Rows; i++)
		for (int j = 0; j<rc.m_Cols; j++)
			r.m_P[i*m_Cols + j] = m_P[i*m_Cols + j] - rc.m_P[i*m_Cols + j];
	return r;
}

CMatrix & CMatrix::operator=(CMatrix &rc)
{
	if (m_P != 0)
		delete m_P;
	m_Rows = rc.m_Rows;
	m_Cols = rc.m_Cols;
	m_P = new float[m_Rows*m_Cols];
	for (int i = 0; i<m_Rows*m_Cols; i++)
		m_P[i] = rc.m_P[i];
	return *this;
}
CMatrix::CMatrix(CMatrix &rc)
{
	int i, j;
	m_Rows = rc.m_Rows;
	m_Cols = rc.m_Cols;
	m_P = new float[m_Rows*m_Cols];
	for (i = 0; i<m_Rows; i++)
		for (j = 0; j<m_Cols; j++)
			m_P[i*m_Cols + j] = rc.m_P[i*m_Cols + j];
}
CMatrix::~CMatrix()
{
	if (m_P != 0)
		delete[]m_P;
}
int main(int argc, char* argv[])
{
	cout << "第一个矩阵" << endl;
	CMatrix c(2, 2);
	c.Init();
	cout << "第二个矩阵" << endl;
	CMatrix b(2, 3);
	b.Init();
	cout << "第三个矩阵" << endl;
	CMatrix d(2, 3);
	d.Init();

	cout << "第一个矩阵是:" << endl;
	c.Show();
	cout << "第二个矩阵是:" << endl;
	b.Show();
	cout << "第三个矩阵是:" << endl;
	d.Show();
	CMatrix r;
	r = c*b;
	cout << "第一和第二个矩阵的相乘后的矩阵是:" << endl;
	r.Show();
	CMatrix k;
	k = b + d;
	cout << "第二和第三个矩阵的相加后的矩阵是:" << endl;
	k.Show();
	CMatrix p;
	p = b - d;
	cout << "第二和第三个矩阵的相减后的矩阵是:" << endl;
	p.Show();
	return 0;
}

