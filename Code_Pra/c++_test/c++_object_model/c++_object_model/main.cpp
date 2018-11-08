#include <iostream>

using namespace std;

class Point
{
public:
	virtual ~Point();
	float x();
	float y();
	virtual float z();
	virtual float a();
};

int main()
{
	//Point p;
	//float (Point:: *pmf1)()=&(Point::~Point);
	float (Point::*pmf)()=&Point::z;
	float (Point:: *pmf1)()=&Point::x;
	cout << pmf << endl;
	cout << pmf1 <<endl;
	//cout <<(&Point::x)
	system("pause");
	return 0;
}