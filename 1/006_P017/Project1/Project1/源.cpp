#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

struct MyStruct
{
	vector<int>A;
};

MyStruct Merge(MyStruct mystruct, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int>L1;
	vector<int>L2;
	for (int i = 0; i < n1; i++)
	{
		//L1[i] = mystruct.A[p+i];
		L1.push_back(mystruct.A[p + i]);
	}
	for (int i = 0; i < n2; i++)
	{
		//L2[i] = mystruct.A[q+i+1];
		L2.push_back(mystruct.A[q + i + 1]);
	}
	sort(L1.begin(), L1.end());
	sort(L2.begin(), L2.end());
	L1.push_back(INT_MAX);
	L2.push_back(INT_MAX);
	int i = 0;
	int j = 0;
	for (int k = 0; k < r - p + 1; k++)
	{
		if (L1[i] <= L2[j])
		{
			mystruct.A[k] = L1[i];
			i++;
		}
		else
		{
			mystruct.A[k] = L2[j];
			j++;
		}
	}
	return mystruct;
}

void main()
{
	MyStruct mystruct;
	mystruct.A = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	mystruct = Merge(mystruct,0,3,9);
	for (int i = 0; i <= 9; i++)
	{
		cout << mystruct.A[i] << " ";
	}
	getchar();
}