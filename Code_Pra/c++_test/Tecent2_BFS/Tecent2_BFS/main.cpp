#include <iostream>
#include <unordered_map>
#include <fstream>
#include <set>
#include <queue>
using namespace std;

unordered_map<int,set<int>> graph;
vector<int> in,out;
vector<bool> vis;


int main()
{
	int n,m;
	fstream fin("test.txt");
	//unordered_map<int,int> path;

	fin >> n >> m;
	in.resize(n+1);
	out.resize(n+1);
	vis.resize(n+1,false);

	for (int i=0;i<m;i++)
	{
		int a,b;
		fin >> a >> b;
		if(a != b)
			graph[a].insert(b);
	}

	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		queue<int> que;
		que.push(i);
		while(!que.empty())
		{
			auto a = que.front();
			que.pop();

			auto st = graph[a];
			for(auto it=st.begin();it!=st.end();it++)
			{
				int tmp = *it;
				if(!vis[tmp])
				{
					vis[tmp] = true;
					out[i]++;
					in[tmp]++;
					que.push(tmp);
				}
			}
		}

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