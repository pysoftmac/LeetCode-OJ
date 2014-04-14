#include "util.h"

class Solution {
public:
    int searchInsert(int A[], int n, int target) 
	{
        int l = 0, r = n - 1, mid;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(A[mid] == target)
			{
				return mid;
			}
			else if(A[mid] > target)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		return l;
    }

	void test()
	{
		int A[4] = {1, 3, 5, 6};
		cout << searchInsert(A, 4, 2) << endl;
	}
};