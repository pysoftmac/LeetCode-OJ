#include "util.h"

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = A[0], max = A[0];
		for(int i = 1; i < n; i++)
		{
			if(sum < 0)
				sum = A[i];
			else
				sum += A[i];

			if(sum > max)
				max = sum;
		}

		return max;
    }

	void test()
	{
		int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
		cout << maxSubArray(A, 9) << endl;
	}
};