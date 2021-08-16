#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
int top1,top2,top3;
int arr[SIZE];
void PUSH(int *top,int val)
{
	arr[++(*top)]=val;
}
void PUSH3(int *top,int val)
{
	arr[--(*top)]=val;
}
int POP(int *top)
{
	return (arr[(*top)--]);
}
int POP3(int *top)
{
	return (arr[(*top)++]);
}
void DISP(int *top,int ini)
{
	int i;
	for(i=*top;i>ini;i--)
	printf("|%d|\n",arr[i]);
	printf("__________\n");
}
void DISP3(int *top,int ini)
{
	int i;
	for(i=*top;i<ini;i++)
	printf("|%d|\n",arr[i]);
	printf("__________\n");
}
int main()
{
	int n,val;
	int ini1,ini2,ini3;
	top1=ini1=-1;
	top2=ini2=SIZE/2;
	top3=ini3=SIZE;
	while(1)
	{
		printf("press 11 to insert to stack1\n");
		printf("press 12 to insert to stack2\n");
		printf("press 13 to insert to stack3\n");
		printf("press 21 to delete from stackl\n");
		printf("press 22 to delete from stack2\n");
		printf("press 23 to delete from stack3\n");
		printf("press 3 to display the stacks\n");
		printf("press 4 to exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 11:
				if(top1==ini2)
				{
					printf("stack overflow\n");
					break;
				}
				printf("enter ur value\n");
				scanf("%d",&val);
				PUSH(&top1,val);
				break;
			case 12:
				if(top2>=top3-1)
				{
					printf("stack overflow\n");
					break;
				}
				printf("enter ur value\n");
				scanf("%d",&val);
				PUSH(&top2,val);
				break;
			case 13:
				if(top2>=top3-1)
				{
					printf("stack overflow\n");
					break;
				}
				printf("enter ur value\n");
				scanf("%d",&val);
				PUSH3(&top3,val);
				break;
			case 21:
				if(top1==ini1)
				{
					printf("stack1 is empty\n");
					break;
				}
				printf("DELETED %d from stack1\n",POP(&top1));
				break;
			case 22:
				if(top2==ini2)
				{
					printf("stack2 is empty\n");
					break;
				}
				printf("DELETED %d from stack3\n",POP(&top2));
				break;
			case 23:
				if(top3==ini3)
				{
					printf("stack3 is empty\n");
					break;
				}
				printf("DELETED %d from stack3\n",POP3(&top3));
				break;
			case 3:
				printf("stack1\n");
				DISP(&top1,ini1);
				printf("stack2\n");
				DISP(&top2,ini2);
				printf("stack3\n");
				DISP3(&top3,ini3);
				break;
			case 4:
				exit(0);
			default:
				printf("INVALID INPUT\n");
		}
	}
	return 0;
}
