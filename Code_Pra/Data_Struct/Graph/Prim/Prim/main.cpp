#include <vector>
#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;


void Prim(vector<int>& dist,vector<vector<int>>& graph,int& sum)
{
	int vex = graph.size();
	while (1)
	{
		int idx = -1;
		int dis = INT_MAX;
		for (int i=0;i<vex;i++)
		{
			if(dist[i] != 0)
			{
				if(dist[i] < dis)
				{
					dis = dist[i];
					idx = i;
				}
			}
		}

		if(dis == INT_MAX)
			break;

		sum += dis;
		dist[idx] = 0;

		for(int i=0;i<vex;i++)
		{
			if(dist[i] != 0 && graph[i][idx] < INT_MAX)
			{
				if(dist[i] > graph[idx][i])
				{
					dist[i] = graph[idx][i];
				}
			}
		}
	}
}

int main()
{
	fstream fin("test.txt");
	int vex;
	fin >> vex;
	vector<vector<int>> graph(vex,vector<int>(vex,0));
	//vector<bool> vis(vex,false);
	//vis[0] = true;

	for(int i=0;i<vex;i++)
		for(int j=0;j<vex;j++)
		{
			int a;
			fin >> a;
			graph[i][j] = a;
		}

	vector<int> dist(vex,INT_MAX);
	dist[0] = 0;
	for(int i=1;i<vex;i++)
	{
		dist[i] = graph[i][0]; 
	}

	//vector<int> path(vex,-1);

	int min_sum = 0;
	Prim(dist,graph,min_sum);
	
	cout << min_sum << endl;

	return 0;
}