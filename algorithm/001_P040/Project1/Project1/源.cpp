#include<iostream>

using namespace std;

int* FindMaxCrossingArray(int* mArray, int low, int mid, int high);

void main()
{
	int A[10] = { -1, -2, 3, 4, 5, 6, 7, 8, -9, 10 };
	int* result = FindMaxCrossingArray(A,0,4,9);
	cout << result[0] << endl << result[1] << endl << result[2] << endl;
	delete result;
	getchar();
}

int* FindMaxCrossingArray(int* mArray,int low,int mid,int high)
{
	int maxLeft;
	int leftSum = 0;
	int sum1 = 0;
	for (int i = mid; i >= low; i--)
	{
		sum1 = sum1 + mArray[i];
		if (sum1 > leftSum)
		{
			leftSum = sum1;
			maxLeft = i + 1;
		}
	}

	int maxRight;
	int rightSum = 0;
	int sum2 = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum2 = sum2 + mArray[i];
		if (sum2 > rightSum)
		{
			rightSum = sum2;
			maxRight = i + 1;
		}
	}

	int* temp = new int[3];
	temp[0] = maxLeft;
	temp[1] = maxRight;
	temp[2] = leftSum + rightSum;

	return temp;
}