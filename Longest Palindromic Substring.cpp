#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int max = 0, start = 0;

		int len = s.length();
		if(len > 0)
			max = 1;

		bool** flag = new bool* [len];
		for(int i = 0; i < len; i++)
			flag[i] = new bool [2];

		int temp;
		for(int j = 0; j < len; j++)
		{
			flag[j][j%2] = true;
			if(j + 1 < len)
				flag[j+1][j%2] = true;
			for(int i = 0; i < j; i++)
			{
				if(s[i] == s[j] && flag[i+1][(j-1)%2] == true)
				{
					flag[i][j%2] = true;
					temp = j - i + 1;
					if(temp > max)
					{
						max = temp;
						start = i;
					}
				}
				else
					flag[i][j%2] = false;
			}
		}

		return s.substr(start, max);
    }

	void test()
	{
		cout << longestPalindrome("abcdefeccd") << endl;
	}
};