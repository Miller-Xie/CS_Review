#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


string ReverseSentence(string str) {
	if(str.size()==0)
		return str;

	reverse(str.begin(),str.end());
	auto pre=str.begin();
	for(auto it=str.begin();it!=str.end();it++)
	{
		if(*it==' ')
		{
			reverse(pre,it);
			while(*it==' ')
				it++;
			pre=it;
		}
	}
	reverse(pre,str.end());

	return str;
}

int main()
{
	string str;
	//stringstream stream;
	while(getline(cin,str,'\n'))
	{
		ReverseSentence(str);
		cout<<str<<endl;
	}

	system("pause");
	return 0;
}