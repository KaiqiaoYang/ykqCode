#include<iostream>
#include<random>

using namespace std;

void main()
{
	const int n = 10;
	default_random_engine e;
	uniform_int_distribution<unsigned> u(1, n*n);
	int A[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int P[n] = {};
	for (int i = 0; i < n; ++i)
	{
		P[i] = u(e);
	}

	for (int i = 0; i < n-1;i++)
		for (int j = 0; j < n-i-1; j++)
		{
			if (P[j] > P[j + 1])
			{
				int tmp = P[j + 1];
				P[j + 1] = P[j];
				P[j] = tmp;

				tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
			}
		}

	for (int i = 0; i < 10; ++i)
	{
		cout << P[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << A[i] << "\t";
	}
	getchar();
}