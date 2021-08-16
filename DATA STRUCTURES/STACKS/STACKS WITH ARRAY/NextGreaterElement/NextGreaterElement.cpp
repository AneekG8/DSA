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
void NFG(int *arr,int n)
{
	Stack *stack=createstack(n);
	int i,next;
	PUSH(stack,arr[0]);
	for(i=1;i<n;i++)
	{
		next=arr[i];
		while(!isempty(stack)&&PEEK(stack)<next)
		{
			printf("NFG of %d is %d\n",POP(stack),next);
		}
		PUSH(stack,next);
	}
	next=-1;
	while(!isempty(stack))
	printf("NFG of %d is %d\n",POP(stack),next);
}
int main()
{
	int n,i;
	printf("how many numbers do u want to enter?\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the numbers\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("your entered elements are:\n");
	for(i=0;i<n;i++)
		printf("|%d|",arr[i]);
	printf("\n\n");
	NFG(arr,n);
	return 0;
}
