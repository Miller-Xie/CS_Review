#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct tree
{
	bool flag;
	int num;
	tree *next[26];
	tree()
	{
		flag = false;
		num = 0;
		for(int i = 0; i<26;i++)
			next[i] = NULL;
	}
};

void add_tree(tree *p,string s)
{
	for(int i = 0; i< s.size();i++)
	{
		if(p->next[s[i]-'a']==NULL)
		{
			p->next[s[i]-'a'] = new tree;
		}
		p = p->next[s[i]-'a'];
		p->num++;
	}
	p->flag = true;
}

tree* build_tree(const vector<string>& vec)
{
	tree * head = new tree;
	for(int i = 0; i<vec.size();i++)
	{
		tree *p = head;
		add_tree(p,vec[i]);
	}
	return head;
}

string find_tree(tree* p,const string& s)
{
	tree *m = p;
	string s1="";
	for(int i = 0;i<s.size();i++)
	{
		s1 +=s[i];
		if(m->next[s[i]-'a']->num==1)
			break;
		m = m->next[s[i]-'a'];
	}
	return s1;
}

int main()
{
	int n; 
	while(cin>>n)
	{
		vector<string> vec;
		string s;
		for(int i = 0; i<n; i++)
		{
			cin>>s;
			vec.push_back(s);
		}

		tree *p = build_tree(vec);
		for(int i = 0; i< vec.size();i++)
		{
			string s;
			s = find_tree(p,vec[i]);
			cout<<s<<endl;
		}
	}

	system("pause");
	return 0;
}