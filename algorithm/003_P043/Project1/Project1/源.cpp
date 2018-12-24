#include<iostream>

using namespace std;

const int N = 2;
//int** squareMatrixMultiply(int(*a)[N], int(*b)[N], int n);
//
//void main()
//{
//	int a[][N] = { { 1, 2 }, { 3, 4 } };
//	int b[][N] = { { 1, 2 }, { 3, 4 } };
//	int** c = (int**)malloc(N*sizeof(int*));
//	for (int i = 0; i < N; i++)
//	{
//		c[i] = (int*)malloc(N*sizeof(int));
//	}
//	c = squareMatrixMultiply(a, b, N);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N;++j)
//		cout << c[i][j];
//	}
//	delete c;
//	getchar();
//}
//
//int** squareMatrixMultiply(int(*a)[N], int(*b)[N],int n)
//{
//	int c[][N] = {0};//初始化全为0
//	for (int i = 0; i < n;++i)
//		for (int j = 0; j < n; ++j)
//		{
//			c[i][j] = 0;
//			for (int k = 0; k < n; ++k)
//			{
//				c[i][j] += a[i][k] + b[k][j];
//			}
//		}
//
//		int** arr = (int**)malloc(N*sizeof(int*));//重点
//		for (int i = 0; i < N; i++)
//		{
//			arr[i] = (int*)malloc(N*sizeof(int));//重点
//			for (int j = 0; j < N; j++)
//			{
//				arr[i][j] = c[i][j];
//			}
//		}
//		return arr;
//}


struct matrix
{
	int mymatrix[N][N];
};

matrix squareMatrixMultiply(matrix a, matrix b)
{
	matrix c;

	for (int i = 0; i < N;++i)
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