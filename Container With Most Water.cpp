#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int maxArea(vector<int> &height) {
		int l = 0, r = height.size() - 1, i, j;

		int res = 0, capacity = 0;
		while(l < r)
		{
			capacity = min(height[l], height[r]) * (r - l);
			if(capacity > res)
				res = capacity;

			if(height[l] < height[r])
			{
				i = l + 1;
				while(height[i] <= height[l])
					i++;
				l = i;
			}
			else
			{
				j = r - 1;
				while(height[j] <= height[r])
					j--;
				r = j;
			}
		}
		return res;
    }

	int min(int a, int b)
	{
		return a < b ? a : b;
	}

	void test()
	{
		int a[7]={1,2,3,4,5,6,7};
		printf("%d\n", maxArea(vector<int>(a, a+7)));
	}
};