#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <fstream>
using namespace std;

int Max = INT_MIN;

void recursion(vector<vector<int>>& vec,vector<int>&cnt,int n,int& res)
{
	const int h = vec.size();
	const int l = vec[0].size();
	if(n == vec.size())
	{
		Max = max(Max,res);
		//res = 0;
		return;
	}

	
	for (int i=0;i<l;i++)
	{
		if(cnt[i] > 0)
		{
			cnt[i]--;
			res += vec[n][i];
			recursion(vec,cnt,n+1,res);
			res -= vec[n][i];
			cnt[i]++;
		}
	}

	Max = max(Max,res);
}

int main()
{
	fstream fin("test.txt");
	int a;
	fin >> a;
	while(a--)
	{
		int n,m,k;
		fin >> n >> m >> k;
		vector<vector<int>> nums(n,vector<int>(m));
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				int a;
				fin >> a;
				nums[i][j] = a;
			}
		}

		vector<int> cnt(m,k);
		int res = 0;
		recursion(nums,cnt,0,res);

		cout << Max << endl;
		Max = INT_MIN;
	}
	
	system("pause");
	return 0;
}