#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

inline bool check_size(int a,int sz)
{
	return a>sz;
}
int main()
{
	auto func=[](const int a){cout<<a<<" ";};
	func(0);
	istream_iterator<int> in_ite(cin),eof;
	vector<int> vec;
	copy(in_ite,eof,back_inserter(vec));
	//lambdaµÄÊ¹ÓÃ
	//for_each(vec.begin(),vec.end(),
		[](const int& a){cout<<a<<" ";});
	//cout<<endl;

	auto check=bind(check_size,_1,10);
	int val=11;
	bool b=check(val);

    //auto ite=find_if(vec.begin(),vec.end(),bind(check_size,_1,sz));
	if(ite!=vec.end())
		cout<<*ite<<endl;

	vector<int> vec1;
	ostream_iterator<int> out_ite(cout," ");
	transform(vec.begin(),vec.end(),back_inserter(vec1),
		[](int i)->int
	   {if(i<0) return i;else return -i;});
	copy(vec1.begin(),vec1.end(),out_ite);
	//sort(vec.begin(),vec.end(),[](const int& a,const int& b){return a>b;});

	
	sort(vec.begin(),vec.end(),greater<int>());
	sort(vec.begin(),vec.end(),less<int>());
	for_each(vec.begin(),vec.end(),
		[](const int& a){cout<<a<<" ";});
	cout<<endl;

	system("pause");
	return 0;
}