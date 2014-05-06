#include "util.h"

class Solution {
public:
    string simplifyPath(string path) {
		stack<string> directories;
		pathToDirectories(directories, path);
		string answer;
		directoriesToPath(answer, directories);
		return answer;
    }

	void pathToDirectories(stack<string> &directories, string &path)
	{
		string name;
		path += '/';
		for(int i = 0; i < (int)path.size(); i++)
		{
			if(path[i] == '/')
			{
				if(!name.empty())
				{
					if(name[0] == '.' && name.size() == 2 && name[1] == '.')
					{
						if(!directories.empty())
						{
							directories.pop();
						}
					}
					else if(!(name[0] == '.' && name.size() == 1))
					{
						directories.push(name);
					}
					name.clear();
				}
			}
			else
				name += path[i];
		}
	}

	void directoriesToPath(string &answer, stack<string> &directories)
	{
		while(!directories.empty())
		{
			answer = '/' + directories.top() + answer;
			directories.pop();
		}
		if(answer.empty())
			answer = "/";
	}

	void test()
	{
		cout << simplifyPath("/a/./b/../../c/") << endl;
	}
};