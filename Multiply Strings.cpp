#include "util.h"

class Solution {
public:
    string multiply(string num1, string num2) {
		int len1 = (int)num1.size(), len2 = (int)num2.size(), len = len1 + len2;
		vector<int> res(len, 0);
		int a, b, t;
		for(int i = len1 - 1; i >= 0; i--)
		{
			a = num1[i] - '0';
			for(int j = len2 - 1, k = len2 + i; j >= 0; j--, k--)
			{
				b = num2[j] - '0';
				t = a * b + res[k];
				res[k] = t % 10;
				res[k - 1] = t / 10 + res[k - 1];
			}
		}

		stringstream ss;
		int i = 0;
		while(res[i] == 0)
			i++;
		for(; i < len; i++)
		{
			ss << res[i];
		}
		string resStr = ss.str();
		if(resStr.length() == 0)
			return string(1, '0');
		else
			return resStr;
    }

	void test()
	{
		cout << multiply("123", "234") << endl;
	}
};