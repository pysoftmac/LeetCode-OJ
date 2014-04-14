#include "util.h"

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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
				path.push_back(candidates[i]);
				comb(candidates, i, sum + candidates[i], target, path, res);
				path.pop_back();
			}
		}
	}

	void test()
	{
		int a[] = {2, 3, 6, 7};
		vector<int> candidates = vector<int>(a, a + 4);
		vector<vector<int> > res = combinationSum(candidates, 7);
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