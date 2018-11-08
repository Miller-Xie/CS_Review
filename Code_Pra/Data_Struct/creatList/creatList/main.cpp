#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
	//ListNode();
	/*ListNode(int i):
	val(i),next(nullptr){

	}*/
};

//Î²²å·¨´´½¨
void Tail_creatList(ListNode* &Head,vector<int> vec)
{
	Head = new ListNode();
	//if(!Head)
	//throw runtime_error("point invalid");
	Head->val = vec[0];
	ListNode* tail = Head;
	int size = vec.size();
	for(int i=1;i<size;i++){
		ListNode* p = new ListNode();
		p->val = vec[i];
		p->next = nullptr;
		tail->next = p;
		tail = p;
	}
	//Head = Head->next;

}

void Head_creatList(ListNode* &ListHead,vector<int> vec)
{
	//ListHead = new ListNode();

	ListNode* head = ListHead;
	//head->next = nullptr;
	for(unsigned i=0;i < vec.size();i++){
		ListNode* p=new ListNode();
		
		p->val=vec[i];
		p->next=head;
		head=p;
	}
	ListHead = head;
}

int main(int argc,char* argv[])
{
	int a;
	vector<int> vec;
	while(cin >> a)
	{
		vec.push_back(a);
		if(cin.get()=='\n')
			break;
	}

	ListNode* ListHead = nullptr;
	Tail_creatList(ListHead,vec);
	//Head_creatList(ListHead,vec);
	ListNode* p = ListHead;
	while(p){
		cout << p->val <<endl;
		p = p->next;
	}
	system("pause");
	return 0;

}