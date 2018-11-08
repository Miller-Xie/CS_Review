#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct thing
{
	//thing(int x=0,int y=0,int z=0):a(x),b(y),c(z){}
	int a,b,c;
};

bool lessAll(const thing& th1,const thing& th2)
{
	return (th1.a < th2.a) && (th1.b < th2.b) && (th1.c < th2.c);
}

bool lessA(const thing& th1,const thing& th2)
{
	return (th1.a < th2.a);
}


int main()
{
	int n;
	fstream in("test.txt");
	in >> n;
	vector<thing> vec(n,thing());
	for(int i=0;i<n;i++)
	{
		//for(int j=0;j<3;j++)
		//{
			int a,b,c;
			in >> a >> b >> c;
			vec[i].a = a;
			vec[i].b = b;
			vec[i].c = c;
		//}
	}

	int cnt = 0;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(is_ok(vec[i],vec[j]))
				cnt++;
		}
	}*/
	//vector<thing> vec1,vec2,vec3;
	sort(vec.begin(),vec.end(),lessA);
	
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if(lessAll(vec[i],vec[j]))
				cnt++;
		}
	}

	cout << cnt <<endl;
	system("pause");
	return 0;
}