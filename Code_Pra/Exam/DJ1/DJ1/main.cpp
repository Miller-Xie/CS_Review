#include <vector>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

bool check(int a,int b,vector<vector<int>> vec)
{
	for(unsigned int i=0;i<vec.size();i++)
	{
		if(vec[i][b]!=1)
			return false;
	}
	for(unsigned int i=0;i<vec[0].size();i++)
	{
		if(vec[a][i]!=1)
			return false;
	}
	return true;
}

bool check1(int a,int b,vector<vector<int>>& vec,vector<vector<bool>>& vst)
{
	for(unsigned int i=0;i<vec.size();i++)
	{
		if(vec[i][b]!=1)
			return false;
		else
			vst[i][b]=true;
	}
	for(unsigned int i=0;i<vec[0].size();i++)
	{
		if(vec[a][i]!=1)
			return false;
		else
			vst[a][i]=true;
	}

	/*for (unsigned int i=0;i<vec.size();i++)
	{
		for (unsigned int j=0;j<vec[0].size();j++)
		{
			if(i!=a && j!=b && vec[i][j]==1)
				return false;
		}
	}*/
	//return true;
}

void clear_hl(int a,int b,vector<vector<int>>& vec)
{
	for(unsigned int i=0;i<vec.size();i++)
	{
		vec[i][b]=0;
	}
	for(unsigned int i=0;i<vec[0].size();i++)
	{
		vec[a][i]=0;
	}
}

bool allClear_if(vector<vector<int>> vec)
{
	for (unsigned int i=0;i<vec.size();i++)
	{
		for (unsigned int j=0;j<vec[0].size();j++)
		{
			if(vec[i][j]!=0)
				return false;
		}
	}
	return true;
}

bool Solution(vector<vector<int>> vec)
{
	string res;
	int cnt=0;
	int h=vec.size();
	int l=vec[0].size();
	vector<vector<int>> sw(h,vector<int>(l,-1));
	vector<vector<bool>> visited(h,vector<bool>(l,false));
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<l;j++)
		{
			if(vec[i][j]==0)
				clear_hl(i,j,sw);
			if(vec[i][j]==1)
				cnt++;
		}
	}

	if(allClear_if(sw))
	{
		if(cnt==0)
			return true;
		else
			return false;
	}
	else
	{
		for(int i=0;i<h;i++)
		{
			for (int j=0;j<l;j++)
			{
				if(sw[i][j]==-1 && !check1(i,j,vec,visited))
				{
					return false;
				}
			}
		}
	}

	for (int i=0;i<h;i++)
	{
		for (int j=0;j<l;j++)
		{
			if(!visited[i][j]&&vec[i][j]==1)
				return false;
		}
	}

	return true;
}

int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	vector<vector<int >> input;
	for(int i=0;i<n;i++)
	{
		vector<int> vec;
		for (int j=0;j<m;j++)
		{
			int a;
			cin>>a;
			vec.push_back(a);
		}
		input.push_back(vec);
	}

	if(Solution(input))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	system("pause");
	return 0;
}