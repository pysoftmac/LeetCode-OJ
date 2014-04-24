#include "util.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
		int pos = -1;
		while(len > 0)
		{
			if(s[len - 1] != ' ')
				break;
			len--;
		}
		for(int i = len - 1; i >= 0; i--)
		{
			if(s[i] == ' ')
			{
				pos = i;
				break;
			}
		}
		if(pos == -1)
			return len;
		else
			return len - 1 - pos;
    }
};