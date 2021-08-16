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
void NGE(int *arr,int *next,int a)
{
	int i,nfg;
	Stack *stack=createstack(a);
	PUSH(stack,0);
	for(i=1;i<a;i++)
	{
		nfg=arr[i];
		if(nfg>arr[PEEK(stack)])
		{
			while(!isempty(stack))
				next[POP(stack)]=nfg;
		}
		PUSH(stack,i);
	}
	while(!isempty(stack))
	{
		next[POP(stack)]=-1;
	}
}
void queries(int *que,int *next,int q)
{
	int i;
	for(i=0;i<q;i++)
	{
		printf("%d\t",next[que[i]]);
	}
}
int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int que[]={0,1,2,3,4,5,6};
	int next[7];
	NGE(arr,next,7);
	queries(que,next,7);
	return 0;
}
