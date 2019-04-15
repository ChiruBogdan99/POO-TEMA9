
#include "matrix.h"


matrix::matrix()
{
	rows = 0;
	cols = 0;
	value = new Complex*;
	value[0] = new Complex;
	Complex x(0, 0);
	value[0][0] = x;
}

matrix::matrix(const int rows, const int cols)
{
	this->rows = rows;
	this->cols = cols;

	this->value = new Complex*[rows];
	for (int i = 0; i < rows; i++)
		this->value[i] = new Complex[cols];
}

matrix::matrix(const matrix& B)
{
	this->rows = B.rows;
	this->cols = B.cols;

	this->value = new Complex*[rows];
	for (int i = 0; i < rows; i++)
	{
		this->value[i] = new Complex[cols];
		for (int j = 0; j < cols; j++)
			this->value[i][j] = B.value[i][j];
	}
}

matrix::~matrix()
{
	delete this->value;
}

int matrix::getRows()
{
	return rows;
}
int matrix::getCols()
{
	return cols;
}
void matrix::setRows(int x)
{
	rows = x;
}
void matrix::setCols(int x)
{
	cols = x;
}
