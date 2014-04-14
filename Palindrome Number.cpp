#include<cstdio>

class Solution {
public:
    bool isPalindrome(int x) 
	{
		if(x < 0)
			return false;

		int base = 1;

		while(x / base >= 10)
			base *= 10;

		int lDigit, rDigit;
		while(x >= 10)
		{
			lDigit = x / base;
			rDigit = x % 10;

			if(lDigit == rDigit)
			{
				x -= lDigit * base;
				x /= 10;
				base /= 100;
			}
			else
			{
				return false;
			}
		}
        
		return true;
    }

	void test()
	{
		bool isTrue = isPalindrome(111111);
		if(isTrue)
		{
			printf("True\n");
		}
		else
		{
			printf("False\n");
		}
	}
};