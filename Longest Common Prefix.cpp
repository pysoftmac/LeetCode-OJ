#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		string res;
		int i, j = 0;
        while(true)
		{
			for(i = 0; i < (int)strs.size(); i++)
			{
				if(j >= (int)strs[i].length() || strs[i][j] != strs[0][j])
					break;
			}
			if(i == strs.size() && i != 0)
			{
				res += strs[0][j];
				j++;
			}
			else
				break;
		}
		return res;
    }

	void test()
	{
		string a[3] = {"aaaa", "aab", "aaac"};
		cout << longestCommonPrefix(vector<string>(a, a+3)) << endl;
	}
};