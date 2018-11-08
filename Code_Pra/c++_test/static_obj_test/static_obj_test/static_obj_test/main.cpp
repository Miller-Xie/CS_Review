#include <iostream>
class Test
{
public:
	Test()
	{
		std::cout << "Constructor is executed\n";
	}
	~Test()
	{
		std::cout << "Destructor is executed\n";
	}
};

void myfunc()
{
	static Test obj;
} // 函数结束时，obj不会被消耗，因为是静态对象。

int main()
{
	std::cout << "main() starts\n";
	//myfunc();    // 这里不会调用析构函数，因为函数体中分配的是静态对象。
	std::cout << "main() terminates\n";
	return 0;
}
