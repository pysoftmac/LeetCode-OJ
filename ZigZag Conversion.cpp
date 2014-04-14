#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) 
	{
		if(nRows == 1)
			return s;

		int zigsize = 2 * nRows - 2, s_len = s.length(), ti, count = 0;
		string ret(s);
		for(int i = 0; i < nRows; i++)
		{
			for(int base = i; ; base += zigsize)
			{
				if(base >= s_len)
					break;
				ret[count++] = s[base];

				if(i > 0 && i < nRows - 1)
				{
					ti = base + zigsize - 2 * i;
					if(ti < s_len)
						ret[count++] = s[ti];
				}
			}
		}
		return ret;
    }

	void test()
	{
		cout << convert("PAYPALISHIRING", 3) << endl;
	}
};