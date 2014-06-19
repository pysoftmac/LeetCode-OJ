#include "util.h"

class Solution {
public:
	int Max(int a, int b) { return a > b ? a : b; }
    int largestRectangleArea(vector<int> height) {
		height.push_back(0);
		stack<int> stk;
		int i = 0;
		int maxArea = 0;
		while(i < (int)height.size())
		{
			if(stk.empty() || height[stk.top()] <= height[i])
			{
				stk.push(i++);
			}
			else
			{
				int t = stk.top();
				stk.pop();
				maxArea = Max(maxArea, height[t] *(stk.empty() ? i : i - stk.top() - 1));
			}
		}

		return maxArea;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
		if(matrix.size() == 0)
			return 0;

		vector<int> a(matrix[0].size(),0);
		int maxArea = 0;
		for(int i = 0; i < (int)matrix.size(); i++)
		{
			for(int j = 0; j < (int)matrix[i].size(); j++)
				a[j] = matrix[i][j] == '1' ? a[j] + 1 : 0;
			maxArea = Max(maxArea, largestRectangleArea(a));
		}
		return maxArea;
    }
};