#include "util.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int n = (int)matrix.size(), temp;
        for(int i = 0; i < (n + 1) / 2; i++)
		{
			for(int j = 0; j < n / 2; j++)
			{
				temp = matrix[i][j];
				matrix[i][j] = matrix[n-1-j][i];
				matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
				matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
				matrix[j][n-1-i] = temp;
			}
		}
    }

	void test()
	{
		int n = 5;
		vector<vector<int> > matrix(n, vector<int>(n));
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				matrix[i][j] = ++count;
			}
		}

		rotate(matrix);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};