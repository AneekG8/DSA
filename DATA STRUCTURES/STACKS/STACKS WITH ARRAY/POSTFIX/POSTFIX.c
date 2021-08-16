#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 15
void PUSH(int *,int *,int);
int POP(int *,int *);
void DISP(int *,int);
int main()
{
	int stack[SIZE],top=-1,i,len,v1,v2;
	int res;
	char postfix[SIZE];
    printf("enter the postfix expression\n");
    scanf("%s",postfix);
    len=strlen(postfix);
    printf("you have entered %s expression\t with length %d\n",postfix,len);
    for(i=0;i<len;i++)
    {
    	if(isdigit(postfix[i]))
    		PUSH(stack,&top,postfix[i]-48);
    	else
    	{
    		v1=POP(stack,&top);
    		v2=POP(stack,&top);
    		switch(postfix[i])
    		{
    			case '/':
    				res=v2/v1;
    				break;
    			case '*':
    				res=v2*v1;
    				break;
    			case '-':
    				res=v2-v1;
    				break;
    			case '+':
    				res=v2+v1;
    				break;
			}
		PUSH(stack,&top,res);
		}
	}
	printf("the output is %d\n",POP(stack,&top));
	return 0;
}
	void PUSH(int *s,int *t, int val)
	{
		if(*t==SIZE-1)
		{
			printf("stack is full\n");
			return;
		}
		(*t)++;
		s[*t]=val;
	}
	int POP(int *s,int *t)
	{
		char val;
		if(*t==-1)
		{
			printf("stack is empty\n");
			return;
		}
		val=s[*t];
		(*t)--;
		return(val);
	}
