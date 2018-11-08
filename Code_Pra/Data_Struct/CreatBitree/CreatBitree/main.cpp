#include <iostream>
#include "stdio.h"
#include <string>

using namespace std;

struct TreeNode{
	char data;
	struct TreeNode *left,*right;
	TreeNode(char i):
	data(i),left(nullptr),right(nullptr){

	}
};


//先序输入建立二叉树
void creatBiTree(TreeNode* &T)
{
	char ch;
	//scanf("%s",&ch);
	ch = getchar();
			if( ch == '#')
			{
				T = nullptr;
				//return 0;
			}
			else{
				T = new TreeNode(ch);
				//T->data = ch;
				creatBiTree(T->left);
				creatBiTree(T->right);
			}
}

//先序遍历二叉树
void PreOrderTree(TreeNode* &T)
{
	if(T)
	{
		cout<<T->data;
		PreOrderTree(T->left);
		PreOrderTree(T->right);
	}
	else
		cout << '#';

}

void InOrderTree(TreeNode* &T)
{
	if(T)
	{
		InOrderTree(T->left);
		cout << T->data;
		InOrderTree(T->right);
	}
	else
		cout << '#';
}

bool IsSubtree(TreeNode* p1,TreeNode* p2)
{
	if(!p2)
		return true;
	else if(!p1)
		return false;
	else if(p1->data != p2->data)
		return false;
	return IsSubtree(p1->left,p2->left) && IsSubtree(p1->right,p2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;
	if(pRoot1 && pRoot2)
	{
		if(pRoot1->data == pRoot2->data)
			result = IsSubtree(pRoot1,pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->left,pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->right,pRoot2);
	}
	return result;

}


int main()
{
	TreeNode* pRoot1,* pRoot2;

	creatBiTree(pRoot1);
	fflush(stdin);
	creatBiTree(pRoot2);

	if(HasSubtree(pRoot1,pRoot2))
		cout << "Is SubTree" << endl;
	else
		cout << "Is not SubTree" << endl;
	system("pause");

	return 0;

}


