#include "util.h"

class Solution {
public:
    int numDecodings(string s) {
		if(s.length() == 0)
			return 0;

		vector<int> f(s.length(), 0);

		if(isLegal(s[0]))
			f[0] = 1;
		else
			f[0] = 0;

		if(s.length() == 1)
			return f[0];

		if(isLegal(s[1]))
			f[1] += f[0];
		if(isLegal(s[0],s[1]))
			f[1] += 1;

		for(int i = 2; i < (int)s.length(); i++)
		{
			if(isLegal(s[i]))
				f[i] += f[i-1];
			if(isLegal(s[i-1],s[i]))
				f[i] += f[i-2];
		}

		return f[s.length() - 1];
    }

	bool isLegal(const char a)
	{
		if('1' <= a && a <= '9')
			return true;
		else
			return false;
	}
	bool isLegal(const char a, const char b)
	{
		if((a == '1' &&  '0' <= b && b <= '9') || (a == '2' && '0' <= b && b <= '6'))
			return true;
		else
			return false;
	}
};