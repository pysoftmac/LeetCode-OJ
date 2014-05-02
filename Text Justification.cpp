#include "util.h"

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> res;
		string line;
		int i = 0, curL = 0, j, addSpace, remainSpace, wordsLineSize = 0, start;
		while(true)
		{
			if(i < (int)words.size() && (int)words[i].length() + curL <= L)
			{
				wordsLineSize += 1;
				curL += ((int)words[i].length() + 1);
				i++;
			}
			else
			{
				start = i - wordsLineSize;
				if(i == (int)words.size())
				{
					for(j = start; j < i - 1; j++)
						line += (words[j] + " ");
					line += words[j];
					line += string(L - line.length(), ' ');
					res.push_back(line);
					break;
				}
				else
				{
					if(wordsLineSize == 1)
						line = words[start] + string(L - curL + 1, ' ');
					else
					{
						addSpace = (L - curL + 1) / (wordsLineSize - 1);
						remainSpace = (L - curL + 1) % (wordsLineSize - 1);
						for(j = start; j < i - 1; j++)
						{
							if(j - start < remainSpace)
							{
								line += (words[j] + string(addSpace + 2, ' '));
							}
							else
							{
								line += (words[j] + string(addSpace + 1, ' '));
							}
						}
						line += words[j];
					}
					res.push_back(line);
					line.clear();
					wordsLineSize = 0;
					curL = 0;
				}
			}
		}
		return res;
    }

	void test()
	{
		string strs[] = {"This", "is", "an", "example", "of", "text", "justification."};
		vector<string> words(strs, strs + 7);
		vector<string> res = fullJustify(words, 16);
		for(int i = 0; i < (int)res.size(); i++)
		{
			cout << res[i] << endl;
		}
	}
};