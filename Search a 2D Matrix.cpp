#include "util.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int l = 0, r = m * n - 1, mid;

		while(l <= r)
		{
			mid = (l + r) / 2;
			if(matrix[ mid/n ][ mid%n ] == target)
				return true;
			else if(matrix[ mid/n ][ mid%n ] > target)
				r = mid - 1;
			else
				l = mid + 1;
		}

		return false;
    }
};