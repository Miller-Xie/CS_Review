#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdio.h>
#include <memory>
using namespace std;

class Point3d{
public:
	//virtual ~Point3d(){}
	
public:
	static Point3d origin;
	float x,y,z;
};

int  main()
{  
	//istream_iterator<int> in_iter(cin),eof;
	//vector<int> vec(in_iter,eof);

	cout << sp.use_count() << endl;
	char str1[] = "Wuhan nihao!";
	char str2[] = "Wuhan nihao!";
	char* str3 = "Hello Word";
	char* str4 = "Hello Word";
	int arr[2][3] = {{1,2,3},{4,5,6}};
	int (*p)[3];
	p = arr;

	int* pi = new int[10]();//会初始化为0
	int* pi2 = new int[10];//不会初始化
	char* p1 = new char[10];

	cout << str1 << endl;
	cout << str2 << endl;
	cout << *(&str3) << endl;
	cout << str4 << endl;
	//cout << sizeof(p1) << endl;
	/*cout << sizeof(str) << endl;
	cout << sizeof(str1) << endl;
	cout << sizeof(*str1) << endl;
	cout << strlen(str) << endl;
	cout << strlen(str1) << endl;*/
	/*cout << arr <<endl;
	cout << arr[0] <<endl;
	cout << *arr << endl;
	cout << arr[1] <<endl;
	cout << *(arr+1) << endl;

	cout << (*(arr+2) - arr[0]) <<endl;

	cout << *(*(p + 1) + 2) <<endl;
	cout << *(arr[0] + 2) << endl;
	cout << *( *(*(&arr + 1) - 1) + 1) << endl;*/
	//printf("%s\n",str);
	//int arr[5]={1,2,3,4,5};
	//vector<int> vec(arr,arr+5);
	//vector<int> vec1(vec.size(),0);

	//adjacent_difference(vec.begin(),vec.end(),vec1.begin(),plus<int>());

	system("pause");
	return 0;
}