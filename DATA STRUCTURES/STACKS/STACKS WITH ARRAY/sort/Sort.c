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
void sort(Stack *stack)
{
	int i,j,temp;
	for(i=0;i<stack->size;i++)
	{
		for(j=i+1;j<stack->size;j++)
		{
			if(stack->arr[i]<stack->arr[j])
			{
				temp=(stack->arr[i]);
				stack->arr[i]=stack->arr[j];
				stack->arr[j]=temp;
			}
			else 
			continue;
		}
	}
}
void transfer(Stack *stack1,Stack *stack2)
{
	while(!isempty(stack2))
	{
		PUSH(stack1,POP(stack2));
	}
}
int main()
{
	int val;
	int n1,n2,n3;
	Stack *stack1,*stack2,*stack3;
	printf("how many numbers do u want to enter into stack 1\n");
	scanf("%d",&n1);
	printf("how many numbers do u want to enter into stack 2\n");
	scanf("%d",&n2);
	printf("how many numbers do u want to enter into stack 3\n");
	scanf("%d",&n3);
	stack2=createstack(n2);
	stack3=createstack(n3);
	stack1=createstack(n1+n2+n3);
	printf("enter your numbers for stack1\n");
	while(n1!=0)
	{
		scanf("%d",&val);
		PUSH(stack1,val);
		n1--;
	}
	printf("enter your numbers for stack2\n");
	while(n2!=0)
	{
		scanf("%d",&val);
		PUSH(stack2,val);
		n2--;
	}
	printf("enter your numbers for stack3\n");
	while(n3!=0)
	{
		scanf("%d",&val);
		PUSH(stack3,val);
		n3--;
	}
	transfer(stack1,stack2);
	transfer(stack1,stack3);
	sort(stack1);
	printf("the sorted elements in one stack are\n");
	DISP(stack1);
	return 0;
}
