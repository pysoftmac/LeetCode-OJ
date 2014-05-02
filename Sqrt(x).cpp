#include "util.h"

class Solution {
public:
    int sqrt(int x) {
        if(x == 0)
			return 0;

		double pre;
		double cur = 1;
		do
		{
			pre = cur;
			cur = 0.5 * (pre + x / pre);
		}
		while(fabs(cur - pre) > 1e-5);
		return int(cur);
    }

	void test()
	{
		cout << sqrt(9) << endl;
	}
};