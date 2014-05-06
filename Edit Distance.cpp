#include "util.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
		int m = word1.length() + 1, n = word2.length() + 1;
		vector<vector<int> > dp(m, vector<int>(n, 0));
		for(int i = 1; i < m; i++)
			dp[i][0] = i;
		for(int j = 1; j < n; j++)
			dp[0][j] = j;

		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				if(word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
				{
					dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
				}
			}
		}
		return dp[m-1][n-1];
    }

	int min3(int a, int b, int c)
	{
		if(a < b && a < c)
			return a;
		else
		{
			if(b < c)
				return b;
			else
				return c;
		}
	}

	void test()
	{
		cout << minDistance("abc", "ac") << endl;
	}
};