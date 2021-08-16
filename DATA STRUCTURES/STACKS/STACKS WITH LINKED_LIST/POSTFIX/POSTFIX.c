#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
typedef struct Node{
	int data;
	struct Node *next;
}Node;
void PUSH(Node **head,int val)
{
	Node *new_node=(Node*)malloc(sizeof(Node));
	Node *last=*head;
	new_node->data=val;
	new_node->next=NULL;
	if(*head==NULL)
	{
		*head=new_node;
		return;
	}
	while(last->next!=NULL)
		last=last->next;
	last->next=new_node;
	return;	
}
int POP(Node **head)
{
	Node *prev;
	Node *last=*head;
	if(*head==NULL)
	{
		printf("STACK IS EMPTY\n");
		return;
	}
	if((*head)->next==NULL)
	{
		int x=(*head)->data;
		*head=NULL;
		return x;
	}
	while(last->next!=NULL)
	{
		prev=last;
		last=last->next;
	}
	prev->next=NULL;
	return last->data;
}
int PEEK(Node *head)
{
	Node *last=head;
	if(last==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
	}
	return last->data;
}
void DISP(Node *node)
{
	if(node==NULL)
	{
		printf("STACK IS EMPTY\n");
		return;
	}
	while(node!=NULL)
	{
		printf("|%d|",node->data);
		node=node->next;
	}
	printf("\n");
}
int main()
{
	Node *head=NULL;
	int i,res,len,v1,v2;
	char postfix[SIZE];
    printf("enter the postfix expression\n");
    gets(postfix);
    len=strlen(postfix);
    for(i=0;i<len;i++)
    {
    	if(postfix[i]==' ')
    		continue;
    	else if(isdigit(postfix[i]))
    	{
    		int num=0;
    		while(postfix[i]!=' ')
    		{
    			num=num*10+(postfix[i]-48);
    			i++;
			}
			PUSH(&head,num);
			i--;
		}
    	else
    	{
    		v1=POP(&head);
    		v2=POP(&head);
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
		PUSH(&head,res);
		}
	}
	printf("the output is %d\n",POP(&head));
	return 0;
}
