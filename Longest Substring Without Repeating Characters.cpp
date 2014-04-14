#include <string>
#include <cstdio>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
		int map[500], len = 0, start = -1, temp;

		for(int i = 0; i < 500; i++)
			map[i] = -1;

		for(int idx = 0; idx < (int)s.length(); idx++)
		{
			if(map[s[idx]] > start)
				start = map[s[idx]];

			temp = idx - start;
			if(temp > len)
				len = temp;

			map[s[idx]] = idx;
		}

		return len;
    }

	void test()
	{
		string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
		printf("%d\n", lengthOfLongestSubstring(s));
	}
};