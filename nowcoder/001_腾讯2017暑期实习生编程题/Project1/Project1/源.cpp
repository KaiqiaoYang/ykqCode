/* 

����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ���
���ɾ������ʹ�û��Ĵ���أ������Ҫɾ�����ַ�������

�ᵽ���Ĵ�����ȻҪ���û��Ĵ����ص㣬�뵽��Դ�ַ�����ת�󣬡����Ĵ�������һ��������
�൱��˳��û�䡣��ԭ�ַ������䷴������󹫹������У������Ӵ�����Ϊ���Բ��������ĳ���
��ʹ�ö�̬�滮��������ã���Ȼ����ԭ�ַ����ĳ��ȼ�ȥ�����󹫹��Ӵ��ĳ��Ⱦ͵õ�����Сɾ�����ȡ�

*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int Max = 1001;
int MaxLen[Max][Max]; //����������У���̬�滮��

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