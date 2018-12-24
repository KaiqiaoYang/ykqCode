#include<iostream>
#include<string>

using namespace std;

void main()
{
	string s;
	while (cin >> s)
	{
		int i = s.length();
		int j = i - 1;
		while (j >= 0)
		{
			if (isupper(s[j]))
			{
				i--;
				int tmp = s[j];
				for (int t = j; t <= i; t++)
				{
					s[t] = s[t + 1];
				}
				s[i] = tmp;
			}
			j--;
		}
		cout << s << endl;
		getchar();
	}

}