#include "util.h"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0')
			return *s == '\0';

		if(*p == '*')
		{
			++p;
			while(true)
			{
				if(isMatch(s,p))
					return true;
				if(*s != '\0')
					++s;
				else
					break;
			}
		}
		else
		{
			if(*s != '\0' && (*p == '?' || *p == *s))
				return isMatch(s + 1, p + 1);
		}

		return false;
    }

	void test()
	{
		if(isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
};