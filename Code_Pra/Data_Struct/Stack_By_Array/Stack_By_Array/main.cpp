#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 10

class Stack
{
public:
	Stack():index(0){}
	void pop()
	{
		if(index<0)
			throw "stack is empty";
		index--;
	}
	void push(int a)
	{
		if(index>=MAXSIZE)
			throw "stack is full";
		array[index++]=a;
	}
	int top()
	{
		if(index<0)
			throw "stack is empty";
		return array[index-1];
	}
	void clear()
	{
		index=-1;
		return;
	}
	

private:
	int array[MAXSIZE];
	int index;
};

int main()
{
	Stack sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);

	try
	{
		cout << sta.top()<<endl;
		sta.pop();
		cout<<sta.top()<<endl;
		//sta.clear();
		//cout<<sta.top()<<endl;
		sta.push(5);
		sta.push(5);
		sta.push(5);
		sta.push(5);
		sta.push(5);
		sta.push(5);
		sta.push(5);
		sta.push(5);
	}
	catch(char* str)
	{
		cout<<str<<endl;
	}
	
	system("pause");

	return 0;

}


