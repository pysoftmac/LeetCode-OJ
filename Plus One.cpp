#include "util.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;

		int nSize = digits.size();
		int carry = 1;
		for(int i = nSize - 1; i >= 0; i--)
		{
			carry += digits[i];
			digits[i] = carry % 10;
			carry /= 10;
		}
		if(carry > 0)
			res.push_back(carry);
		for(int i = 0; i < nSize - 1; i++)
			res.push_back(digits[i]);
		return res;
    }
};