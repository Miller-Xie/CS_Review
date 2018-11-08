#include <iostream> 
#include <cstring> 
using namespace std; 



class ClassTest 
{ 
public: 
	ClassTest() 
	{ 
		c[0] = '\0'; 
		cout<<"ClassTest()"<<endl; 
	} 
	ClassTest& operator=(const ClassTest &ct) 
	{ 
		strcpy(c, ct.c); 
		cout<<"ClassTest& operator=(const ClassTest &ct)"<<endl; 
		return *this; 
	} 

	ClassTest(const char *pc) 
	{ 
		strcpy(c, pc); 
		cout<<"ClassTest (const char *pc)"<<endl; 
	}

//private: 
	ClassTest(const ClassTest& ct) 
	{ 
		strcpy(c, ct.c); 
		cout<<"ClassTest(const ClassTest& ct)"<<endl; 
	} 

private: 
	char c[256]; 
}; 


int main() 
{ 
	cout<<"ct1: "; 
	ClassTest ct1("ab");//直接初始化 
	cout<<"ct2: "; 
	ClassTest ct2 = "ab";//拷贝初始化 
	cout<<"ct3: "; 
	/*ClassTest ct3 = ct1;//拷贝初始化 
	cout<<"ct4: "; */
	ClassTest ct4(ct1);//直接初始化 
	cout<<"ct5: "; 
	//ClassTest ct5 = ClassTest();//默认初始化 

	system("pause");
	return 0; 
} 