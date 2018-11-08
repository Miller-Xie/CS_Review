#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
using namespace std;

class TreeNode
{
public:
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char a):val(a),left(nullptr),right(nullptr){}
};



void PreOrder_NonRecur(TreeNode* head)
{
	stack<TreeNode* > sta;
	if(!head)
		return;
	sta.push(head);
	while(!sta.empty())
	{
		TreeNode* cur=sta.top();
		sta.pop();

		cout << cur->val <<" "; 

		if(cur->right)
			sta.push(cur->right);
		if(cur->left)
			sta.push(cur->left);
	}
	cout<<endl;
	return;
}

void InOrder_NonRecur(TreeNode* head)
{
	if(!head)
		return;
	stack<TreeNode*> sta;
	while (!sta.empty() || head)
	{
		while(head)
		{
			sta.push(head);
			head=head->left;
		}
		head=sta.top();
		sta.pop();
		cout<<head->val<<" ";
		head=head->right;
	}
	cout<<endl;
}

void PosOrder_Tree(TreeNode* head)
{
	if(!head)
		return;
	stack<TreeNode*> sta1;
	stack<TreeNode*> sta2;
	sta1.push(head);
	while(!sta1.empty())
	{
		head=sta1.top();
		sta2.push(head);
		sta1.pop();
		if(head->left)
			sta1.push(head->left);
		if(head->right)
			sta1.push(head->right);
	}
	while (!sta2.empty())
	{
		cout<<sta2.top()->val<<" ";
		sta2.pop();
	}
	cout<<endl;
	return;
}

void PosOrder_Tree1(TreeNode* head)
{
	
}

//先序输入建立二叉树
void PreCreatBiTree(TreeNode* &T,queue<char>& que)
{
	char ch;
	//scanf("%s",&ch);
	//ch = getchar();
	if(!que.empty())
	{
		ch=que.front();
		que.pop();
	}
	else
		return;

	if( ch == '#')
	{
		T = nullptr;
		return;
	}
	else{
		T = new TreeNode(ch);
		//T->data = ch;
		PreCreatBiTree(T->left,que);
		PreCreatBiTree(T->right,que);
	}
}

//层序建立二叉树
TreeNode* LayCreatBiTree(queue<char> que)
{
	if(que.empty())
		return nullptr;

	queue<TreeNode*> que1; 
	char ch=que.front();
	que.pop();
	TreeNode* head=new TreeNode(ch);

	que1.push(head);
	while (!que1.empty())
	{
		TreeNode* cur=que1.front();
		que1.pop();

		if(!que.empty())
		{
			ch=que.front();
			que.pop();
			if(ch=='#')
				cur->left=nullptr;
			else
				{
					TreeNode* l_node=new TreeNode(ch);
			        cur->left=l_node;
					que1.push(l_node);
			    }
		}
		if(!que.empty())
		{
			ch=que.front();
			que.pop();
			if(ch=='#')
				cur->right=nullptr;
			else
			{
				TreeNode* r_node=new TreeNode(ch);
				cur->right=r_node;
				que1.push(r_node);
			}
			
		}
	}
	return head;
}

int main()
{
	queue<char> que;
	int n;
	char a;
	//ifstream inf(.\test.txt);

	/*char ch;
	cin>>ch;
	if(ch=='#')
	{
		cout << "yes" <<endl;
		system("pause");
		return 0;
	}*/
		
	/*cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		que.push(a);
	}*/
	string str;
	getline(cin,str,'\n');
	for (int i=0;i<str.size();i++)
	{
		que.push(str[i]);
	}
	//PreCreatBiTree(root,que);
	TreeNode* root=LayCreatBiTree(que);
	PreOrder_NonRecur(root);
	InOrder_NonRecur(root);
	PosOrder_Tree(root);
	system("pause");
	return 0;
}