#include<stdio.h>
#include<stdlib.h>
int x,min;
typedef struct Stack{
	int *arr;
	int top;
	unsigned size;
}Stack;
struct Stack* createstack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->size = capacity;

	stack->arr = (int*) malloc(stack->size * sizeof(int));

	if (!stack->arr)
		return NULL;
	return stack;
}
int isfull(Stack *stack) //checks if the satck is full or not
{
	if(stack->top==stack->size-1)	//or return stack->top==stack->size-1;
	return 1;
	else 				//without the else statement function will return in undefined behaviour for if(not)
	return 0;
}
int isempty(Stack *stack) //checks whether the stack is empty or not
{
	return stack->top==-1; // returns 1 only if top is -1 else returns 0
}
//operation functions of stack
void PUSH(Stack *stack,int val)
{
	stack->arr[++stack->top]=val;
}
int POP(Stack *stack)
{
	if(!isempty(stack))
		return stack->arr[stack->top--];
}
int PEEK(Stack *stack) //returns the top element without removing it
{
	if(!isempty(stack))
	return stack->arr[stack->top];
}
void DISP(Stack *stack)
{
	int i;
	if(isempty(stack))
	{
		printf("stack is empty\n");
	}
	else
	{
	for(i=stack->top;i>=0;i--)
	printf("|%d|\n",stack->arr[i]);
	}
}
void getmin(int SIZE)
{
	Stack *entry=createstack(SIZE);
	Stack *stack=createstack(SIZE);
	int n;
	while(1)
	{
	printf("press 1 to insert\n");
	printf("press 2 to delete\n");
	printf("press 3 to display\n");
	printf("press 4 to exit\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			{
				if(isfull(stack))
				{
				printf("stack is full\n");
				break;
				}
				printf("enter ur value\n");
				scanf("%d",&x);
				PUSH(entry,x);
				if(isempty(stack))
				{
				PUSH(stack,x);
				min=x;
				}
				else
				{
					if(x>=min)
					{
						PUSH(stack,x);
					}
					else
					{
					PUSH(stack,(2*x-min));
					min=x;
					}
				}
				printf("your entry\n");
				DISP(entry);
				printf("minimum element is %d\n",min);
			break;
			}
			case 2:
				{
					if(isempty(stack))
					{
						printf("stack is empty\n");
						break;
					}
					printf("DELETED %d\n",PEEK(entry));
					if(PEEK(stack)>=min)
					{
					POP(stack);
					POP(entry);
					}
					else
					{
						min=2*min-PEEK(stack);
						POP(stack);
						POP(entry);
					}
					printf("your entry\n");
					DISP(entry);
					printf("minimum element is %d\n",min);
				break;
				}
			case 3:
				printf("your entry\n");
				DISP(entry);
				printf("minimum element is %d\n",min);
				break;
			case 4:
			exit(1);
	}
	}
}
int main()
{
	int n;
	printf("how many numbers do u want to enter\n");
	scanf("%d",&n);
	getmin(n);
	return 0;
}
