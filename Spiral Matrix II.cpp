#include "util.h"

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));

		int l, r, count = 0;
		for(int i = 0; i < (n + 1) / 2; i++)
		{
			l = i;
			r = n - 1 - i;
			if(l != r)
			{
				for(int j = l; j < r; j++)
					matrix[l][j] = ++count;
				for(int j = l; j < r; j++)
					matrix[j][r] = ++count;
				for(int j = r; j > l; j--)
					matrix[r][j] = ++count;
				for(int j = r; j > l; j--)
					matrix[j][l] = ++count;
			}
			else
			{
				matrix[l][r] = ++count;
			}
		}

		return matrix;
    }
};