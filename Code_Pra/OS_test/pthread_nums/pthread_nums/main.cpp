//#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "process.h"

unsigned int __stdcall myfun(void* p)
{
	int index = (int)p;
	printf("I am the No. %d thread\n", index);
	//等待一下，防止创建出来就退出
	Sleep(1000 * 10);
	return index;
}

int main(int argc, char* argv[])
{
	int cnt = 0;
	while (true)
	{
		cnt++;
		if (0 == _beginthreadex(NULL, 0, myfun, (void*) cnt, 0, NULL))
		{
			break;
		}
		else
		{
			printf("%d threads were created\n", cnt);
		}
	}

	Sleep(1000 * 100);

	return 0;
}
