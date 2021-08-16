#include<stdio.h>
#include<stdlib.h>
int arr[5];
int top1=-1,size=5,top2=size;
void PUSH1(int x)
{
	if(top1<top2-1)
	{
		printf("enter ur value\n");
		scanf("%d",&x);
		top1++;
		arr[top1]=x;
	}
	else
	{
	printf("\nstack overflowed\n");
	}
}
void PUSH2(int x)
{
	if(top1<top2-1)
	{
		printf("enter ur value\n");
		scanf("%d",&x);
		top2--;
		arr[top2]=x;
	}
	else
	{
		printf("\nstack overflowed\n");
	}
}
int POP1()
{
	if(top1>=0)
	return arr[top1--];
	else
	{
	printf("\nstack1 is empty\n");
	}
}
int POP2()
{
	if(top2<=size-1)
	return arr[top2++];
	else
	{
	printf("\nstack2 is empty\n");
	}
}
void DISP1()
{
	int i;
	printf("stack1 is:\n");
	for(i=top1;i>=0;i--)
	printf("\t|%d|\n",arr[i]);
}
void DISP2()
{
	int i;
	printf("stack2 is:\n");
	for(i=top2;i<=size-1;i++)
	printf("\t|%d|\n",arr[i]);	
}
int main()
{
	int n,val1,val2;
	while(1)
	{
		printf("\nfor PUSH stack1 press 11\n");
		printf("for POP stack1 press 21\n");
		printf("for PUSH stack2 press 12\n");
		printf("for POP stack2 press 22\n");
		printf("for DISP press 3\n");
		printf("for EXIT press 4\n");
		scanf("%d",&n);
		switch(n)
		{
			case 11:
				PUSH1(val1);
				break;
			case 21:
				if(POP1()!=0)
				printf("DELETED %d from stack1\n",POP1());
				break;
			case 12:
				PUSH2(val2);
				break;
			case 22:
				if(POP2()!=0)
				printf("DELETED %d from stack2\n",POP2());
				break;
			case 3:
				{
				DISP1();
				DISP2();
				break;
				}
			case 4:
				exit(0);
			default:
				printf("\ninvalid input\n");
		}
	}
}
