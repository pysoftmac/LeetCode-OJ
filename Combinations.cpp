#include "util.h"

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> path;
		vector<vector<int> > res;
		dfs(path, res, 1, n, k);
		return res;
    }

	void dfs(vector<int> &path, vector<vector<int> > &res, int idx, int &n, int &k)
	{
		if((int)path.size() == k)
		{
			res.push_back(path);
		}
		else
		{
			if(path.size() < k && idx <= n)
			{
				for(int i = idx; i <= n; i++)
				{
					path.push_back(i);
					dfs(path, res, i + 1, n, k);
					path.pop_back();
				}
			}
		}
	}
};