#include "util.h"

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
        vector<vector<int> > res;
		vector<int> path;
		dfs(S,0,path,res);
		return res;
    }

	void dfs(vector<int> &S, int start, vector<int> &path, vector<vector<int> > &res)
	{
		res.push_back(path);

		for(int i = start; i < (int)S.size(); i++)
		{
			if(i != start && S[i] == S[i-1])
				continue;

			path.push_back(S[i]);
			dfs(S,i+1,path,res);
			path.pop_back();
		}
	}
};