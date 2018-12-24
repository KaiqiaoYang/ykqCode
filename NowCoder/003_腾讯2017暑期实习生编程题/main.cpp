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
            continue;
		}
		if (n == 2)
		{
			cout << 1 << " " << 1 << endl;
            continue;
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
			if (data[0] == data[n - 1])
            {
				cout << n*(n - 1) / 2 << " " << n*(n - 1) / 2 << endl;
                continue;
            }

			//mapͳ�Ƽ�����ÿ�����ֵĸ��������˺ܾõ�bug������
			map<int, int>dataMap;
			int mark = 0;
			for (int i = 0; i < data.size(); ++i)
            {
                if (dataMap.find(data[i]) != dataMap.end())
                {
                    dataMap[data[i]]++;
                    mark = 1;
                }
                else
                {
                    dataMap.insert(pair<int,int>(data[i],1));
                }
            }

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
                map<int, int>::iterator iter;
                for (iter = dataMap.begin(); iter!= dataMap.end(); iter++)
                {
                    if (iter->second > 1)
                    {
                        minNum += (iter->second * (iter->second - 1)) / 2;
                    }
                }
                int maxNum = dataMap.begin()->second * (--iter)->second;
                cout << minNum << " " << maxNum << endl;
            }
        }
    }
}
