#include "util.h"

class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n - 1, mid;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(A[mid] == target)
				break;
			if(A[l] <= A[mid])
			{
				if(target < A[mid] && target >= A[l])
					r = mid - 1;
				else
					l = mid + 1;
			}
			else
			{
				if(target < A[mid] || target >= A[l])
					r = mid - 1;
				else
					l = mid + 1;
			}
		}

		if(l > r)
			return -1;
		else
			return mid;
    }

	void test()
	{
		int A[2] = {1, 3};
		cout << search(A, 2, 3) << endl;
	}
};