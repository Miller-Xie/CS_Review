#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool is_ok(vector<int> vec)
{
	for (unsigned int i=0;i<vec.size()-1;i++)
	{
		if(vec[i]>vec[i+1])
			return false;
	}
	return true;
}

//递归方法时间复杂度及其之高，不可取O(n^2n)
void recursion(vector<int> vec,int& min,int cnt,int a,int b)
{
	int len=vec.size();
	if(is_ok(vec))
	{
		if(min==0)
			min=cnt;
		else if(cnt<min)
			min=cnt;
		return;
	}

	if(cnt>=vec.size())
		return;
	for(unsigned int i=0;i<len-1;i++)
	for(unsigned int j=i+1;j<len;j++)
	{
		if(i!=a && j!=b)
		{
			if(i==0 && j==len-1)
				continue;
			if(vec[i]==vec[j] && j==i+1)
				continue;
			reverse(vec.begin()+i,vec.begin()+j+1);
			recursion(vec,min,cnt+1,i,j);
			//recursion(vec,min,cnt);
			reverse(vec.begin()+i,vec.begin()+j+1);
		}
	}
}



int main()
{
	int n,a,k;
	cin>>n;
	//cin>>k;
	vector<int> vec;
	for (int i=0;i<n;i++)
	{
		cin>>a;
		vec.push_back(a);
	}

	int min=0;
	int cnt=0;
	recursion(vec,min,cnt,-1,-1);
	
	cout<<min<<endl;
	system("pause");
	return 0;
}