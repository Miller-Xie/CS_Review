#include <iostream>
#include "stdio.h"
using namespace std;

class A
{
public:
	A(int arg):m_a(arg)
	{
		cout << "constructor of A" << endl;
		//this->output();
	}

	void func1()
	{
		this->output();
	}

	virtual void output()
	{ 
		cout << "output A" << endl;
	}

	virtual void display()
	{ 
		output(); 
	}

private:
	int m_a;
};

class B : public A
{
public:
	B(int arg1, int arg2):A(arg1), m_b(arg2)
	{ 
		cout << "constructor of B" << endl;
		//this->output();
	}

	virtual void output()
	{ 
		cout << "output B" << endl;
	}

	void func1()
	{
		this->output();
	}
private:
	int m_b;
};


int main(int argc, char* argv[])
{
	B b(1, 2);
	B b1(5,10);
	A* pa = &b;
	pa->func1();

	b.display();
	return 0;
}
