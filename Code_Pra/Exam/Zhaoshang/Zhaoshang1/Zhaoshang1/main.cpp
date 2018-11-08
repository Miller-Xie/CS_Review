#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
	string str1,str2;
	fstream fin("test.txt");
	getline(fin,str1,'\n');
	getline(fin,str2,'\n');

	vector<int> s,g;
	string tmp;
	for (int i=0;i<str1.size();i++)
	{
		if(str1[i] == ' ')
		{
			s.push_back(stoi(tmp));
			tmp.clear();
			//continue;
		}
		else{
			tmp.push_back(str1[i]);
		}
	}
	s.push_back(stoi(tmp));
	tmp.clear();

	for (int i=0;i<str2.size();i++)
	{
		if(str2[i] == ' ')
		{
			g.push_back(stoi(tmp));
			tmp.clear();
			//continue;
		}
		else{
			tmp.push_back(str2[i]);
		}
	}

	g.push_back(stoi(tmp));

	sort(s.begin(),s.end());
	sort(g.begin(),g.end());

	int i=0,j=0;
	int cnt = 0;
	int len1 = s.size();
	int len2 = g.size();
	while(i < len1 && j < len2)
	{
		if(s[i] <= g[j])
		{
			cnt++;
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}

	cout << cnt << endl;

	//system("pause");
	return 0;

}