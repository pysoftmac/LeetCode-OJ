#include "util.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
		res.push_back(0);
		int highbit = 0;
		while(n--)
		{
			highbit = res.size();
			for(int i = (int)res.size() - 1; i >= 0; i--)
				res.push_back(res[i]|highbit);
		}
		return res;
    }
};