#include "util.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
			return n;
		int count = 1;
		for(int i = 1; i < n; i++)
		{
			if(A[i-1] != A[i])
				A[count++] = A[i];
		}
		return count;
    }

	void test()
	{
		int a[] = {1, 2, 3, 3};
		int res = removeDuplicates(a, 4);
		for(int i = 0; i < res; i++)
			cout << a[i] << endl;
	}
};