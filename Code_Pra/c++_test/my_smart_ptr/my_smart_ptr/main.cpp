#include <iostream>
#include "smart.h"

using namespace std;


int main()
{
	smart_ptr<int> sp(new int(10));
	smart_ptr<int> sp1(sp);
	smart_ptr<int> sp2(new int(20));
	//smart_ptr<double> sp4;
	//weak_ptr<int> wp = sp;
	cout << sp.use_cnt() << endl;
	cout << sp1.use_cnt() << endl;
	cout << sp2.use_cnt() << endl;
	//cout << wp.use_cnt() << endl;

	sp2 = sp;

	cout << sp.use_cnt() << endl;
	cout << sp1.use_cnt() << endl;
	cout << sp2.use_cnt() << endl;
	//cout << wp.use_cnt() << endl;

	system("pause");
	return 0;
}