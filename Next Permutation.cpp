#include "util.h"

class Solution {
public:
    void nextPermutation(vector<int> &num) {
		int i, temp;
		int numSize = (int)num.size();
		for(i = numSize - 2; i >= 0; i--)
		{
			if(num[i] < num[i + 1])
				break;
		}

		if(i != -1)
		{
			int j;
			for(j = numSize - 1; j >= 0; j--)
			{
				if(num[i] < num[j])
					break;
			}

			temp = num[i];
			num[i] = num[j];
			num[j] = temp;
		}

		int l = i + 1, r = numSize - 1;
		while(l < r)
		{
			temp = num[l];
			num[l] = num[r];
			num[r] = temp;
			l++;
			r--;
		}
    }

	void test()
	{
		int a[6] = {5, 1, 4, 3, 2, 0};
		vector<int> num(a, a + 6);
		nextPermutation(num);
		for(int i = 0; i < (int)num.size(); i++)
		{
			cout << num[i] << endl;
		}
	}
};