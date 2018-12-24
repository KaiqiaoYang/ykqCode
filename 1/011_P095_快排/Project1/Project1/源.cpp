#include<iostream>

using namespace std;

template <typename T>
void swap(T a[], int m, int n)
{
	T temp = a[m];
	a[m] = a[n];
	a[n] = temp;
}

template <typename T1>
void sort1(T1 a[], int m, int n)//单边
{
	if (m > n)
	{
		return;
	}
	int p = m;
	T1 t = a[m];
	for (int i = m + 1; i <= n; i++)
	{
		if (a[i] < t)
		{
			swap<T1>(a, ++p, i);
		}
	}
	swap<T1>(a, m, p);
	sort1(a, m, p - 1);
	sort1(a, p + 1, n);
}

template <typename T2>
void sort2(T2 a[], int m, int n)//双边
{
	if (m > n)
	{
		return;
	}
	T2 t = a[m];
	int p = m;
	int q = n + 1;
	while (true)
	{
		for (p++; p <= n && a[p] < t; p++);
		for (q--; q >= m && a[q] > t; q--);
		if (p > q)
			break;
		swap<T2>(a, p, q);
	}
	swap<T2>(a, m, q);
	sort2(a, m, q - 1);
	sort2(a, q + 1, n);
}

template <typename T3>
void sort3(T3 a[], int m, int n)//随机
{
	if (m > n)
	{
		return;
	}
	int tmp = rand() % (n - m + 1) + m;//随机数
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
	sort3(a, m, q - 1);
	sort3(a, q + 1, n);
}

void main()
{
	int a[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	sort1<int>(a, 0, 7);
	//sort2<int>(a, 0, 7);
	//sort3<int>(a, 0, 7);
	for (int i = 0; i < 8; i++)
		cout << a[i] << ",";
	getchar();
}

