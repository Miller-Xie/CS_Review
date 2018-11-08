#include <iostream>
using namespace std;

void recursion(int i,int n,int& res,int cnt)
{
	if(i > 9)
	{
		i = i%10;
	}
	else if(i < 0)
	{
		i = (10+i)%10;
	}

	if(cnt == n)
	{
		if(i == 0)
			res++;

		return;
	}

	recursion(i+1,n,res,cnt+1);
	recursion(i-1,n,res,cnt+1);
}

int get_res(int n)
{
	int res = 0;
	int cnt = 0;  
	recursion(0,n,res,cnt);

	return res;
}

int main()
{
	int n;
	cin >> n;

	cout << get_res(n) << endl;

	system("pause");
	return 0;
}