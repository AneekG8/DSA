#include<stdio.h>
#include<stdlib.h>
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
	return (stack->top==-1); // returns 1 only if top is -1 else returns 0
}
//operation functions of stack
void PUSH(Stack *stack,int val)
{
	int i;
	if(isfull(stack))
	{
		Stack *auxstack=createstack(stack->size+1);
		for(i=0;i<=stack->top;i++)
			auxstack->arr[i]=stack->arr[i];
		stack->size+=1;
		free(stack->arr);
		stack->arr=auxstack->arr;
	}
	stack->arr[++stack->top]=val;
}
int POP(Stack *stack)
{
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
		printf("\tSTACK IS EMPTY\n");
		return;
	}
	printf("\tSTACK IS:\n");
	for(i=stack->top;i>=0;i--)
	printf("\t\t|%d|\n",stack->arr[i]);
}
int main()
{
	Stack *stack=createstack(0);
	int n,val;
	while(1)
	{
		printf("\nfor PUSH press 1\n");
		printf("for POP press 2\n");
		printf("for DISP press 3\n");
		printf("for EXIT press 4\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\tENTER UR VALUE\n");
				scanf("%d",&val);
				PUSH(stack,val);
				break;
			case 2:
				if(isempty(stack))
				{
					printf("\tSTACK IS EMPTY\n");
					break;
				}
				printf("DELETED %d\n",POP(stack));
				break;
			case 3:
				DISP(stack);
				break;
			case 4:
				exit(0);
			default:
				printf("\tINVALID INPUT\t PLEASE RETRY!\n");
		}
	}
	return 0;
}
