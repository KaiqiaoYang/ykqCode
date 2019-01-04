#include<iostream>

using namespace std;

void main()
{
	//鞋子的尺码
	int shoeSize[] = { 36, 34, 40, 38, 36, 37, 38 };
	//由于我们鞋子的范围是30-40，也就是我们需要11个桶，定义桶数据
	int arrs[11] = { 0 };

	//把鞋子的尺码分配到桶里
	for (int i = 0; i < sizeof(shoeSize) / sizeof(shoeSize[0]); i++) {
		//
		int size = shoeSize[i] - 30;
		//每个尺码每出现一次，就标记一次，数量加一
		arrs[size] = arrs[size] + 1;
	}
	//依次判断arrs[0]~arrs[10]
	for (int i = 0; i < 11; i++) {
		//出现几次打印几次，我们知道arrs[i]对应数据代表出现的次数。
		for (int j = 0; j < arrs[i]; j++) {
			int size = i + 30;
			cout << size << "\t";
		}
	}
	getchar();
}