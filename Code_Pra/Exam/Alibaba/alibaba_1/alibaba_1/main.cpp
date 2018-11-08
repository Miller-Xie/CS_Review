#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main()
{
	vector<string> vec;
	string str;
	cin >> str;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}


	return 0;

}