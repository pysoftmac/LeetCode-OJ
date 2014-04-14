#include "util.h"
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta = stack<char>();
		for(int i = 0; i < (int)s.size(); i++)
		{
			if(isLBracket(s[i]))
				sta.push(s[i]);
			else
			{
				if(!sta.empty() && isCouple(sta.top(), s[i]))
					sta.pop();
				else
					return false;
			}
		}
		if(sta.empty())
			return true;
		else
			return false;
    }

	bool isLBracket(char c)
	{
		if(c == '{' || c == '[' || c == '(')
			return true;
		else
			return false;
	}

	bool isCouple(char a, char b)
	{
		if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
			return true;
		else
			return false;
	}

	void test()
	{
		if(isValid("()"))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
};