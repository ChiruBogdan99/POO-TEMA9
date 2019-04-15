
#include "square_matrix.h"

square_matrix::~square_matrix()
{

}

square_matrix& square_matrix::operator=(square_matrix B)
{
	this->setCols(B.getCols());
	this->setRows(B.getRows());

	for (int i = 0; i < B.getRows(); i++)
		for (int j = 0; j < B.getCols(); j++)
			this->value[i][j] = B.value[i][j];

	return *this;
}

istream& operator>>(istream& in, square_matrix& B)
{
	for (int i = 0; i < B.getRows(); i++)
		for (int j = 0; j < B.getCols(); j++)
			in >> B.value[i][j];
	return in;
}

ostream& operator<<(ostream& out, square_matrix B)
{
	for (int i = 0; i < B.getRows(); i++)
	{
		for (int j = 0; j < B.getCols(); j++)
			out << B.value[i][j] << " ";
		out << endl;
	}
	return out;
}

void square_matrix::getCofactor(Complex** B, Complex** temp, int row, int col, int n)
{
	int i = 0, j = 0;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (r != row && c != col)
			{
				temp[i][j++] = B[r][c];

				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

Complex square_matrix::determinant(Complex** B, int n)
{
	Complex D(0, 0);

	if (n == 1)
		return B[0][0];

	Complex** temp;
	temp = new Complex*[n];
	for (int i = 0; i < n; i++)
		temp[i] = new Complex[n];

	int sign = 1;

	for (int f = 0; f < n; f++)
	{
		getCofactor(B, temp, 0, f, n);
		D += B[0][f] * sign  * determinant(temp, n - 1);

		sign = -sign;
	}

	return D;
}

Complex square_matrix::determinant()
{
	return determinant(this->value, this->dim);
}

bool square_matrix::isDiagonal()
{
	bool ok = true;
	Complex nul(0, 0);
	for (int i = 0; i < this->getRows(); i++)
		for (int j = 0; j < this->getCols(); j++)
			if ((i != j) && (value[i][j] != nul))
				ok = false;
	return ok;
}
