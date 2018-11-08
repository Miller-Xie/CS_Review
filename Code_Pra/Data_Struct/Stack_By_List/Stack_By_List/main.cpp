//单链表实现栈：使用一个index指针指向栈顶元素，压栈过程采用链表的头插法,这样出栈的index向后移动即可
#include <bits/stdc++.h>
using namespace std;


class ListNode
{
public:
	int val;
	ListNode* next;
	ListNode(int a):val(a),next(nullptr){}
};



class Stack
{
public:
	Stack():index(nullptr){}
	void push(int a)
	{
		if(!index)
		{
			index=new ListNode(a);
			return;
		}
		ListNode* node=new ListNode(a);
		node->next=index;
		index=node;
	}
	void pop()
	{
		if(!index)
			throw "stack is empty!";

		ListNode* node=index;
		index=index->next;
		delete node;
	}

	int top()
	{
		if(!index)
			throw "stack is empty!";

		return index->val;
	}
	void clear()
	{
		while(index)
		{
			ListNode* node=index;
			index=index->next;
			delete node;
		}
		return;
	}
	int size()
	{
		int cnt=0;
		ListNode* cur=index;
		while(cur)
		{
			cnt++;
			cur=cur->next;
		}
		return cnt;
	}
private:
	//ListNode* first;
	ListNode* index;
};

int main()
{
	Stack sta;
	try{
		//sta.pop();
		sta.push(1);
		sta.push(2);
		sta.push(3);
		sta.pop();
		sta.pop();
		sta.pop();
		//sta.pop();
		cout<<sta.top()<<endl;
	}
	catch(char* str)
	{
		cout<<str<<endl;
	}
	

	system("pause");
	return 0;

}