#include<iostream>

using namespace std;

struct MyStruct
{
	int* array;
};

MyStruct insertionSort(MyStruct myArr);

int N = 10;

void main()
{
	MyStruct myArr;
	myArr.array = (int*)malloc(N*sizeof(int));

	int n = 0;
	for (int i = 9; i >= 0; --i)
	{
		myArr.array[n] = i;
		n++;
	}
	insertionSort(myArr);
	for (int i = 0; i < 10; ++i)
	{
		cout << myArr.array[i]<<" ";
	}
	delete myArr.array;
	getchar();
}


MyStruct insertionSort(MyStruct myArr)
{
	for (int i = 1; i < N; ++i)
	{
		int k = i - 1;
		int tmp = myArr.array[i];
		while (tmp<myArr.array[k])
		{
			myArr.array[k + 1] = myArr.array[k];
			k--;
		}
		myArr.array[k + 1] = tmp;
	}
	return myArr;
}

