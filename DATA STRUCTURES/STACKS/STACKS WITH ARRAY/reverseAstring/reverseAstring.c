#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Stack{
	char *arr;
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

	stack->arr = (char*) malloc(stack->size * sizeof(char));

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
void PUSH(Stack *stack,char ch)
{
	stack->arr[++stack->top]=ch;
}
char POP(Stack *stack)
{
	return stack->arr[stack->top--];
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
void revstr(char *str)
{
	Stack *stack=createstack(strlen(str));
	int i,k=-1;
	for(i=0;i<strlen(str);i++)
	{
		PUSH(stack,str[i]);
	}
	while(!isempty(stack))
        str[++k]=POP(stack);
	printf("the reversed string is %s\n",str);
}
int main()
{
	char string[100];
	printf("enter a string\n");
	//scanf("%s",string);
	gets(string);
	revstr(string);
	return 0;
}
