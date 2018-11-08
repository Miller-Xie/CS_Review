#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm> 
using namespace std;


int main()
{
	string str;
	fstream fin("test.txt");
	fin >>str;
	int len = str.size();
	if(len == 0)
	{
		cout << "/" << endl;
		return 0;
	}

	vector<string> vec;
	string res("");
	int first = str[0] == '/' ? 0 : -1;
	for(int i = first + 1;i <= len;i++)
	{
		if(str[i] == '/' || i == len)
		{
			string ch = str.substr(first + 1,i - first - 1);
			if(ch == ".."){
				if(!vec.empty())
					vec.pop_back();
			}
			else if(ch != "." && ch != "")
				vec.push_back(ch);
			first = i;
		}
	}

	for(int i=0;i<vec.size();i++)
		res += '/' + vec[i];

	if(res == "") 
	{
		cout << "/" << endl;
		return 0;
	}

	cout << res <<endl;

	system("pause");
	return 0;
}