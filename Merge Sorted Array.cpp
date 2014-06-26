#include "util.h"


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index = m + n - 1;
		int aIndex = m - 1;
		int bIndex = n - 1;

		while(aIndex >= 0 && bIndex >= 0)
		{
			if(A[aIndex] > B[bIndex])
				A[index--] = A[aIndex--];
			else
				A[index--] = B[bIndex--];
		}

		while(bIndex >= 0)
			A[index--] = B[bIndex--];
    }
};