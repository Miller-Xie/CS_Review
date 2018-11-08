#include <vector>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <algorithm>
using namespace std;


struct edge 
{
	int begin;
	int end;
	int weight;
	edge(int b,int e,int w):begin(b),end(e),weight(w){}
};

inline bool cmp(const edge& e1,const edge& e2)
{
	return e1.weight > e2.weight;
}

int findRoot(int idx,const vector<int>& path)
{
	while(path[idx] != idx)
	{
		idx = path[idx];
	}

	return idx;
}

void Kruscal(vector<edge>& graph,int& sum,const int& v)
{
	//sort(graph.begin(),graph.end(),cmp);
	int e = graph.size();
	int cnt = 0;

	//根据权值weight建立最小堆,建立堆时间复杂度O(e)
	make_heap(graph.begin(),graph.end(),cmp);
	vector<int> path(v,0);
	for (int i=0;i<v;i++)
	{
		path[i] = i;
	}
	
	//循环时间复杂度O(eloge)
	while(cnt < v-1 && !graph.empty())
	{
		//sum += graph[0].weight;
		edge tmp = graph[0];
		int m = tmp.begin;
		int n = tmp.end;

		//从堆中删除最小边
		pop_heap(graph.begin(),graph.end(),cmp);
		graph.pop_back();
		if(findRoot(m,path) != findRoot(n,path))
		{
			path[m] = n;
			sum += tmp.weight;
			++cnt;
		}
	}

	return;
	//return sum;

}

int main()
{
	fstream fin("test.txt");
	int N,M;
	fin >> N >> M;
	vector<vector<int>> graph(N,vector<int>(N,INT_MAX));
	for(int i=0;i<M;i++)
	{
		int a,b,w;
		fin >> a >> b >> w;
		graph[a-1][b-1] = min(graph[a-1][b-1],w);
	}

	vector<edge> edges;
	for (int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			if(graph[i][j] < INT_MAX)
			{
				edges.push_back(edge(i,j,graph[i][j]));
			}
		}
	}

	int res = 0;
	Kruscal(edges,res,N);

	cout << res << endl;

	//system("pause");
	return 0;
}