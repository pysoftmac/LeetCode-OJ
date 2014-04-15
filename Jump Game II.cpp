#include "util.h"

class Solution {
public:
	/*
    int jump(int A[], int n) {
        int* dp = new int [n];
		
		dp[0] = 0;
		for(int i = 1; i < n; i++)
			dp[i] = n;

		for(int i = 0; i < n - 1; i++)
		{
			for(int j = 1; j <= A[i] && i + j < n; j++)
			{
				if(dp[i] + 1 < dp[i + j])
					dp[i + j] = dp[i] + 1;
			}
		}

		int res = dp[n - 1];
		delete [] dp;
		return res;
    }
	*/

	int jump(int A[], int n)
	{
		int last = 0, curr = 0, ret = 0;

		for(int i = 0; i < n; i++)
		{
			if(i > last)
			{
				last = curr;
				ret++;
			}
			curr = max(curr, i + A[i]);
		}

		return ret;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	void test()
	{
		int A[] = {2, 3, 1, 4};
		cout << jump(A, 4) << endl;
	}
};