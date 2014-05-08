#include "util.h"

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		reverse(S.begin(), S.end());
        vector<int> path;
		vector<vector<int> > res;
		dfs(path, res, S, 0);
		return res;
    }

	void dfs(vector<int> &path, vector<vector<int> > &res, vector<int> &S, int idx)
	{
		res.push_back(path);

		if(path.size() < S.size() && idx < (int)S.size())
		{
			for(int i = idx; i < (int)S.size(); i++)
			{
				path.push_back(S[i]);
				dfs(path, res, S, i + 1);
				path.pop_back();
			}
		}
	}
};