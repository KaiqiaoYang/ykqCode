#include<iostream>

using namespace std;

void main()
{
	//Ь�ӵĳ���
	int shoeSize[] = { 36, 34, 40, 38, 36, 37, 38 };
	//��������Ь�ӵķ�Χ��30-40��Ҳ����������Ҫ11��Ͱ������Ͱ����
	int arrs[11] = { 0 };

	//��Ь�ӵĳ�����䵽Ͱ��
	for (int i = 0; i < sizeof(shoeSize) / sizeof(shoeSize[0]); i++) {
		//
		int size = shoeSize[i] - 30;
		//ÿ������ÿ����һ�Σ��ͱ��һ�Σ�������һ
		arrs[size] = arrs[size] + 1;
	}
	//�����ж�arrs[0]~arrs[10]
	for (int i = 0; i < 11; i++) {
		//���ּ��δ�ӡ���Σ�����֪��arrs[i]��Ӧ���ݴ�����ֵĴ�����
		for (int j = 0; j < arrs[i]; j++) {
			int size = i + 30;
			cout << size << "\t";
		}
	}
	getchar();
}