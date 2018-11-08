#include <vector>
#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;


int recursion(int x,int y,const vector<vector<int>>& vec,vector<vector<int>>& dp)
{
	if(dp[x][y] != 0)
		return dp[x][y];

	int row = vec.size();
	int col = vec[0].size();

	dp[x][y] = 1;

	if(x > 0 && vec[x-1][y] > vec[x][y])
	{
		int cnt = recursion(x-1,y,vec,dp) + 1;
		dp[x][y] = max(dp[x][y],cnt);
	}

	if(x < row - 1 && vec[x+1][y] > vec[x][y])
	{
		int cnt = recursion(x+1,y,vec,dp) + 1;
		dp[x][y] = max(cnt,dp[x][y]);
	}

	if(y > 0 && vec[x][y-1] > vec[x][y])
	{
		int cnt = recursion(x,y-1,vec,dp) + 1;
		dp[x][y] = max(dp[x][y],cnt);
	}

	if(y < col - 1 && vec[x][y+1] > vec[x][y])
	{
		int cnt = recursion(x,y+1,vec,dp) + 1;
		dp[x][y] = max(dp[x][y],cnt);
	}

	return dp[x][y];
}


int longestIncreasingPath(vector<vector<int>>& matrix) {
	if(matrix.empty()) return 0;

	int row = matrix.size();
	int col = matrix[0].size();

	vector<vector<int>> dp(row,vector<int>(col,0));
	int res = INT_MIN;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
		{
			int a = recursion(i,j,matrix,dp);
			res = max(res,a);
		}

		return res;
}

int main()
{
	fstream fin("test.txt");

	int n,m;
	fin >> n >> m;
	vector<vector<int>> nums(n,vector<int>(m,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int a;
			fin >> a;
			nums[i][j] = a;
		}

	cout << longestIncreasingPath(nums) <<endl;

	return 0;
}