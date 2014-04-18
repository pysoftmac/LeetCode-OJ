#include "util.h"

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> sign(n, 0);
		vector<int> sign1(2*n, 0);
		vector<int> sign2(2*n, 0);
		vector<string> path;
		int res = 0;


		vector<string> strs;
		for(int i = 0; i < n; i++)
		{
			strs.push_back(string(n, '.'));
			strs[i][i] = 'Q';
		}


		dfs(n, sign, sign1, sign2, strs, path, res);
		return res;
    }

	void dfs(int n, vector<int> &sign, vector<int> &sign1, vector<int> &sign2, vector<string> &strs, vector<string> &path, int &res)
	{
		int j = path.size();
		if(j == n)
		{
			res++;
			return;
		}
		else
		{
			for(int i = 0; i < (int)sign.size(); i++)
			{
				if(sign[i] == 0 && sign1[j-i+n-1] == 0 && sign2[i+j] == 0)
				{
					sign[i] = 1;
					sign1[j-i+n-1] = 1;
					sign2[i+j] = 1;
					path.push_back(strs[i]);
					dfs(n, sign, sign1, sign2, strs, path, res);
					sign[i] = 0;
					sign1[j-i+n-1] = 0;
					sign2[i+j] = 0;
					path.pop_back();
				}
			}
		}
	}


	void test()
	{
		cout << totalNQueens(4) << endl;
	}

};