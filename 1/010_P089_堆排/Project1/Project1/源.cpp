#include<iostream>
using namespace std;

#define left(x) 2*x+1;
#define right(x) 2*(x+1);

void MaxHeapify(int* a, int i, int low, int high)//维护最大堆
{
	int l = left(i);
	int r = right(i);
	int largest;
	int tmp;

	if (l <= high && a[l] > a[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}

	if (r <= high && a[r] > a[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		tmp = a[largest];
		a[largest] = a[i];
		a[i] = tmp;
		MaxHeapify(a, largest, low, high);
	}
}

void BuildMaxHeap(int* a, int length)//构建最大堆
{
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(a, i, 0, length - 1);
	}
}

void HeapSort(int* a, int length)//堆排序
{
	BuildMaxHeap(a, length);
	int tmp;
	for (int i = length - 1; i >= 1; i--)
	{
		tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		MaxHeapify(a, 0, 0, i - 1);
	}
}

void main()
{
	int a[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	HeapSort(a, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i] << "\t";
	}
	getchar();
}