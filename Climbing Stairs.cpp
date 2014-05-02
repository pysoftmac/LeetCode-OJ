#include "util.h"

class Solution {
public:
    int climbStairs(int n) {
		if(n <= 2)
			return n;
		int* dp = new int [n + 1];
		dp[1] = 1;
		dp[2] = 2;
		for(int i = 3; i <= n; i++)
		{
			dp[i] = dp[i-1] + dp[i-2];
		}
		int res = dp[n];
		delete [] dp; 
		return res;
    }

	/*
	void dfs(int n, int &res)
	{
		if(n < 0)
		{
			return;
		}
		else if(n == 0)
		{
			res += 1;
			return;
		}
		else
		{
			dfs(n - 1, res);
			dfs(n - 2, res);
		}
	}
	*/

	void test()
	{
		cout << climbStairs(3) << endl;
	}
};