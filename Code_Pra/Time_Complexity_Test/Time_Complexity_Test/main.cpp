#include <time.h>
#include <stdio.h>
#include <math.h>

#define LOOP_TIME 1e7

double f1(int n,double a[],double x)
{
	int i;
	double p=a[0];
	for (int i=0;i<=n;i++)
	{
		p+=(a[i]*pow(x,i));
	}
	return p;
}

double f2(int n,double a[],double x)
{
	int i;
	double p=a[0];
	for (int i=n;i>0;i--)
	{
		p=a[i-1]+x*p;
	}
	return p;
}

int main()
{
	clock_t start;
	clock_t stop;

	double num[]={1,20,37,18,37,48,39,2,49,99};
	double (*pf)(int ,double [],double);
	pf=f1;
	double duration;
	start=clock();
	for (double i=0;i<LOOP_TIME;i++)
	{
		(*pf)(10,num,10);
	}
	
	stop=clock();
	duration=(stop-start)/CLK_TCK;

	return 0;
}