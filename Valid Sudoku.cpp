#include "util.h"

class Solution {
public:
	int count[9];
    bool isValidSudoku(vector<vector<char> > &board) 
	{
		for(int i = 0; i < 9; i++)
		{
			set0();
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] != '.')
				{
					if(++count[board[i][j] - '1'] > 1)
						return false;
				}
			}
		}
		for(int i = 0; i < 9; i++)
		{
			set0();
			for(int j = 0; j < 9; j++)
			{
				if(board[j][i] != '.')
				{
					if(++count[board[j][i] - '1'] > 1)
						return false;
				}
			}
		}
		for(int m = 0; m < 9; m += 3)
		{
			for(int n = 0; n < 9; n += 3)
			{
				set0();
				for(int i = m; i < m + 3; i++)
				{
					for(int j = n; j < n + 3; j++)
					{
						if(board[j][i] != '.')
						{
							if(++count[board[j][i] - '1'] > 1)
								return false;
						}
					}
				}
			}
		}
		return true;
    }
	void set0()
	{
		for(int i = 0; i < 9; i++)
			count[i] = 0;
	}
};