#include "util.h"

class Solution {
public:
    string addBinary(string a, string b) {
		int ia = (int)a.size() - 1, ib = (int)b.size() - 1;
		int carry = 0;

		string res;
		while(ia >= 0 || ib >= 0 || carry > 0)
		{
			if(ia >= 0)
				carry += a[ia] - '0';
			if(ib >= 0)
				carry += b[ib] - '0';

			res = string(1, '0' + (1&carry)) + res;
			carry /= 2;

			ia--;
			ib--;
		}
		return res;
    }

	void test()
	{
		string a = "11";
		string b = "1";

		cout << addBinary(a, b) << endl;
	}
};