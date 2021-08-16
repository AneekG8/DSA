#include<stdio.h>
#include<stdlib.h>
#include"push.h"
#include"pop.h"
#include"disp.h"
#define SIZE 5
int main()
{
	int stack[SIZE],top=-1,n;
	while(1)
	{
		printf("for PUSH press 1\n");
		printf("for POP press 2\n");
		printf("for DISP press 3\n");
		printf("for EXIT press 4\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				PUSH(stack,&top,SIZE);
				break;
			case 2:
				POP(stack,&top);
				break;
			case 3:
				DISP(stack,top);
				break;
			case 4:
				exit(0);
		}
	}
}
