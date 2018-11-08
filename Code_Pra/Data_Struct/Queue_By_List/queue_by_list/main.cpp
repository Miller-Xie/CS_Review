#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int a):val(a),next(nullptr){}
};

class queue
{
public:
	queue():first(nullptr),rear(nullptr){}
	void clear();
	int size();
	bool empty();
	void push(int a);
	void pop();
	int front();
	//int back();

private:
	ListNode* first;
	ListNode* rear;
};

void queue::clear()
{
	if(empty())
		return;
	while(first)
	{
		ListNode* node = first;
		first = first->next;
		delete node;
	}
	first = rear = nullptr;
}

int queue::size()
{
	int count=0;
	if(empty())
		return 0;
	ListNode* node = first;
	while(node)
	{
		count++;
		node=node->next;
	}
	return count;
}

bool queue::empty()
{
	if(!first && !rear)
		return true;
	return false;
}

void queue::push(int a)
{
	if(!first && !rear)
	{
		first = new ListNode(a);
	    rear=first;
	}
	else
	{
		ListNode* node = new ListNode(a);
		rear->next = node;
		rear=node;
	}
	//node->next=rear;
	//first=node;
}

void queue::pop()
{
	if(!empty())
	{
		ListNode* node = first;
		first = first->next;
		delete node;//×¢ÒâÊÍ·ÅÄÚ´æ
	}
	else
		throw overflow_error("the queue is empty!!");

}

int queue::front()
{
	if(!empty())
		return first->val;
	else
		throw overflow_error("the queue is empty!!");
}


int main()
{
	queue que;
	que.push(0);
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);

	//que.pop();
	cout <<"the queue front is: "<<que.front()<<endl;
	cout<<"the queue size is:" << que.size()<<endl;

	que.clear();
	//cout <<"the queue front is: "<<que.front()<<endl;
	cout<<"the queue size is:" << que.size()<<endl;
	system("pause");
	return 0;

}

