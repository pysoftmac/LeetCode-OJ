#include <cstdio>

class Solution {
public:
    int reverse(int x) 
	{
        int tag = 0;
		if(x < 0)
		{
			tag = 1;
			x = -x;
		}
		int y = 0;
		while(x > 0)
		{
			y *= 10;
			y += x % 10;
			x /= 10;
		}
		if(tag == 1)
			y = -y;
		return y;
    }

	void test()
	{
		printf("%d\n", reverse(-123));
	}
};