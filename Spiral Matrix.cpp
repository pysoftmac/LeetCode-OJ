#include "util.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> res;
		int m = matrix.size();
		if(m == 0)
			return res;
		int n = matrix[0].size();
		int l, r, u, d;
		int min = m < n ? m : n;
		for(int i = 0; i < (min + 1) / 2; i++)
		{
			l = i;
			r = n - 1 - i;
			u = i;
			d = m - 1 - i;
			if(l != r && u != d)
			{
				for(int j = l; j < r; j++)
					res.push_back(matrix[u][j]);
				for(int j = u; j < d; j++)
					res.push_back(matrix[j][r]);
				for(int j = r; j > l; j--)
					res.push_back(matrix[d][j]);
				for(int j = d; j > u; j--)
					res.push_back(matrix[j][l]);
			}
			else
			{
				for(int j = u; j <= d; j++)
					for(int k = l; k <= r; k++)
						res.push_back(matrix[j][k]);
			}
		}

		return res;
    }

	void test()
	{
		int m = 1, n = 2;
		vector<vector<int> > matrix(m, vector<int>(n));
		int count = 0;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				matrix[i][j] = ++count;
			}
		}

		vector<int> res = spiralOrder(matrix);

		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		for(int i = 0; i < (int)res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
};