#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
	queue que;
	que.push(0);
	que.push(1);
    que.push(2);
	que.push(3);
	//que.push(4);

	cout << "the queue front is: " << que.front() << endl;
	cout << "the queue size is: " << que.size() << endl;

	que.pop();
	cout << "the queue front is: " << que.front() << endl;
	cout << "the queue size is: " << que.size() << endl;
	
	que.push(5);
	cout << "the queue front is: " << que.front() << endl;
	cout << "the queue size is: " << que.size() << endl;


	que.clear();
	//cout << "the queue front is: " << que.front() << endl;
	cout << "the queue size is: " << que.size() << endl;

	system("pause");
}