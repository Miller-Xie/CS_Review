#include<iostream>
#include<string>
using namespace std;


//int main()
//{
char x=0;
class A{
public:
	A(){x=11;}
	virtual ~A(){x=12;}
	void func1(){x=13;}
	void func2(){func3();}//func1,func2±»Òþ²Ø
	virtual void func3(){x=14;}//func3±»ÖØÐ´
};

class B:public A{
public:
	B(){x=21;}
	virtual ~B(){x=22;}
	void func1(){x=23;}
	void func2(){func3();}
	virtual void func3(){x=24;}
};


int main()
{
	B testb;
	B* testc;
	A* testa;

	void (A::*pmf)() = &A::func3;
	//(A::*pmf1)() = &A::~A;
	A* ptr = new B;
	ptr->func3();
	(ptr->*pmf)();
	//cout << &B::~B << endl;
	//cout << pmf1 <<endl;
	cout << pmf <<endl;
	cout << ptr << endl;
	//cout << &testb << endl;
	testa=&testb;
	cout << testa <<endl;
	testa++;
	cout << testa <<endl;
	//cout << testa << endl;
	//testa = new B;
	testa->func3();

	testc=new B;

	delete testc;

	testa->func2();

	return 0;
}
