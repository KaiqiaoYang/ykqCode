/* 

给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。
如何删除才能使得回文串最长呢？输出需要删除的字符个数。

提到回文串，自然要利用回文串的特点，想到将源字符串逆转后，“回文串”（不一定连续）
相当于顺序没变。求原字符串和其反串的最大公共子序列（不是子串，因为可以不连续）的长度
（使用动态规划很容易求得），然后用原字符串的长度减去这个最大公共子串的长度就得到了最小删除长度。

*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int Max = 1001;
int MaxLen[Max][Max]; //最长公共子序列，动态规划求法

int maxLen(string s1, string s2)
{
	int length1 = s1.size();
	int length2 = s2.size();

	for (int i = 0; i < length1; ++i)
		MaxLen[i][0] = 0;
	for (int i = 0; i < length2; ++i)
		MaxLen[0][i] = 0;

	for (int i = 1; i <= length1; ++i)
	{
		for (int j = 1; j <= length2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				MaxLen[i][j] = MaxLen[i - 1][j - 1] + 1;
			}
			else
			{
				MaxLen[i][j] = max(MaxLen[i - 1][j], MaxLen[i][j - 1]);
			}
		}
	}

	return MaxLen[length1][length2];
}


void main()
{
	string s;
	while (cin >> s)
	{
		int length = s.size();
		if (length == 1)
		{
			cout << 1 << endl;
			continue;
		}
		string s2 = s;
		reverse(s2.begin(), s2.end());
		int maxLength = maxLen(s, s2);
		cout << length - maxLength << endl;
	}
}