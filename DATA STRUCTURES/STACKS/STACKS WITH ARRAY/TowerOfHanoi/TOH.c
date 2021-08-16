#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
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
}int isfull(Stack *stack) //checks if the satck is full or not
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
void movedisk(int d,char from,char to)
{
	printf("MOVE disk %d from %c to %c\n",d,from,to);
}
void MoveBetween2Poles(Stack *fp,Stack *sp,char p1,char p2)
{
	if(isempty(fp))
	{
	PUSH(fp,POP(sp));
	movedisk(PEEK(fp),p2,p1);
	}
	else if(isempty(sp))
	{
	PUSH(sp,POP(fp));
	movedisk(PEEK(sp),p1,p2);
	}
	else if(PEEK(fp)>PEEK(sp))
	{
		PUSH(fp,PEEK(fp));		//increases the top of fp
		PUSH(fp,POP(sp));
		movedisk(PEEK(fp),p2,p1);
	}
	else
	{
		PUSH(sp,PEEK(sp));		//increases the top
		PUSH(sp,POP(fp));
		movedisk(PEEK(sp),p1,p2);
	}
}
void TOH(Stack *src,Stack *aux,Stack *des,int num)
{
	int i,totmoves;
	char s='S',a='A',d='D';
	totmoves=pow(2,num)-1;
	if(num%2==0)
		{
			int temp;
			temp=d;
			d=a;
			a=temp;
		}
	for(i=num;i>=1;i--)
	PUSH(src,i);
	for(i=1;i<=totmoves;i++)
	{
		if(i%3==1)
		MoveBetween2Poles(src,des,s,d);
		else if(i%3==2)
		MoveBetween2Poles(src,aux,s,a);
		else if(i%3==0)
		MoveBetween2Poles(aux,des,a,d);
	}
}
int main()
{
	Stack *src,*aux,*des;
	int num;
	printf("ENTER NUMBER OF DISKS\n");
	scanf("%d",&num);
	src=createstack(num);
	aux=createstack(num);
	des=createstack(num);
	TOH(src,aux,des,num);
	return 0;
}
