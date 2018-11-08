#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int cnt = 0;

int is_ok(const vector<int>& vec)
{
	int len = vec.size();
	for(int i=0;i<len-1;i++)
	{
		int a = vec[i];
		int b = vec[i+1];
		if(a > b && a%b == 0)
			return false;
	}

	return true;
}

void recursion(vector<int>& vec,int i,const int k,const int n,set<vector<int>>& st)
{
	if(i == n)
	{
		//auto it = st.find(vec);
		//if(it == st.end() && is_ok(vec))
		if(is_ok(vec))
		{
			cnt++;
			//st.insert(vec);
		}

		return;
	}

	for(int j=1;j<=n;j++)
	{
		vec.push_back(j);
		recursion(vec,i+1,k,n,st);
		vec.pop_back();
	}
}

int main()
{
	int n,k;
	fstream in("test.txt");
	in >> n >> k;

	vector<int> vec;
	set<vector<int>> st; 
	vector<bool> visited(k,false);
	
	recursion(vec,0,k,n,st);

	cout << cnt << endl;
	//recursion();
	system("pause");
	return 0;
}