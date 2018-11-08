#include <bits/stdc++.h>
using namespace std;

class Empty{};

class HoldsAnInt:private Empty
{
public:
	int x;
	//Empty e;
};

int main()
{
	Empty e1;
	HoldsAnInt h;
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	
	char s[]={'a','s','3'};
	char s1[]={'1','4','s','\0'};
	char* s2="xcg";
	cout<<strlen(s)<<endl;
	cout<<strlen(s1)<<endl;
	cout<<strlen(s2)<<endl;
	cout << sizeof(int*) <<endl;
	cout<<sizeof(vec)<<endl;
	cout << sizeof(e1) << endl;
	cout << sizeof(h) << endl;
	return 0;
}