#include <stdio.h>
#include <conio.h>

/*count characters in input;£¬version1.0*/
/*filename: nc.c*/

int main()
{
	char ch;
	//long nc=0;

	//fflush(stdin);
	while ((ch=getchar()) != '\n') 
	{
		printf("%c\n",ch);
	}
	//ch=getchar();
	fflush(stdin);
	getchar();
	return 0;
} 