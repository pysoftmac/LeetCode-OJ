#include "util.h"

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
		if(L.size() <= 0)
			return vector<int>();

		vector<int> res;

		map<string, int> wordCount;
		for(int i = 0; i < (int)L.size(); i++)
			wordCount[L[i]]++;

		int wordSize = L[0].length();
		map<string, int> counting;
		int j;
		for(int i = 0; i <= (int)S.length() - (int)L.size() * wordSize; i++)
		{
			counting.clear();
			for(j = 0; j < (int)L.size(); j++)
			{
				string word = S.substr(i + j * wordSize, wordSize);
				if(wordCount.find(word) != wordCount.end())
				{
					++counting[word];
					if(counting[word] > wordCount[word])
						break;
				}
				else
					break;
			}
			
			if(j == L.size())
				res.push_back(i);
		}

		return res;
    }

	void test()
	{
		string s = "a";
		string l[2] = {"a", "a"};
		vector<string> L(l, l + 2);
		vector<int> res = findSubstring(s, L);
		for(int i = 0; i < (int)res.size(); i++)
			cout << res[i] << endl;
	}
};