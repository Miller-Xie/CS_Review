#include <vector>
#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;


void Dijkstral(int src,vector<int>& dist,vector<bool>& vis,vector<vector<int>>& graph)
{
	int vex = graph.size();
	while (1)
	{
		int idx = -1;
		int dis = INT_MAX;
		for (int i=0;i<dist.size();i++)
		{
			if(!vis[i])
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

		vis[idx] = true;

		for(int i=0;i<vex;i++)
		{
			if(!vis[i] && graph[i][idx] < INT_MAX)
			{
				if(dist[i] > graph[idx][i] + dist[idx])
					dist[i] = graph[idx][i] + dist[idx];
			}
		}
	}
}

int main()
{
	fstream fin("test.txt");
	int vex,edge;
	fin >> vex >> edge;
	int src,dst;
	fin >> src >> dst;
	cout << vex <<endl;
	vector<vector<int>> graph(vex,vector<int>(vex,INT_MAX));

	while (edge--)
	{
		int a,b,len;
		fin >> a >> b >> len;
		graph[a-1][b-1] = min(graph[a-1][b-1],len);
		graph[b-1][a-1] = graph[a-1][b-1];
	}

	vector<int> dist(vex,INT_MAX);
	dist[src-1] = 0;
	for(int i=0;i<vex;i++)
	{
		if(i != src-1 && graph[src-1][i] != INT_MAX)
		{
			dist[i] = graph[src-1][i];
		}
	}

	vector<bool> vis(vex,false);

	Dijkstral(src,dist,vis,graph);

	cout << dist[dst-1] << endl;

	return 0;
}