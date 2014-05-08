#include "util.h"

class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1, mid;

		while(l <= r)
		{
			mid = (l + r) / 2;
			if(A[mid] == target)
				return true;
			else if(A[l] < A[mid])
			{
				if(A[l] <= target && target < A[mid])
					r = mid - 1;
				else
					l = mid + 1;
			}
			else if(A[mid] < A[r])
			{
				if(A[mid] < target && target <= A[r])
					l = mid + 1;
				else
					r = mid - 1;
			}
			else if(A[l] == A[mid])
				l++;
			else if(A[r] == A[mid])
				r--;
		}

		return false;
    }
};