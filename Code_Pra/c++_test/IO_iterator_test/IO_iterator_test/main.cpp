#include <iterator>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;


int main()
{
	istream_iterator<int> it(cin),eof;
	//vector<int> vec(it,eof);
	int arr[]={0,1,2,3,4,5};
	deque<int> deq(arr,arr+6);

	auto iter=back_inserter(deq);
	*iter=9;
	*iter = 8;
	copy(it,eof,inserter(deq,deq.begin()));

	ostream_iterator<int> out_it(cout," ");
	copy(deq.begin(),deq.end(),out_it);
	cout<<endl;
	copy(arr+1,arr+2,back_inserter(deq));
	copy(deq.begin(),deq.end(),out_it);
	cout<<endl;
	copy(arr+1,arr+2,front_inserter(deq));
	copy(deq.begin(),deq.end(),out_it);
	cout<<endl;
	//copy(vec.rbegin(),vec.rend(),out_it);
	cout<<endl;

	deque<int>::reverse_iterator rite(deq.end());
	cout<<*rite<<endl;
	rite++;
	cout<<*(rite.base())<<endl;
	system("pause");

	return 0;

}