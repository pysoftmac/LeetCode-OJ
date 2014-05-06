#include "util.h"

class Solution {
public:
    string minWindow(string S, string T) {
		if(S.size() == 0 || T.size() == 0)
			return "";

        int count1[256], count2[256];

		memset(count1, 0, sizeof(count1));
		memset(count2, 0, sizeof(count2));

		for(int i = 0; i < (int)T.size(); i++)
		{
			count1[T[i]]++;
			count2[T[i]]++;
		}

		int count = T.size();

		int start = 0;
		int minSize = INT_MAX;
		int minStart;

		for(int end = 0; end < (int)S.size(); end++)
		{
			if(count2[S[end]] > 0)
			{
				count1[S[end]]--;
				if(count1[S[end]] >= 0)
					count--;
			}

			if(count == 0)
			{
				while(true)
				{
					if(count2[S[start]] > 0)
					{
						if(count1[S[start]] < 0)
						{
							count1[S[start]]++;
						}
						else
							break;
					}
					start++;
				}
				if(minSize > end - start + 1)
				{
					minSize = end - start + 1;
					minStart = start;
				}
			}
		}

		if(minSize == INT_MAX)
			return "";

		string ret(S, minStart, minSize);

		return ret;
    }

	void test()
	{
		cout << minWindow("a", "b") << endl;
	}
};