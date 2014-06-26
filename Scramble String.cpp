#include "util.h"

class Solution {
public:
	bool f[100][100][100];
    bool isScramble(string s1, string s2) {
		if(s1.length() != s2.length())
			return false;
		int len = s1.length();
		for(int k = 1; k <= len; k++)
		{
			for(int i = 0; i <= len - k; i++)
			{
				for(int j = 0; j <= len - k; j++)
				{
					f[i][j][k] = false;
					if(k == 1)
						f[i][j][k] = s1[i] == s2[j];
					else
					{
						for(int l = 1; l < k; l++)
						{
							if((f[i][j][l] && f[i+l][j+l][k-l]) || (f[i][j + k - l][l] && f[i + l][j][k - l]))
								f[i][j][k] = true;
						}
					}
				}
			}
		}

		return f[0][0][len];
    }
};