#include "util.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		vector<vector<int> > f(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

		if(obstacleGrid[0][0] == 0)
			f[0][0] = 1;
		else
			f[0][0] = 0;
		for(int i = 1; i < (int)obstacleGrid.size(); i++)
		{
			if(obstacleGrid[i][0] == 1)
				f[i][0] = 0;
			else
				f[i][0] = f[i-1][0];
		}

		for(int j = 1; j < (int)obstacleGrid[0].size(); j++)
		{
			if(obstacleGrid[0][j] == 1)
				f[0][j] = 0;
			else
				f[0][j] = f[0][j-1];
		}

		for(int i = 1; i < (int)obstacleGrid.size(); i++)
		{
			for(int j = 1; j < (int)obstacleGrid[0].size(); j++)
			{
				if(obstacleGrid[i][j] == 1)
					f[i][j] = 0;
				else
					f[i][j] = f[i-1][j] + f[i][j-1];
			}
		}

		return f[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};