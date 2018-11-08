#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;



int main()
{
	int n;
	vector<int> nums;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		nums.push_back(a);
	}

	int Max = INT_MIN;
	for (int i=0;i<n;i++)
	{
		Max = max(nums[i],Max);
	}

	cout << Max - 1 << endl;

	//system("pause");
	return 0;
}