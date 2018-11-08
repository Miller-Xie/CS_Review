#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



int main()
{
	long n;
	fstream fin("test.txt");
	fin >> n;
	long a1,b1,v1,a2,b2,v2;
	while(n--)
	{
		fin >> a1 >> b1 >> v1 >> a2 >> b2 >> v2;
		long a = b1*a2 - a1*b2;
		long b = v1*a2 - v2*a1;
		float x,y;
		if(b == 0)
		{
			cout << "UNKONWN" <<endl;
		}
		else{
			x = (float(a))/(float(b));
			long tmpx = (long)x;
			if(tmpx <= 0)
			{
				cout << "UNKONWN" <<endl;
				continue;
			}

			if(tmpx - x != 0)
			{
				cout << "UNKONWN" <<endl;
				continue;
			}
			else{
				y = ((float)(v1 - b1*x))/((float)a1);
				long tmpy = (long)y;
				if(tmpy <= 0)
				{
					cout << "UNKONWN" <<endl;
					continue;
				}

				if(y - tmpy != 0)
				{
					cout << "UNKONWN" <<endl;
					continue;
				}
				else{
					cout << (long)y << " " <<  (long)x << endl;
				}
			}
		}
	}

	system("pause");
	return 0;
}