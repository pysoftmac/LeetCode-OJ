#include "util.h"

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		if(word.size() == 0)
			return true;

		for(int i = 0; i < (int)board.size(); i++)
		{
			for(int j = 0; j < (int)board[0].size(); j++)
			{
				if(board[i][j] == word[0])
				{
					board[i][j] = '#';
					if(dfs(board, i, j, word.substr(1)))
						return true;
					board[i][j] = word[0];
				}
			}
		}

		return false;
    }

	bool dfs(vector<vector<char> > &board, int x, int y, string word)
	{
		if(word.size() == 0)
			return true;

		bool flag = false;
		if(!flag && x - 1 >= 0 && board[x-1][y] == word[0])
		{
			board[x-1][y] = '#';
			flag = dfs(board, x-1, y, word.substr(1));
			board[x-1][y] = word[0];
		}

		if(!flag && y - 1 >= 0 && board[x][y-1] == word[0])
		{
			board[x][y-1] = '#';
			flag = dfs(board, x, y-1, word.substr(1));
			board[x][y-1] = word[0];
		}

		if(!flag && x + 1 <= (int)board.size() && board[x+1][y] == word[0])
		{
			board[x+1][y] = '#';
			flag = dfs(board, x+1, y, word.substr(1));
			board[x+1][y] = word[0];
		}

		if(!flag && y + 1 <= (int)board[0].size() && board[x][y+1] == word[0])
		{
			board[x][y+1] = '#';
			flag = dfs(board, x, y+1, word.substr(1));
			board[x][y+1] = word[0];
		}

		return flag;
	}
};