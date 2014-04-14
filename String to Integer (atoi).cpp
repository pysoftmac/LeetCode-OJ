#include <cstdlib>
#include <cstdio>

class Solution {
public:
    int atoi(const char *str) {
        int res = 0, i = 0, digit;
		bool isNeg = false;
		
		while(str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			++i;
		
		if(str[i] == '-')
		{
			isNeg = true;
			++i;
		}
		else if(str[i] == '+')
		{
			isNeg = false;
			++i;
		}

		while(str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if(INT_MAX / 10 >= abs(res))
				res *= 10;
			else
				return isNeg ? INT_MIN : INT_MAX;

			if(isNeg)
			{
				if(INT_MIN + digit < res)
					res -= digit;
				else
					return INT_MIN;
			}
			else
			{
				if(INT_MAX - digit > res) 
					res += digit;
				else
					return INT_MAX;
			}
			i++;
		}

		return res;
    }

	void test()
	{
		printf("%d\n", atoi("   -2147483647"));
	}
};