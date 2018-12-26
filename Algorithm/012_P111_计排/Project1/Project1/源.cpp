#include<iostream>

using namespace std;

//template<class T>
//int length(T& arr)
//{
//	//指针类型没办法求数组长度
//	cout << sizeof(arr[0]) << endl;
//	cout << sizeof(arr) << endl;
//	getchar();
//	return sizeof(arr) / sizeof(arr[0]);
//
//	//return end(arr) - begin(arr);
//}

void countSort(int* a, int n)//计数排序
{
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		else if (a[i] > max)
			max = a[i];
	}
	int bLength = max - min + 2;
	int* b = new int[bLength];
	for (int i = 0; i<n; i++)
	{
		(b[a[i] - min + 1])++;
	}
	for (int i = 0; i < bLength; i++)
	{
		b[i + 1] += b[i];
	}
	int* c = new int[n];
	for (int i = 0; i<n; i++)
	{
		c[b[a[i] - min]++] = a[i];
	}
	for (int i = 0; i<n; i++)
	{
		a[i] = c[i];
	}
	delete[] b;
	delete[] c;
}

void main()
{
	int a[] = { 1, 3, 4, 3, 2, 4, 1, 2, 3, 4 };
	countSort(a, 10);
	for (int i = 1; i < 10; i++)
	{
		cout << a[i]<<" ,";
	}
	cout << endl;
	getchar();
}

