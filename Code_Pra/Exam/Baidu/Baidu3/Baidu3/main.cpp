#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



vector<int> solution(const vector<int>& ids)
{
	int len = ids.size();
	vector<int> flag(len+1,false);
	map<int,int> mp;
	vector<int> res;
	for(int i=0;i<len;i++)
	{
		mp[i+1] = ids[i];
	}

	for (auto it = mp.begin();it != mp.end();it++)
	{
		int a = it->first;
		int b = it->second;
		if(!flag[a])
		{
			if(mp[b] == a)
			{
				flag[a] = true;
				flag[b] = true;
			}
		}
	}

	for (int i=0;i<flag.size();i++)
	{
		auto tmp = flag[i];
		if(tmp)
		{
			mp.erase(i);
		}
	}

	auto it = mp.begin();
	auto a = it->first;
	while (1)
	{
		res.push_back(a);
		a = mp[a];
		auto it1 = find(res.begin(),res.end(),a);
		if(it1 != res.end())
			break;
	}

	 return res;
}


int main()
{
	int n;
	vector<int> vec;
	fstream fin("test.txt");
	fin >> n;
	for (int i=0;i<n;i++)
	{
		int a;
		fin >> a;
		vec.push_back(a);
	}

	vector<int> res = solution(vec);

	return 0;
}