#include "util.h"

class Solution {
public:
    string countAndSay(int n) 
	{
		if(n <= 0)
			return string();
		stringstream ss;
		string res = "1";
		int j, count;
        for(int i = 2; i <= n; i++)
		{
			count = 1;
			j = 0;
			while(true)
			{
				j++;
				if(j < (int)res.length() && res[j] == res[j - 1])
					count++;
				else
				{
					ss << count << res[j - 1];
					count = 1;
					if(j >= (int)res.length())
					{
						res = ss.str();
						ss.str("");
						break;
					}
				}
			}
		}
		return res;
    }

	void test()
	{
		cout << countAndSay(3) << endl;
	}
};