#include<iostream>
#include<random>

using namespace std;

void main()
{
	const int n = 10;
	int A[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < 10; ++i)
	{
		default_random_engine e;
		uniform_int_distribution<unsigned> u(i, n-1);
		int temp = u(e);
		int tmp;
		tmp = A[i];
		A[i] = A[temp];
		A[temp] = tmp;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << A[i] << "\t";
	}
	getchar();
}