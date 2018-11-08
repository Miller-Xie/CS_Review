#include "queue.h"
#include <stdexcept>

using namespace std;
queue::queue()
{
	first = rear = 0;
	for(int i=0;i<MAX_SIZE;i++)
	{
		array[i] = 0;
	}
}

int queue::front()
{
	if(first%MAX_SIZE == rear%MAX_SIZE) 
		throw overflow_error("queue is empty!!");
	int res = array[first%MAX_SIZE];
	//res = (res + 1)%MAX_SIZE;
	return res;
}

void queue::push(int a)
{
	if((rear+1)%MAX_SIZE == first%MAX_SIZE)
		throw overflow_error("queue is full!!");
	array[rear%MAX_SIZE] = a;
	rear++;
}

void queue::pop()
{
	if(first%MAX_SIZE == rear%MAX_SIZE) 
		throw overflow_error("queue is empty!!");
	//int res = array[first];
	first++;
	//return res;
}

bool queue::empty()
{
	if(first%MAX_SIZE == rear%MAX_SIZE)
		return true;
	return false;
}

int queue::size()
{
	return (rear-first)%MAX_SIZE;
}

void queue::clear()
{
	first = rear = 0;
	for(int i=0;i<MAX_SIZE;i++)
	{
		array[i] = 0;
	}
}
