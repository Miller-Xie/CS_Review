#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};

void ser(TreeNode* root,string& str)
{
	if(!root)
	{
		str+="#,";
		return;
	}
	
	stringstream stream;
	stream<<root->val;
	str+=stream.str();
	str+=',';

	ser(root->left,str);
	ser(root->right,str);
}

char* Serialize(TreeNode *root) {    
	if(!root)
		return nullptr;
	string str;
	ser(root,str);
	str.pop_back();
	char* res=new char[str.size()+1];
	int i=0;
	for(;i<str.size();i++)
	{
		res[i]=str[i];
	}
	res[i]='\0';
	return res;
}

void des(TreeNode*& root,string str,int& n)
{
	if(str[n]=='#')
	{
		root=nullptr;
		n++;
		while(n<str.size() && str[n]==',')
			n++;

		return;
	}

	int flag=1;
	if(str[n]=='-')
	{
		flag=-1;
		n++;
	}
	int a=0;
	while(n<str.size() && str[n]!=',')
	{
		a=(str[n]-'0')+a*10;
		n++;
	}
	n++;
	a=a*flag;
	//root->val=a;

	root=new TreeNode(a);
	des(root->left,str,n);
	des(root->right,str,n);

}

TreeNode* Deserialize(char *str) {
	if(!str)
		return nullptr;

	string str_in;
	while(*str!='\0')
	{
		str_in.push_back(*str);
		str++;
	}
	TreeNode* root=nullptr;
	int a=0;
	des(root,str_in,a);

	return root;
}


int main()
{
	//char* s=new char[100];
	string s;
	//gets(s);
	ifstream inf("test.txt");
	//inf>>s;
	getline(inf,s,'\n');
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i];
	}
	cout<<endl;
	//cout<<s[2]<<endl;
	//TreeNode* head=Deserialize(s);
	//char* p=Serialize(head);


	system("pause");
	return 0;
}