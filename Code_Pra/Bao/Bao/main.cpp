#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int cnt = 0;
int sum = 0;
set<int> Ast,Bst;
void recursion(int idx,int& sumA,int& sumB,const int& n,const int& c,vector<bool>& vis)
{
	if(idx == 6)
	{
		if(Ast.count(sumA) == 0 && Bst.count(sumB) == 0)
		{
			if(sumA == c && sumB != c)
			{
				cnt++;
				Ast.insert(sumA);
				Bst.insert(sumB);
			}
			sum++;
		}
		
	}

	
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				if(idx >=0 && idx < 3)
				{
					vis[i] = true;
					sumA += i;
					recursion(idx+1,sumA,sumB,n,c,vis);
					vis[i] = false;
					sumA -= i;
				}
				else
				{
					vis[i] = true;
					sumB += i;
					recursion(idx+1,sumA,sumB,n,c,vis);
					vis[i] = false;
					sumB -= i;
				}
			}
		}
}

int main()
{
	int n,c;
	cin >> n >> c;

	int idx = 0,sumA = 0,sumB = 0;
	vector<bool> vis(n,false);
	recursion(idx,sumA,sumB,n,c,vis);

	system("pause");
	return 0;
}