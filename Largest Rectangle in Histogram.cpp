#include "util.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
		if((int)height.size() == 0)
			return 0;

		int maxArea = 0;

		stack<int> stackIndex;
		stack<int> stackHeight;

		for(int i = 0; i < (int)height.size(); i++)
		{
			if(stackIndex.empty() || height[i] > stackHeight.top())
			{
				stackIndex.push(i);
				stackHeight.push(height[i]);
			}
			else
			{
				if(height[i] < stackHeight.top())
				{
					int lastIndex = 0;
					while(!stackIndex.empty() && height[i] <= stackHeight.top())
					{
						int tempArea = stackHeight.top() * (i - stackIndex.top());
						if(tempArea > maxArea)
							maxArea = tempArea;
						lastIndex = stackIndex.top();
						stackIndex.pop();
						stackHeight.pop();
					}
					stackIndex.push(lastIndex);
					stackHeight.push(height[i]);
				}
			}
		}

		while(!stackIndex.empty())
		{
			int tempArea = stackHeight.top() * ((int)height.size() - stackIndex.top());
			if(tempArea > maxArea)
				maxArea = tempArea;
			stackIndex.pop();
			stackHeight.pop();
		}

		return maxArea;
    }

	void test()
	{
		vector<int> height(1,0);
		cout << largestRectangleArea(height) << endl;
	}
};