#include <iostream>
#include <vector>
using namespace std;

class Num{
public:
	Num()
	{
		cnt++;
		sum+=cnt;
	}
	static int sum;
	static int cnt;
};
int Num::cnt=0;
int Num::sum=0;

class Solution {
public:
	int Sum_Solution(int n) {
		if(n==0)
			return 0;
		//Num::cnt=0;
		//Num::sum=0;
		Num* p=new Num[n];
		return Num::sum;
	}
};


int main()
{
	Solution a;
	int n;
	//cin>>n;
	//cout<<a.Sum_Solution(n)<<endl;

	cout<<(3)/(-5)<<endl;
	cout<<(3)%(-5)<<endl;
	system("pause");
	return 0;
}