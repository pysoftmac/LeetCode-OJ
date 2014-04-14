#include "util.h"

class Solution {
public:
    int longestValidParentheses(string s) {
		int i;
		stack<int> sta = stack<int>();
		vector<int> idx = vector<int>(s.size());
		for(i = 0; i < (int)s.size(); i++)
			idx[i] = -1;
		for(i = 0; i < (int)s.size(); i++)
		{
			if(s[i] == '(')
				sta.push(i);
			else
			{
				if(!sta.empty())
				{
					idx[sta.top()] = i;
					sta.pop();
				}
			}
		}

		int res = 0, cur = 0;
		for(i = 0; i < (int)s.size();)
		{
			if(idx[i] == -1)
			{
				if(cur > res)
					res = cur;
				cur = 0;
				i++;
			}
			else
			{
				cur += idx[i] - i + 1;
				i = idx[i] + 1;
			}
		}

		if(cur > res)
			res = cur;
		return res;
    }
};