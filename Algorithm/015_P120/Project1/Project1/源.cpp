#include<iostream>

using namespace std;

template <typename T>
void swap(T a[], int m, int n)
{
	T temp = a[m];
	a[m] = a[n];
	a[n] = temp;
}

template <typename T3>
T3 select(T3 a[], int m, int n, int i)//Ëæ»ú
{
	if (m == n)
	{
		return a[m];
	}
	int tmp = rand() % (n - m + 1) + m;//Ëæ»úÊý
	swap<T3>(a, m, tmp);
	T3 t = a[m];
	int p = m;
	int q = n + 1;
	while (true)
	{
		for (p++; p <= n && a[p] < t; p++);
		for (q--; q >= m && a[q] > t; q--);
		if (p > q)
			break;
		swap<T3>(a, p, q);
	}
	swap<T3>(a, m, q);
	if (i == q+1)
		return a[q];
	else if (i < q+1)
		select(a, m, q - 1, i);
	else
		select(a, q + 1, n, i);
}

void main()
{
	int a[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	cout << select<int>(a, 0, 7, 5);
	getchar();
}
