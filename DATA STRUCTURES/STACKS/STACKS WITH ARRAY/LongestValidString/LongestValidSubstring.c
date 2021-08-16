#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Stack{
	int *arr;
	int top;
	unsigned size;
}Stack;
Stack* createstack( unsigned capacity )
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
int isfull(Stack *stack)
{
	return stack->top==stack->size-1;
}
int isempty(Stack *stack)
{
	return stack->top==-1;
}
void PUSH(Stack *stack,int val)
{
	stack->arr[++stack->top]=val;
}
int POP(Stack *stack)
{
	return stack->arr[stack->top--];
}
int PEEK(Stack *stack)
{
	return stack->arr[stack->top];
}
void DISP(Stack *stack)
{
	int i;
	if(isempty(stack))
	{
	printf("stack is empty\n");
	return;
	}
	else
	{
	for(i=stack->top;i>=0;i--)
	printf("|%c|\n",stack->arr[i]);
	}
}
int LVS(char *exp) 	//lvs=length of longest valid substring
{
	Stack *stack=createstack(strlen(exp));
	PUSH(stack,-1);
	int i,res=0;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(')
			PUSH(stack,i);
		else if(exp[i]==')')
		{
			POP(stack);
			if(!isempty(stack)&&(i-PEEK(stack))>res)
				res=i-PEEK(stack);
			else if(isempty(stack))
				PUSH(stack,i);
		}
	}
	return res;
}
int main()
{
	char str[100];
	printf("\tenter ur string\n");
	scanf("%s",str);
	printf("\tLENGTH OF LONGEST VALID SUBSTRING IS: %d\n",LVS(str));
	return 0;
}
