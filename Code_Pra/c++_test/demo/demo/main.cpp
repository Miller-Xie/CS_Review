#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;


inline bool comp(pair<int,int>& pr1,pair<int,int>& pr2)
{
	return (pr1.second > pr2.second);
}

int main()
{
	int N,M,P;
	fstream fin("test.txt");
	fin >> N >> M >> P;

	unordered_multimap<char,int> mp;
	map<int,int> th_mp; 
	for(int i=1;i<=N;i++)
	{
		int a;
		fin >> a;
		th_mp.insert(make_pair(i,a));
	}

	char ch;
	int cnt;
	for (int i=0;i<M;i++)
	{
		fin >> ch >> cnt;
		mp.insert(make_pair(ch,cnt));
	}

	for (auto it=mp.begin();it!=mp.end();it++)
	{
		char s = it->first;
		int i = it->second;
		if(s == 'A')
		{
			th_mp[i]++;
		}
		else if(s == 'B')
		{
			th_mp[i]--;
		}
	}

	vector<pair<int,int>> vec;
	for (auto it=th_mp.begin();it!=th_mp.end();it++)
	{
		auto p = *it;
		vec.push_back(p);
	}

	sort(vec.begin(),vec.end(),comp);

	int res = 1;
	for(int i=0;i<vec.size();i++)
	{
		if(i >= 1 && vec[i].second != vec[i-1].second)
			res++;
		else
			res++;
		if(P == vec[i].first)
			break;
	}

	cout << res << endl;
	system("pause");
	return 0;
}