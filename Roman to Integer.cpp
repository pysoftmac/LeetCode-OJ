#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    int romanToInt(string s) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

		int res = 0;

		for(int i = 0; i < 13; i++)
		{
			while(s.substr(0, numerals[i].length()) == numerals[i])
			{
				s.erase(s.begin(), s.begin() + numerals[i].length());
				res += values[i];
			}
		}

		return res;
    }

	void test()
	{
		cout << romanToInt("MDCCCXCIX") << endl;
	}
};