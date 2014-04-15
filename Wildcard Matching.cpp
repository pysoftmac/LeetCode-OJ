#include "util.h"

class Solution {
public:
	bool isMatch(const char *s, const char *p) 
	{
		int n=strlen(s), m=strlen(p), i, j, chars=0;
		for(i=0; p[i]!='\0'; ++i) 
			if(p[i]!='*' && n<++chars) 
				return false;
		vector<bool> dp(n+2,false);
		for(i=m-1, dp[n]=true; i>=0; --i)
		{
			if(p[i]=='*')
			{
				while(i>0 && p[i]==p[i-1]) 
					--i; //skip multiple *
				for(j=n; j>=0 && !dp[j]; --j);
				for(; j>=0; --j) 
					dp[j]=true;
			}else{
				for(j=0; j<n+1; ++j)
					dp[j]=(p[i]==s[j] || p[i]=='?') ? dp[j+1] : false;
			}
		}
		return dp[0];
	}
	/*
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
	*/

	void test()
	{
		if(isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
};