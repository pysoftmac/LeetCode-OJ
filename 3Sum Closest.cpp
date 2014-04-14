#include "util.h"

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());

		int numSize = num.size();
		int m, n, mid, value, temp, marginMid, marginTemp;
		int res = num[0] + num[1] + num[2], minMargin = abs(target - res);
		for(int i = 0; i < numSize - 2; i++)
		{
			if(i > 0 && num[i] == num[i-1])
				continue;
			for(int j = i + 1; j < numSize - 1; j++)
			{
				if(j > i + 1 && num[j] == num[j-1])
					continue;
				value = target - (num[i] + num[j]);
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
				}

				if(num[mid] == value)
				{
					res = target;
					minMargin = 0;
				}
				else
				{
					if(num[mid] > value)
					{
						temp = mid;
						while(temp > j && num[temp] == num[mid])
							temp--;
					}
					else
					{
						temp = mid;
						while(temp < numSize && num[temp] == num[mid])
							temp++;
					}
					marginMid = abs(num[mid] - value);
					if(temp > j && temp < numSize && (marginTemp = abs(num[temp] - value)) < marginMid)
					{
						if(marginTemp < minMargin)
						{
							res = num[i] + num[j] + num[temp];
							minMargin = marginTemp;
						}
					}
					else
					{
						if(marginMid < minMargin)
						{
							res = num[i] + num[j] + num[mid];
							minMargin = marginMid;
						}
					}

				}
			}
		}
		return res;
    }

	void test()
	{
		int a[4] = {-1, 2, 1, -4};
		cout << threeSumClosest(vector<int>(a, a+4), 1) << endl;
	}
};