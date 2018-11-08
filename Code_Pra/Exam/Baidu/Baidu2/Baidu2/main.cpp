#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
struct Point
{
	int x;
	int y;
};
int calculate(vector<int> v,Point *p, int *next)
{
	double min = 10000;
	int min_1=0,min_2=0;
	for(int i = 0; i<v.size();i++)
	{
		for(int j = i+1; j<v.size();j++)
		{
			int x = p[v[i]].x-p[v[j]].x;
			int y = p[v[i]].y-p[v[j]].y;
			double r = sqrt((double)(x*x)+(double)(y*y));
			if(r<min)
			{
				min = r;
				min_1=v[i];
				min_2=v[j];
			}
		}
	}
	int re = (int)min;
	next[min_1] = 1;
	next[min_2] = 1;
	return re;
}
int strategy_x(int num,Point *p,int *range,int *next)
{
	int x1 = range[1],x2=range[2];
	int o;
	if(x1>x2)
	{
		o = x1;
		x1 = x2;
		x2 = o;
	}
	vector<int> v;
	for(int i = 0; i<num;i++)
	{
		if(next[i]==0&&p[i].x>x1&&p[i].x<x2)
			v.push_back(i);
	}
	int sum = calculate(v,p,next);
	return sum;
}
int strategy_y(int num,Point *p,int *range,int *next)
{
	int y1 = range[1],y2=range[2];
	int o;
	if(y1>y2)
	{
		o = y1;
		y1 = y2;
		y2 = o;
	}
	vector<int> v;
	for(int i = 0; i<num;i++)
	{
		if(next[i]==0&&p[i].y>y1&&p[i].y<y2)
			v.push_back(i);
	}
	int sum = calculate(v,p,next);
	return sum;
}
int strategy_xy(int num,Point *p,int *range,int *next)
{
	int x1 = range[1],x2=range[2],y1 = range[3],y2=range[4];
	int o;
	if(x1>x2)
	{
		o = x1;
		x1 = x2;
		x2 = o;
	}
	if(y1>y2)
	{
		o = y1;
		y1 = y2;
		y2 = o;
	}
	vector<int> v;
	for(int i = 0; i<num;i++)
	{
		if(next[i]==0&&p[i].x>x1&&p[i].x<x2&&p[i].y>y1&&p[i].y<y2)
			v.push_back(i);
	}
	int sum = calculate(v,p,next);
	return sum;
}
vector<int> nearestLoc(int num, Point* locCoordinates,int tripCount,int tripDetails[][5])
{
	vector<int> vec;
	int *next;
	next = new int[num];
	for(int i = 0;i<num;i++)
		next[i] = 0;
	for(int i = 0; i<tripCount; i++)
	{
		int flag = tripDetails[i][0];
		int m = 0;
		if(flag == 1)
			m = strategy_x(num,locCoordinates,tripDetails[i],next);
		else if(flag == 2)
			m = strategy_y(num,locCoordinates,tripDetails[i],next);
		else if(flag == 3)
			m = strategy_xy(num,locCoordinates,tripDetails[i],next);
		vec.push_back(m);
	}
	return vec;
}

int main()
{
	int num = 9,tripCount=3;
	Point p[9]={{2,1},{6,2},{9,0},{12,8},{16,14},{18,12},{-4,2},{-6,-2},{-4,-10}};
	vector<int> vec;
	int tripDetails[3][5]={{2,6,20},{1,1,11},{3,-8,1,3,-20}};
	vec = nearestLoc(num, p,tripCount,tripDetails);
	return 0;
}
