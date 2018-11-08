#include <vector>
#include <iostream>
using namespace std;


int main()
{
	vector<int> vec;
	vec.reserve(100);
	vec.resize(50);

	vec.resize(130);

	cout << vec.capacity() << endl;

	vec.push_back(10);
	cout << vec.capacity() << endl;

	vec.resize(300);
    cout << vec.capacity() << endl;

	vec.push_back(10);
	cout << vec.capacity() << endl;

	return 0;
}