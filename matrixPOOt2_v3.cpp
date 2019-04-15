
#include <iostream>
#include "any_matrix.h"
#include "square_matrix.h"

using namespace std;

int main()
{
	square_matrix m(2);
	cin >> m;
	cout << m << endl;
	cout << m.determinant() << endl;
	if (m.isDiagonal() == true)
		cout << "Diagonala";
	else
		cout << "Nu e diagonala";
}
