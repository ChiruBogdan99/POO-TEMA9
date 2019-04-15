#pragma once
#include "matrix.h"

using namespace std;

class any_matrix : protected matrix
{
public:
	any_matrix() : matrix() {};
	any_matrix(const int rows, const int cols) :matrix(rows, cols) {};
	any_matrix(const any_matrix& B) : matrix(B) {};
	~any_matrix();

	void getCofactor(Complex**, Complex**, int, int, int);
	Complex determinant(Complex** B, int n);
	Complex determinant();
	bool isDiagonal();

	any_matrix& operator=(any_matrix B);

	friend istream& operator>>(istream&, any_matrix&);
	friend ostream& operator<<(ostream&, any_matrix);
};