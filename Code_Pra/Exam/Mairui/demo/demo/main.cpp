#include<iostream>
using namespace std;


class foo{
public:
	static char a[4];
	virtual int func(){};
};

char foo::a[4]={'4','5','6','7'};

class bar:public foo{
private:
	char *p;
};

int main()
{	
	char *p1 = foo::a + 2;
	char *p2 = (char*)(&foo::a + 1);

	cout<<sizeof(foo);
	cout<<sizeof(bar);
	cout<<*(foo::a + 1);

	cout<<*p1;
	cout<<*(p2 -1 );
	cout<<foo::a[p2-p1] ;

	return 0;
} 