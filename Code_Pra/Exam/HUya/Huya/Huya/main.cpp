#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <fstream>
using namespace std;

inline bool comp(const pair<int,int>& pr1,const pair<int,int>& pr2)
{
	return ( (pr1.first < pr2.first) || ((pr1.first == pr2.first) && (pr1.second > pr2.second)));
}

int main()
{
	vector<pair<int,int>> vec;
	int x,y;
	fstream fin("test.txt");
	while(fin >> x >> y)
	{
		vec.push_back(make_pair(x,y));
	}

	sort(vec.begin(),vec.end(),comp);

	for (int i=0;i<vec.size();i++)
	{
		cout << vec[i].first;
		cout << " ";
		cout << vec[i].second << endl;
	}
	system("pause");
	return 0;

}