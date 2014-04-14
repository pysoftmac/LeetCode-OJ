#include "util.h"

class Solution {
public:
    int firstMissingPositive(int A[], int n) 
	{
		int temp = 0;
		for(int i = 0; i < n; i++)
		{
			while(A[i] != i + 1)
			{
				if(A[i] > n || A[i] <= 0 || A[A[i] - 1] == A[i])
					break;
				else
				{
					temp = A[i];
					A[i] = A[A[i] - 1];
					A[temp - 1] = temp;
				}
			}
		}

		for(int i = 0; i < n; i++)
		{
			if(A[i] != i + 1)
				return i + 1;
		}

		return n + 1;
    }

	void test()
	{
		int A[] = {3, 4, -1, 1};
		cout << firstMissingPositive(A, 4) << endl;
	}
};