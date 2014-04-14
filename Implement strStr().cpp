#include "util.h"

class Solution
{
public:
    char *strStr(char *haystack, char *needle)
	{
		int lenHaystack = strlen(haystack);
		int lenNeedle = strlen(needle);
		int* next = new int [lenNeedle];

		getNext(needle, next, lenNeedle);

		int i = 0, j = 0;
		while(i < lenHaystack && j < lenNeedle)
		{
			if(j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
				j = next[j];
		}

		delete [] next;

		if(j >= lenNeedle)
			return &haystack[i - lenNeedle];
		else
			return NULL;
    }

	void getNext(char* t, int next[], int len)
	{
		int j = 0, k = -1;
		next[0] = -1;
		while(j < len - 1)
		{
			if(k == -1 || t[j] == t[k])
			{
				j++;
				k++;
				next[j] = k;
			}
			else
				k = next[k];
		}
	}
	
	void test()
	{
		char *s = "agctagca", *t = "cta";

		printf("%s\n", strStr(s, t));
	}
};