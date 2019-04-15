#pragma once
#include "matrix.h"

using namespace std;

class square_matrix : protected matrix
{
	int dim;
public:
	square_matrix() : matrix() {};
	square_matrix(const int dim) :matrix(dim, dim) { this->dim = dim; };
	square_matrix(const square_matrix& B) : matrix(B) {};
	~square_matrix();

	void getCofactor(Complex**, Complex**, int, int, int);
	Complex determinant(Complex** B, int n);
	Complex determinant();
	bool isDiagonal();

	square_matrix& operator=(square_matrix B);

	friend istream& operator>>(istream&, square_matrix&);
	friend ostream& operator<<(ostream&, square_matrix);
};