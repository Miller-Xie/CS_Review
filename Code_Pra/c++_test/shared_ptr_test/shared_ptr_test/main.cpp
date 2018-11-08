#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class ClassB;

class ClassA
{
public:
	ClassA() { cout << "ClassA Constructor..." << endl; }
	~ClassA() { cout << "ClassA Destructor..." << endl; }
	shared_ptr<ClassB> pb;  // 在A中引用B
	//weak_ptr<ClassB> pb;
};

class ClassB
{
public:
	ClassB() { cout << "ClassB Constructor..." << endl; }
	~ClassB() { cout << "ClassB Destructor..." << endl; }
	shared_ptr<ClassA> pa;  // 在B中引用A
	//weak_ptr<ClassA> pa;
};

int main() 
{
	/*shared_ptr<int> sp(new int(10));
	shared_ptr<int> sp1(sp);
	shared_ptr<int> sp2(new int(20));
	weak_ptr<int> wp = sp;

	shared_ptr<string> pstr(new string("xcg"));

	cout << pstr->size() << endl;
	cout << pstr->back() << endl;
	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	cout << wp.use_count() << endl;

	sp2 = sp;

	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	cout << wp.use_count() << endl;
	
	shared_ptr<int> sp3 = wp.lock();
	wp.reset();

	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	cout << wp.use_count() << endl;

	if(!sp.unique())
		sp.reset(new int(100));

	if(!wp.expired())
		cout << "cnt is not 0" << endl;

	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	cout << wp.use_count() << endl;*/
	//循环引用
	while (1)
	{
		shared_ptr<ClassA> spa = make_shared<ClassA>();
		shared_ptr<ClassB> spb = make_shared<ClassB>();
		spa->pb = spb;
		spb->pa = spa;

		std::cout << "spa use_cout:" << spa.use_count() << " spb use_cout:" << spb.use_count() << std::endl;//spa: 2 spb:2
	}
	

	
	
	// 函数结束，思考一下：spa和spb会释放资源么？ 超过作用于时引用计数减一，此时为2，减一后不为0，所以内存不释放
	//system("pause");
	return 0;
}