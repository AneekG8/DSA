#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100
void PUSH(char *,int *,char);
char POP(char *,int *);
int prece(char );
void PUSH1(int *,int *,int);
int POP1(int *,int *);
void PUSH(char *s,int *t,char val)
{
	(*t)++;
	s[*t]=val;
}
char POP(char *s,int *t)
{
	char val=s[*t];
	(*t)--;
	return val;
}
int prece(char sym)
{
if(sym=='/')
return (3);
else if(sym=='*')
return (2);
else if(sym=='+')
return (1);
else
return (0);
}
	void PUSH1(int *s,int *t, int val)
	{
		if(*t==SIZE-1)
		{
			printf("stack is full\n");
			return;
		}
		(*t)++;
		s[*t]=val;
	}
	int POP1(int *s,int *t)
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
int main()
{
	char infix[SIZE],postfix[SIZE],stack[SIZE];
	int i,c=0,top=-1;
	char x;
	printf("\t\t\t\t****IT ONLY WORKS FOR SINGLE DIGIT NUMBERS****\n\n\n");
	printf("enter the infix expression\n");
	scanf("%s",infix);
	for(i=0;i<strlen(infix);i++)
	{
		if(isdigit(infix[i])||isalpha(infix[i]))
		{
			postfix[c]=infix[i];
			c++;
		}
		else if(infix[i]=='(')
		{
			PUSH(stack,&top,infix[i]);
		}
		else if(infix[i]==')')
		{
			x=POP(stack,&top);
			while(x!='(')
			{
				postfix[c]=x;
				c++;
				x=POP(stack,&top);
			}
		}
		else if(infix[i]=='/'||infix[i]=='*'||infix[i]=='+'||infix[i]=='-')
		{
			 x=POP(stack,&top);
			 while(prece(x)>prece(infix[i]))
			 {
			 	postfix[c]=x;
			 	c++;
			 	x=POP(stack,&top);
			 }
			 PUSH(stack,&top,x);
			 PUSH(stack,&top,infix[i]);
		}
		else
		printf("invalid expression\n");
	}
		while(top!=-1)
		{
			postfix[c]=POP(stack,&top);
			c++;
		}
	printf("\n\tthe postfix expression is %s\n",postfix);
	int stack1[SIZE],j,top1=-1,len,v1,v2;
	int res;
    len=strlen(postfix);
    printf("\n\tyou have entered %s expression\t with length %d\n",postfix,len);
    for(j=0;j<len;j++)
    {
    	if(isdigit(postfix[j]))
    	PUSH1(stack1,&top1,postfix[j]-48);
    	else
    	{
    		v1=POP1(stack1,&top1);
    		v2=POP1(stack1,&top1);
    		switch(postfix[j])
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
		PUSH1(stack1,&top1,res);
		}
	}
	printf("\n\t\t\t||||||||the output is %d||||||||\n",POP1(stack1,&top1));
	return 0;
}

