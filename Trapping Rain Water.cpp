#include "util.h"

class Solution {
public:
	int min(int &a, int &b)
	{
		if(a < b)
			return a;
		else
			return b;
	}
    int trap(int A[], int n) {

		int maxHeight = 0;
		vector<int> leftMostHeight(n);
		for(int i = 0; i < n; i++)
		{
			leftMostHeight[i] = maxHeight;
			if(A[i] > maxHeight)
				maxHeight = A[i];
		}

		maxHeight = 0;
		vector<int> rightMostHeight(n);
		for(int i = n - 1; i >= 0; i--)
		{
			rightMostHeight[i] = maxHeight;
			if(A[i] > maxHeight)
				maxHeight = A[i];
		}

		int res = 0, high;
		for(int i = 0; i < n; i++)
		{
			high = min(leftMostHeight[i], rightMostHeight[i]) - A[i];
			if(high > 0)
				res += high;
		}

		return res;
    }

	void test()
	{
		int A[4] = {5,4,1,2};
		cout << trap(A, 4) << endl;
	}
};