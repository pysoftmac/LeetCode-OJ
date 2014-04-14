#include "util.h"

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) 
	{
        int l = 0, r = n - 1, mid;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(A[mid] >= target)
				r = mid - 1;
			else
				l = mid + 1;
		}
		int left = l;
		l = 0, r = n - 1;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(A[mid] <= target)
				l = mid + 1;
			else
				r = mid - 1;
		}
		int right = r;
		
		vector<int> res;
		if(left <= n - 1 && right >= 0 && A[left] == target)
		{
			res.push_back(left);
			res.push_back(right);
		}
		else
		{
			res.push_back(-1);
			res.push_back(-1);
		}

		return res;
    }

	void test()
	{
		int A[1] = {1};
		vector<int> res = searchRange(A, 1, 0);
		for(int i = 0; i < (int)res.size(); i++)
			cout << res[i] << endl;
	}
};