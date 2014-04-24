#include "util.h"

class Solution {
public:
    string getPermutation(int n, int k) {
		string res;
        vector<int> sign(n + 1, 0);
		vector<int> data(n + 1, 0);
		data[1] = 1;
		for(int i = 2; i <= n; i++)
			data[i] = data[i - 1] * (i - 1); // data[i] = (i-1)!

		int chosen;
		k--;
		for(int i = n; i >= 1; i--)
		{
			chosen = k / data[i];
			for(int j = 1; j <= n; j++)
			{
				if(sign[j] == 0)
				{
					if(chosen == 0)
					{
						sign[j] = 1;
						res.push_back('0' + j);
						break;
					}
					else
						chosen--;
				}
			}
			k %= data[i];
		}
		return res;
    }

	void test()
	{
		cout << getPermutation(3,2) << endl;
	}
};