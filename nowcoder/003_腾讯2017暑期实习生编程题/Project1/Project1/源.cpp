/*
	˼·��
    1.������
         ������������������֮��������������������ͬ��ֱ��������
             ���Ϊ���������� = ����С���� = ��n * (n-1))/2;(�������)
    2.ͳ��������ÿ�����ֵĸ����������õ�map��
    3.�������С����
        3.1.���������û���ظ����֣�˵����С�Ϊ0����С��϶��������������������Ĳ�
            ��ˣ�����һ�����飬���㲢ͳ����С�
        3.2.������������ظ����֣�˵����С����0����ʱ������һ��map�����ָ�����Ϊ0��
            ���ֻ������С��0�����ù�ʽ���㼴��
    4.�����������
        ֻ��һ����������ֵ����Сֵ��������ϣ������ֵ���� * ��Сֵ����
    �㷨���Ӷȣ�����O(nlogn), ͳ��O(n)
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void main()
{
	int n;
	while (cin>>n)
	{
		if (n < 2)
		{
			cout << 0 << " " << 0 << endl;
		}
		if (n == 2)
		{
			cout << 1 << " " << 1 << endl;
		}
		else
		{
			vector<int>data;
			for (int i = 1; i <= n; ++i)
			{
				int tmp;
				cin >> tmp;
				data.push_back(tmp);
			}
			sort(data.begin(),data.end());

			//mapͳ�Ƽ�����ÿ�����ֵĸ��������˺ܾõ�bug������
			map<int, int>dataMap;
			int mark = 0;
			int n1;
			int* dataTmp = new int[];
			for (int i = 0; i < n; ++i)
			{
				int j;
				for (j = 0; j < dataMap.size(); ++j)
				{
					if (dataTmp[j] == data[i])
					{
						dataMap[dataTmp[j]]++;
						mark = 1;
						continue;
					}
					/*else
					{
						dataMap.insert(pair<int,int>(data[i],1));
						continue;
					}*/
				}
				if (mark == 0)
				{
					dataMap.insert(pair<int, int>(data[i], 1));
					dataTmp[j] = data[i];
					n1 = j;
				}
				else
				{
					mark = 0;
				}
			}

			if (data[0] == data[n - 1])
				cout << n*(n - 1) / 2 << " " << n*(n - 1) / 2 << endl;
			else
			{
				if ((dataMap.size() == n))
				{
					int minNum = 1;
					int min = data[1] - data[0];
					for (int i = 2; i < n; ++i)
					{
						if ((data[i] - data[i - 1]) < min)
						{
							min = data[i] - data[i - 1];
							minNum = 1;
						}
						else if (data[i]-data[i-1] == min)
						{
							minNum++;
						}
					}
					cout << minNum << " " << 1 << endl;
				}
				else
				{
					int minNum = 0;
 					for (int i = 0; i < dataMap.size(); ++i)
					{
						if (dataMap[dataTmp[i]]>1)
						{
							minNum += (dataMap[dataTmp[i]] * (dataMap[dataTmp[i]] - 1)) / 2;
						}
					}
					int maxNum = dataMap[dataTmp[0]] * dataMap[dataTmp[n1]];
					cout << minNum << " " << maxNum << endl;
				}
			}
		}
	}
}