#include "util.h"

class Solution {
public:
	bool check(string &s, int beg, int end)
	{
		string ip(s, beg, end - beg + 1);

		if(ip.size() == 1)
			return "0" <= ip && ip <="9";
		
		if(ip.size() == 2)
			return "10" <= ip && ip <= "99";

		if(ip.size() == 3)
			return "100" <= ip && ip <= "255";

		return false;
	}

	void dfs(string &s, vector<int> &path, int start, vector<string> &res)
	{
		if(path.size() == 4)
		{
			if(start == s.size())
			{
				int beg = 0;
				string addr;
				for(int i = 0; i < (int)path.size(); i++)
				{
					string ip(s, beg, path[i] - beg + 1);
					beg = path[i] + 1;
					addr += i == 0 ? ip : "." + ip;
				}
				res.push_back(addr);
			}
		}

		for(int i = start; i < (int)s.size() && i < start + 3; i++)
		{
			if(check(s,start,i))
			{
				path.push_back(i);
				dfs(s, path, i+1, res);
				path.pop_back();
			}
		}
	}
    vector<string> restoreIpAddresses(string s) {
        vector<int> path;
		vector<string> res;

        if(s.size() <= 12)
        {
		    dfs(s,path,0,res);
        }

		return res;
    }
};