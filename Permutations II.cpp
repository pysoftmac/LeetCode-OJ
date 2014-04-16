#include "util.h"

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<int> sign(num.size(), 0);
		vector<int> path;
		vector<vector<int> > res;
		sort(num.begin(), num.end());
		dfs(num, sign, path, res);
		return res;
    }

	void dfs(vector<int> &num, vector<int>& sign, vector<int> &path, vector<vector<int> > &res)
	{
		if(path.size() == num.size())
		{
			res.push_back(path);
			return;
		}
		for(int i = 0; i < (int)num.size(); i++)
		{
			if(i == 0 || num[i] != num[i - 1] || sign[i - 1] == 1)
			{
				if(sign[i] == 0)
				{
					sign[i] = 1;
					path.push_back(num[i]);
					dfs(num, sign, path, res);
					sign[i] = 0;
					path.pop_back();
				}
			}
		}
	}

	void test()
	{
		int A[] = {1, 1, 2};
		vector<int> num(A, A + 3);
		vector<vector<int> > res = permuteUnique(num);
		for(int i = 0; i < (int)res.size(); i++)
		{
			for(int j = 0; j < (int)res[i].size(); j++)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
};