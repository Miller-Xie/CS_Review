#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int cnt = 0;


void recursion(vector<int>& nums,int n)
{
	if(n == nums.size())
		cnt++;

	int sum=0;
	for(int i=n;i<nums.size();i++)
	{
		sum += nums[i];
		if(sum == 0)
			continue;
		else if(sum == 1)
		{
			recursion(nums,i+1);
		}
		else 
			break;
	}
}

int main()
{
	fstream fin("test.txt");
	int n;
	vector<int> nums;
	fin >> n;
	for (int i=0;i<n;i++)
	{
		int a;
		fin >> a;
		nums.push_back(a);
	}

	recursion(nums,0);

	cout <<cnt << endl;
	system("pause");
	return 0;
}