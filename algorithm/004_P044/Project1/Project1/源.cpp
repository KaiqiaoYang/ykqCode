#include<iostream>

using namespace std;

const int N = 2;

struct matrix
{
	int mymatrix[N][N];
};

matrix squareMatrixMultiply(matrix a, matrix b)
{
	matrix c;

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	{
		c.mymatrix[i][j] = 0;
		for (int k = 0; k < N; ++k)
		{
			c.mymatrix[i][j] += a.mymatrix[i][k] * b.mymatrix[k][j];
		}
	}
	return c;
}

void main()
{
	matrix a, b, c;
	int n = 1;
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	{
		a.mymatrix[i][j] = b.mymatrix[i][j] = n;
		n++;
	}
	c = squareMatrixMultiply(a, b);
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	{
		cout << c.mymatrix[i][j] << " ";
	}
	getchar();
}