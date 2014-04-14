#include "util.h"

class Solution {
public:
	vector<string> res;
	
    vector<string> generateParenthesis(int n) {
        generate("", n, 0);
		return res;
    }

	void generate(string s, int l, int r)
	{
		if(l == 0 && r == 0)
		{
			res.push_back(s);
			return;
		}

		if(l > 0)
			generate(s + "(", l - 1, r + 1);

		if(r > 0)
			generate(s + ")", l, r - 1);
	}

	void test()
	{
		generateParenthesis(3);
		for(int i = 0; i < (int)res.size(); i++)
			cout << res[i] << endl;
	}
};