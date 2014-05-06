#include "util.h"

class Solution {
public:
    void sortColors(int A[], int n) {
        int i = 0; // 0 pointer
		int j = n - 1; // 1 pointer
		int k = n - 1; // 2 pointer

		while(i <= j)
		{
			if(A[i] == 2)
			{
				int t = A[i];
				A[i] = A[k];
				A[k] = t;
				k--;
				if(k < j)
					j = k;
			}
			else if(A[i] == 1)
			{
				int t = A[i];
				A[i] = A[j];
				A[j] = t;
				j--;
			}
			else
				i++;
		}
    }
};