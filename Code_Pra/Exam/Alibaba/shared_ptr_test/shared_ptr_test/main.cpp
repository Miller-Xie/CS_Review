#include <vector>
#include <memory>
using namespace std;

class B;
class A
{
public:
	　　shared_ptr<B> m_b;
};

class B
{
public:
	　　shared_ptr<A> m_a;
};

int main()
{
	while(true)
	{
			　　　shared_ptr<A> a(new A); //new出来的A的引用计数此时为1
				　shared_ptr<B> b(new B); //new出来的B的引用计数此时为1
				a->m_b = b; //B的引用计数增加为2
						　　　　b->m_a = a; //A的引用计数增加为2
	  　　}

	  　　//b先出作用域，B的引用计数减少为1，不为0，所以堆上的B空间没有被释放，且B持有的A也没有机会被析构，A的引用计数也完全没减少

	  　　//a后出作用域，同理A的引用计数减少为1，不为0，所以堆上A的空间也没有被释放

}