/*
	思路：
    1.先排序
         特殊情况：如果排完序之后发现数组中所有数都相同，直接输出结果
             结果为：差最大个数 = 差最小个数 = （n * (n-1))/2;(两两组合)
    2.统计数组中每种数字的个数（这里用的map）
    3.计算差最小个数
        3.1.如果数组中没有重复数字，说明最小差不为0，最小差肯定是数组中相邻两个数的差
            因此，遍历一边数组，计算并统计最小差。
        3.2.如果数组中有重复数字，说明最小差是0，此时，遍历一边map，数字个数不为0的
            数字会产生最小差0，利用公式计算即可
    4.计算差最大个数
        只有一种情况，最大值与最小值的两两组合，即最大值个数 * 最小值个数
    算法复杂度：排序O(nlogn), 统计O(n)
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

			//map统计集合中每种数字的个数，改了很久的bug。。。
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
