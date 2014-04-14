#include "util.h"

class Solution {
public:
	bool solveSudokudfs(vector<vector<char> > &board)
	{
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] == '.')
				{
					for(int k = 0; k < 9; k++)
					{
						board[i][j] = '1' + k;
						if(isValid(board, i, j) && solveSudokudfs(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		}
		return true;
	}

	bool isValid(vector<vector<char> > &board, int a, int b)
	{
		for(int i = 0; i < 9; i++)
			if(i != a && board[i][b] == board[a][b])
				return false;
		for(int j = 0; j < 9; j++)
			if(j != b && board[a][j] == board[a][b])
				return false;

		int m = a / 3 * 3;
		int n = b / 3 * 3;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(i + m != a && j + n != b && board[i + m][j + n] == board[a][b])
					return false;
			}
		}

		return true;
	}

    void solveSudoku(vector<vector<char> > &board) {
		solveSudokudfs(board);
    }
};