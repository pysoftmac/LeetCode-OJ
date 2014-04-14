#include "util.h"

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			if(A[i] != elem)
				A[count++] = A[i];
		}
		return count;
    }

	void test()
	{
		int a[] = {1, 2, 3, 3};
		int res = removeElement(a, 4, 3);
		for(int i = 0; i < res; i++)
			cout << a[i] << endl;
	}
};