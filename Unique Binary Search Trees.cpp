#include "util.h"

class Solution {
public:
    int numTrees(int n) {
        if(n == 1)
			return 1;

		vector<int> dp(n+1, 0);
		dp[0] = 1; dp[1] = 1;

		for(int i = 2; i <= n; i++)
		{
			for(int k = 0; k < i; k++)
			{
				dp[i] += dp[k] * dp[i - k - 1];
			}
		}

		return dp[n];
    }
};