#include <iostream>
#include <unordered_map>
#include <fstream>
#include <set>
using namespace std;

unordered_map<int,set<int>> graph;
vector<int> in,out;
vector<bool> vis;


int dfs(int i)
{
	int res = 0;

	vis[i] = true;
	auto st = graph[i];
	for(auto it=st.begin();it!=st.end();it++)
	{
		auto a = *it;
		if(!vis[a])
		{
			vis[a] = true;
			in[a]++;

			res++;
			res += dfs(a);
		}
	}

	return res;
}

int main()
{
	int n,m;
	fstream fin("test.txt");
	//unordered_map<int,int> path;
	
	fin >> n >> m;
	in.resize(n+1,0);
	out.resize(n+1,0);
	vis.resize(n+1,false);
	for (int i=0;i<m;i++)
	{
		int a,b;
		fin >> a >> b;
		if(a != b)
			graph[a].insert(b);
	}

	int cnt =0;
	for(int i=1;i<=n;i++)
	{
		out[i] = dfs(i);
		for (int i=0;i<=n;i++)
		{
			vis[i] = false;
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(in[i] > out[i])
			cnt++;
	}

	cout << cnt << endl;
	system("pause");
	return 0;
}