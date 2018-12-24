#include<iostream>

using namespace std;

int* findMaxCrossingArray(int* mArray, int low, int mid, int high);
int* findMaxSubarray(int* mArray1, int low, int high);

void main()
{
	int A[10] = { -1, -2, 3, 4, 5, 6, 7, 8, -9, 10 };
	int* result = findMaxSubarray(A, 4, 9);
	cout << result[0] << endl << result[1] << endl << result[2] << endl;
	delete result;
	getchar();
}

int* findMaxCrossingArray(int* mArray, int low, int mid, int high)
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

int* temp = new int[3];
int* leftMax = new int[3];
int* rightMax = new int[3];
int* crossMax = new int[3];

int* findMaxSubarray(int* mArray1, int low, int high)
{
	if (high == low)
	{
		temp[0] = low;
		temp[1] = high;
		temp[2] = mArray1[low];
		return temp;
	}
	else
	{
		int mid = (low + high) / 2;

		leftMax[0] = low;
		leftMax[1] = mid;
		leftMax[2] = 0;
		for (int i = low; i <= mid; ++i)
		{
			leftMax[2] += mArray1[i];
		}

		rightMax[0] = low;
		rightMax[1] = mid;
		rightMax[2] = 0;
		for (int i = mid; i <= high; ++i)
		{
			rightMax[2] += mArray1[i];
		}

		leftMax = findMaxSubarray(mArray1, low, mid);
		rightMax = findMaxSubarray(mArray1, mid, high);
		crossMax = findMaxCrossingArray(mArray1, low, mid, high);
	}

	if (leftMax[2] >= rightMax[2] && leftMax[2] >= crossMax[2])
	{
		return leftMax;
	}
	else if (rightMax[2] >= leftMax[2] && rightMax[2] >= crossMax[2])
	{
		return rightMax;
	}
	else
	{
		return crossMax;
	}
}