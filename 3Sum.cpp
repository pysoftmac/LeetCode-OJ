#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > res = vector<vector<int> >();
		sort(num.begin(), num.end());

		int numSize = num.size();
		int m, n, mid, value;
		for(int i = 0; i < numSize - 2; i++)
		{
			if(i > 0 && num[i] == num[i-1])
				continue;
			for(int j = i + 1; j < numSize - 1; j++)
			{
				if(j > i + 1 && num[j] == num[j-1])
					continue;
				value = - (num[i] + num[j]);
				m = j + 1;
				n = numSize - 1;
				mid = -1;
				while(m <= n)
				{
					mid = (m + n) / 2;
					if(value == num[mid])
						break;
					else if(value < num[mid])
						n = mid - 1;
					else
						m = mid + 1;
					mid = -1;
				}

				if(mid != -1)
				{
					vector<int> list = vector<int>();
					list.push_back(num[i]);
					list.push_back(num[j]);
					list.push_back(num[mid]);
					res.push_back(list);
				}
			}
		}
		return res;
    }

	void test()
	{
		//int a[6] = {-1, 0, 1, 2, -1, -4};
		vector<vector<int> > vec = threeSum(vector<int>(/*a, a + 6*/));
		vector<int> list;
		for(int i = 0; i < (int)vec.size(); i++)
		{
			list = vec[i];
			cout << list[0] << ", " << list[1] << ", " << list[2] << endl;
		}
	}
};