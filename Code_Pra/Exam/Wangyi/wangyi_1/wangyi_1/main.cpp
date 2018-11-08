#include <string>
#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;



bool is_ok(const string& str)
{
	int cnt = 0;
	for (int i=0;i<str.size()-1;i++)
	{
		if(str[i] != str[i+1])
			cnt++;
	}

	if(cnt > 1)
		return false;

	return true;
}

void recursion(int n,string& str,unordered_set<string>& st)
{
	int len = str.size();
	if(n == len)
	{
		auto it = st.find(str);
		if(it == st.end())
		{
			if(is_ok(str))
			{
				st.insert(str);
			}
		}
		
		return;
	}

	for(int i=n;i<str.size();i++)
	{
		swap(str[n],str[i]);
		recursion(n+1,str,st);
		swap(str[n],str[i]);
	}
}

int main()
{
	string str;
	fstream in("test.txt");
	in >> str;
	int res = 0;
	unordered_set<string> st;
	recursion(0,str,st);

	/*for(auto it = st.begin();it!=st.end();it++)
	{
		auto a = *it;
		if(is_ok(a))
			res++;
	}*/

	
	cout << st.size() << endl;
	system("pause");
	return 0;

}