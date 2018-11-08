#include <iostream>
using namespace std;

class B
{  
public:
	virtual void f() { cout<< "f()" <<endl; }
};
class D : public B
{
public:
	void m(){cout<< "m()" <<endl;}
}; 
int main()
{
	B* pb=new B;
	D* pd1=new D;
	D* pd = static_cast<D*>(pb); 
	pd -> m();   // ...
	return 0;    
}