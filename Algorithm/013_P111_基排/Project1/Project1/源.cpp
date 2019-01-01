#include<iostream>
#include<assert.h>

using namespace std;

int getMaxDidit(int* arr, size_t n)
{
	assert(arr);
	int digit = 1;
	int base = 10;
	for (size_t i = 1; i < n; i++)
	{
		while (arr[i]>=base)
		{
			digit++;
			base *= 10;
		}
	}
	return digit;
}

void LSDSort(int* arr, size_t n)
{
	assert(arr);
	int base = 1;
	int digit = getMaxDidit(arr, n);
	int* tmp = new int[n];
	while (digit--)
	{
		int count[10] = { 0 };
		//统计某一位相同数字的个数
		for (size_t i = 0; i < n; i++)
		{
			int index = arr[i] / base % 10;
			count[index]++;
		}
		int start[10] = { 0 };
		for (size_t i = 1; i < n; i++)
		{
			start[i] = count[i - 1] + start[i - 1];
		}
		//初始化tmp数组
		memset(tmp, 0, n*sizeof(int));
		//排序
		for (size_t i = 0; i < n; i++)
		{
			int index = arr[i] / base % 10;
			tmp[start[index]++] = arr[i];
		}
		//copy
		memcpy(arr, tmp, n*sizeof(int));
		base *= 10;
	}
	delete[] tmp;
}



void main()
{
	
	int arr[10] = { 3, 4, 53, 34, 58, 975, 547, 672, 783, 239 };
	LSDSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	getchar();
}