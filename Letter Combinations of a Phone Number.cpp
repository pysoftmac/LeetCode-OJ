#include "util.h"
class Solution {
public:
	vector<string> res;
	vector<string> buttons;
	Solution()
	{
		string a[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		buttons = vector<string>(a, a+10);
	}
    vector<string> letterCombinations(string digits) {
        combine("", digits);
		return res;
    }

	void combine(string prefix, string digits)
	{
		if(digits.size() == 0)
		{
			res.push_back(prefix);
			return;
		}
		string newDigits = digits.substr(1, digits.size() - 1);
		if(buttons[digits[0] - '0'].size() == 0)
			combine(prefix, newDigits);
		else
		{
			for(int i = 0; i < (int)buttons[digits[0] - '0'].size(); i++)
			{
				combine(prefix + buttons[digits[0] - '0'][i], newDigits);
			}
		}
	}

	void test()
	{
		vector<string> res = letterCombinations("23");
		for(int i = 0; i < (int)res.size(); i++)
			cout << res[i] << endl;
	}
};