#include "util.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n == 0)
			return n;
        int count = 1, dupcount = 1;

		for(int i = 1; i < n; i++)
		{
			if(A[i] == A[i-1])
				dupcount += 1;
			else
				dupcount = 1;
			if(dupcount < 3)
				A[count++] = A[i];
		}
		return count;
    }

	void test()
	{
		int A[] = {1, 1, 1, 2, 2, 3};
		cout << removeDuplicates(A, 6) << endl;
	}
};