#include "util.h"

class Solution {
public:
    double pow(double x, /*int*/ long long n) 
	{
		if(n < 0)
			return 1 / pow(x, -n);
		double ans = 1;
		for(; n > 0; x *= x, n >>= 1)
		{
			if(n & 1)
				ans *= x;
		}
		return ans;
    }

	void test()
	{
		cout << pow(2,2) << endl;
	}
};