#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
int isempty(Node *head)
{
	return head==NULL;
}
void append(Node **head,int val)
{
	Node *new_node=(Node*)malloc(sizeof(Node));
	Node *last=*head;
	new_node->data=val;
	new_node->next=NULL;
	if(isempty(*head))
	{
		*head=new_node;
		return;
	}
	while(last->next!=NULL)
		last=last->next;
	last->next=new_node;
	return;	
}void DISP(Node *node)
{
	if(node==NULL)
	{
		printf("\t\tEMPTY\n");
		return;
	}
	printf("\t\t");
	while(node!=NULL)
	{
		printf("|%d|",node->data);
		node=node->next;
	}
	printf("\n");
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void del(Node **head,int key)
{
	Node *prev=*head;
	if(*head==NULL)
	{
		//printf("LIST IS EMPTY\n");
		return;
	}
	else if((*head)!=NULL&&(*head)->data==key)
	{
		//printf("DELETED %d\n",key);
		*head=(*head)->next;
		return;
	}
	else
	{
		while(prev->next!=NULL&&prev->next->data!=key)
		{
			prev=prev->next;
		}
		if(prev->next==NULL)
			printf("%d DOESNOT EXIST IN THE LIST\n",key);
		else
		{
			//printf("DELETED %d\n",key);
			prev->next=prev->next->next;
		}
	}
}
void sort(Node **head)
{
	Node *temp1=*head;
	while(temp1)
	{
		Node *temp2=temp1->next;
		while(temp2)
		{
			if(temp1->data>temp2->data)
			{
				swap(&(temp1->data),&(temp2->data));
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	temp1=*head;
	while(temp1)
	{
		if(temp1->next!=NULL&&temp1->data==temp1->next->data)
		{
			del(head,temp1->data);
		}
		temp1=temp1->next;
	}
}
int main()
{
	Node *head=NULL;
	append(&head,23);
	append(&head,00);
	append(&head,00);
	append(&head,99);
	append(&head,99);
	append(&head,10);
	append(&head,10);
	append(&head,23);
	append(&head,23);
	append(&head,00);
	DISP(head);
	sort(&head);
	DISP(head);
	return 0;
}
