#include "util.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
		if(dividend == 0 || divisor == 0)
			return 0;

		int active = 1;
		if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
			active = -1;
		long long a = abs((long long)dividend), b = abs((long long)divisor);

		long long sum = 0, count = 0, res = 0;

		while(a >= b)
		{
			count = 1;
			sum = b;
			while(sum + sum <= a)
			{
				count += count;
				sum += sum;
			}
			a -= sum;
			res += count;
		}

		/*
		if(a == 0 || active == 1)
			return active * res;
		else
			return - res - 1;
		*/

		return int(res * active);
    }

	void test()
	{
		printf("%d\n", divide(-1010369383, -2147483648));
	}
};