#include <iostream>
#include "unique.h"
using namespace std;


int main()
{
	my_unique<int> up(new int(10));
	//my_unique<int> up1(up);
	auto p = up.get_ptr();
	int a = *up;
	
	cout << a << endl;
	system("pause");

	return 0;
}