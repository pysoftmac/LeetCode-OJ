#include "util.h"

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res = vector<vector<int> >();
		sort(num.begin(), num.end());

		int numSize = num.size();
		int k, l, value, temp;
		for(int i = 0; i < numSize - 3; i++)
		{
			if(i > 0 && num[i] == num[i-1])
				continue;
			for(int j = i + 1; j < numSize - 2; j++)
			{
				if(j > i + 1 && num[j] == num[j-1])
					continue;
				k = j + 1;
				l = numSize - 1;
				value = target - (num[i] + num[j]);
				while(k < l)
				{
					if(k > j + 1 && num[k] == num[k-1])
					{
						k++;
						continue;
					}
					if(l < numSize - 1 && num[l] == num[l+1])
					{
						l--;
						continue;
					}
					
					temp = num[k] + num[l];
					if(temp > value)
					{
						l--;
					}
					else if(temp < value)
					{
						k++;
					}
					else
					{
						vector<int> list = vector<int>();
						list.push_back(num[i]);
						list.push_back(num[j]);
						list.push_back(num[k]);
						list.push_back(num[l]);
						res.push_back(list);
						k++;
						l--;
					}
				}
			}
		}
		return res;
    }

	void test()
	{
		int a[6] = {1, 0, -1, 0, -2, 2};
		vector<vector<int> > vec = fourSum(vector<int>(a, a + 6), 0);
		vector<int> list;
		for(int i = 0; i < (int)vec.size(); i++)
		{
			list = vec[i];
			cout << list[0] << ", " << list[1] << ", " << list[2] << ", " << list[3] << endl;
		}
	}
};