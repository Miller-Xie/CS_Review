#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


inline bool comp(const pair<int,int>& pr1,const pair<int,int>& pr2)
{
	return ((pr1.second > pr2.second) || (pr1.second == pr2.second && pr1.first < pr2.first));
}

int get_cnt(int num,int k)
{
	int cnt=0;
	while(num)
	{
		if(num%k == k-1)
			cnt++;

		num /= k;
	}

	return cnt;
}

int main()
{
	int q;
	vector<int> l,r,k;
	fstream fin("test.txt");
	fin >> q;
	for (int i=0;i<1;i++)
	{
		int a,b,c;
		fin >> a >> b >> c;
		k.push_back(a);
		l.push_back(b);
		r.push_back(c);
	}

	vector<pair<int,int>> vec;

	for (int i=0;i<q;i++)
	{
		for(int j=l[i];j<=r[i];j++)
		{
			vec.push_back(make_pair(j,get_cnt(j,k[i])));
		}

		sort(vec.begin(),vec.end(),comp);

		cout << vec.front().first << endl;
	}
	

	system("pause");
	return 0;
}