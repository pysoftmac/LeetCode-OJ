#include "util.h"

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
		vector<int> path;
		comb(candidates, 0, 0, target, path, res);
		return res;
    }

	void comb(vector<int> &candidates, int index, int sum, int target, vector<int> &path, vector<vector<int> > &res)
	{
		if(sum > target)
			return;
		else if(sum == target)
		{
			res.push_back(path);
			return;
		}
		else
		{
			for(int i = index; i < candidates.size(); i++)
			{
				if(i == index || candidates[i] != candidates[i-1])
				{
					path.push_back(candidates[i]);
					int idx = i + 1;
					comb(candidates, i + 1, sum + candidates[i], target, path, res);
					path.pop_back();
				}
			}
		}
	}

	void test()
	{
		int a[] = {10,1,2,7,6,1,5};
		vector<int> candidates = vector<int>(a, a + 7);
		vector<vector<int> > res = combinationSum2(candidates, 8);
		for(int i = 0; i < (int)res.size(); i++)
		{
			for(int j = 0; j < (int)res[i].size(); j++)
			{
				cout << res[i][j] << ' ';
			}
			cout << endl;
		}
	}
};