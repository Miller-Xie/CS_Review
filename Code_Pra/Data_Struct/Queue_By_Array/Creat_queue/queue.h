#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

#define MAX_SIZE 5

class queue
{
	int array[MAX_SIZE];

public:
	queue();
	int front();
	//int back();
	void push(int a);
	void pop();
	bool empty();
	int size();
	void clear();

private:
	int first;
	int rear;
};


#endif