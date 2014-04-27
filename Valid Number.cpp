#include "util.h"

class Solution {
public:
	vector<vector<int> > transTable;

	int inputType(const char a)
	{
		if(a == ' ')
			return 0;
		else if(a == '+' || a == '-')
			return 1;
		else if(a >= '0' && a <= '9')
			return 2;
		else if(a == '.')
			return 3;
		else if(a == 'e')
			return 4;
		else
			return -1;
	}

	void initTransTable()
	{
		transTable.resize(9, vector<int>(5, -1));
		transTable[0][0] = 0;
		transTable[0][1] = 1;
		transTable[0][2] = 2;
		transTable[0][3] = 3;
		transTable[1][2] = 2;
		transTable[1][3] = 3;
		transTable[2][0] = 8;
		transTable[2][2] = 2;
		transTable[2][3] = 4;
		transTable[2][4] = 5;
		transTable[3][2] = 4;
		transTable[4][0] = 8;
		transTable[4][2] = 4;
		transTable[4][4] = 5;
		transTable[5][1] = 6;
		transTable[5][2] = 7;
		transTable[6][2] = 7;
		transTable[7][0] = 8;
		transTable[7][2] = 7;
		transTable[8][0] = 8;
	}

    bool isNumber(const char *s) {
        if(s == NULL)
			return false;

		initTransTable();
		int curState = 0, curInput;
		while(*s != '\0')
		{
			curInput = inputType(*s);
			if(curInput == -1)
				return false;
			curState = transTable[curState][curInput];
			if(curState == -1)
				return false;
			s++;
		}

		if(curState == 2 || curState == 4 || curState == 7 || curState == 8)
			return true;
		else
			return false;
    }
	
	void test()
	{
		if(isNumber("6e6.5"))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
};