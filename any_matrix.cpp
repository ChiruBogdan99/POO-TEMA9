
#include "any_matrix.h"

any_matrix::~any_matrix()
{

}

any_matrix& any_matrix::operator=(any_matrix B)
{
	this->setCols(B.getCols());
	this->setRows(B.getRows());

	for (int i = 0; i < B.getRows(); i++)
		for (int j = 0; j < B.getCols(); j++)
			this->value[i][j] = B.value[i][j];

	return *this;
}

istream& operator>>(istream& in, any_matrix& B)
{
	for (int i = 0; i < B.getRows(); i++)
		for (int j = 0; j < B.getCols(); j++)
			in >> B.value[i][j];
	return in;
}

ostream& operator<<(ostream& out, any_matrix B)
{
	for (int i = 0; i < B.getRows(); i++)
	{
		for (int j = 0; j < B.getCols(); j++)
			out << B.value[i][j] << " ";
		cout << endl;
	}
	return out;
}

void any_matrix::getCofactor(Complex** B, Complex** temp, int row, int col, int n)
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

Complex any_matrix::determinant(Complex** B, int n)
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

Complex any_matrix::determinant()
{
	if (this->getRows() == this->getCols())
		return determinant(this->value, this->getRows());
	else
	{
		cout << "Error! (cols != rows)" << endl;
		return NULL;
	}
}

bool any_matrix::isDiagonal()
{
	bool ok = true;
	Complex nul(0, 0);
	for (int i = 0; i < this->getRows(); i++)
		for (int j = 0; j < this->getCols(); j++)
			if ((i != j) && (value[i][j] != nul))
				ok = false;
	return ok;
}
