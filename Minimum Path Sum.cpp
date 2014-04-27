#include "util.h"

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int> > f(grid.size(), vector<int>(grid[0].size(), 0));
		f[0][0] = grid[0][0];
		for(int i = 1; i < (int)grid.size(); i++)
			f[i][0] = f[i-1][0] + grid[i][0];
		for(int j = 1; j < (int)grid[0].size(); j++)
			f[0][j] = f[0][j-1] + grid[0][j];
		for(int i = 1; i < (int)grid.size(); i++)
		{
			for(int j = 1; j < (int)grid[0].size(); j++)
			{
				if(f[i][j-1] < f[i-1][j])
					f[i][j] = f[i][j-1] + grid[i][j];
				else
					f[i][j] = f[i-1][j] + grid[i][j];
			}
		}
		return f[grid.size()-1][grid[0].size()-1];
    }
};