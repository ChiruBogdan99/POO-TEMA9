#pragma once
#include "Complex.h"

using namespace std;

class matrix
{
	int rows, cols;
protected:
	Complex** value;
public:
	matrix();
	matrix(const int, const int);
	matrix(const matrix&);
	virtual ~matrix();

	virtual void getCofactor(Complex**, Complex**, int, int, int) = 0;
	virtual Complex determinant(Complex** B, int n) = 0;
	virtual bool isDiagonal() = 0;

	int getRows();
	int getCols();
	void setRows(int x);
	void setCols(int x);
};

