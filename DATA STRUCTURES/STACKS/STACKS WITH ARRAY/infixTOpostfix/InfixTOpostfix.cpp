#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 40
void push(char *s,int *t,char item);
char pop (char *s,int *t);
int prece(char sym);
int main ()
{
char postfix[SIZE];
char infix[SIZE];
char stack[SIZE];
char x;
int top=-1,len,i,c=0;
printf ("Enter an Infix Expression:\n");
scanf ("%s",infix);
len =strlen(infix);
for (i=0;i<len;i++)
{
if(isdigit(infix[i])|| isalpha(infix[i]))
{
postfix[c]=infix[i];
c++;
}
else if (infix[i]=='(')
{
push (stack,&top,infix[i]);
}
else if (infix[i]==')')
{
x=pop(stack,&top);
while (x!='(')
{
postfix[c]=x;
c++;
x=pop(stack,&top);
}
}
else if (infix[i]=='/'||infix[i]=='*'||infix[i]=='+'||infix[i]=='-')
{
x=pop(stack,&top);
while (prece(x)>prece(infix[i]))
{
postfix[c]=x;
c++;
x=pop(stack,&top);
}
push(stack,&top,x);
push (stack,&top,infix[i]);
}

else
printf ("invalid expression\n");
}
printf("%d",top);
while(top!=-1)
{
x=pop(stack,&top);
postfix[c]=x;
c++;
}
printf ("postfix expression is :%s",postfix);
}
void push(char *s,int *t,char item)
{
if (*t>=SIZE-1)
{
printf ("stack is overflow\n");
return;
}
(*t)++;
s[*t]=item;
}
char pop (char *s,int *t)
{
char item;
if(*t<-1)
{
printf ("stack is empty");
}
item=s[*t];
(*t)--;
return (item);
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
