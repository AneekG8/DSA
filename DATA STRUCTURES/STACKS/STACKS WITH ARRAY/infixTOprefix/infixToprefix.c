#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Stack{
	char *arr;
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

	stack->arr = (char*) malloc(stack->size * sizeof(char)); 

	if (!stack->arr) 
		return NULL; 
	return stack; 
}
//some utility functions
int isoperand(char ch) //checks if the element is operand or not
{
	if(isdigit(ch)||isalpha(ch))
	return 1;							//or return isdigit(ch)||isalpha(ch)
	else
	return 0;
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
void PUSH(Stack *stack,char ch)
{
	stack->arr[++stack->top]=ch;
}
char POP(Stack *stack)
{
	if(!isempty(stack))
		return stack->arr[stack->top--];
}
char PEEK(Stack *stack) //returns the top element without removing it
{
	if(!isempty(stack))
	return stack->arr[stack->top];
}
//precedence function
int prece(char ch)
{
	switch (ch)
	{
		case '+':
		case'-' :
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;			
	}
	return 0;	//this implies that any operator is of higher precedence than '(' {in this case} 
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
	printf("|%c|\n",stack->arr[i]);
	}
}
//function to convert infix to postfix
void infixTOprefix(char* exp)
{
	exp=strrev(exp);
	Stack *stack=createstack(strlen(exp));
	int i,count=-1;
	int j;
	for(j=0;j<strlen(exp);j++)
	{
		if(exp[j]=='(')
		exp[j]=')';
		else if(exp[j]==')')
		exp[j]='(';
		else 
		continue;
	}
	for(i=0;i<strlen(exp);i++)
	{
		if(isoperand(exp[i]))
		exp[++count]=exp[i];
		else if(exp[i]=='(')
		{
		PUSH(stack,exp[i]);
		}
		else if(exp[i]==')')
		{
			while(!isempty(stack)&&PEEK(stack)!='(')
			exp[++count]=POP(stack);
			if(!isempty(stack)&&PEEK(stack)!='(') //in case of no opening paranthesis
			{
				printf("invalid expression\n");
				exit(2);
			}
			else
			POP(stack);		//removes the opening paranthesis
		}
		else
		{
			while(!(isempty(stack))&&prece(exp[i])<=prece(PEEK(stack)))
				exp[++count]=POP(stack);
			PUSH(stack,exp[i]);		//pushes the op of lower precedence into stack after removing the ops of higher precedence 
		}
	}
	while(!isempty(stack))
	exp[++count]=POP(stack);
	exp[++count]='\0';
	exp=strrev(exp);
	printf("the prefix expression is\n%s\n",exp);
}
int main()
{
	char exp[100];
	printf("ENTER AN INFIX EXPRESSION\n");
	scanf("%s",exp);
	infixTOprefix(exp);
	return 0;
}
