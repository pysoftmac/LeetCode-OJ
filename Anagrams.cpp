#include "util.h"

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> solution;
		map<string, int> strMap;
		map<string, int>::iterator it;
		for(int i = 0; i < (int)strs.size(); i++)
		{
			string tmps = strs[i];
			sort(tmps.begin(), tmps.end());
			it = strMap.find(tmps);
			if(it == strMap.end())
				strMap[tmps] = i;
			else
			{
				if(strMap[tmps] != -1)
				{
					solution.push_back(strs[strMap[tmps]]);
					strMap[tmps] = -1;
				}
				solution.push_back(strs[i]);
			}
		}
		return solution;
    }

	void test()
	{
		vector<string> strs;
		strs.push_back("tea");
		strs.push_back("and");
		strs.push_back("ate");
		strs.push_back("eat");
		strs.push_back("den");
		vector<string> solution = anagrams(strs);
		for(int i = 0; i < (int)solution.size(); i++)
			cout << solution[i] << endl;
	}
};