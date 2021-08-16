#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
}Node;
void append(Node **head,int val)
{
	Node *last=*head;
	Node *new_node=(Node*)malloc(sizeof(Node));
	new_node->data=val;
	new_node->next=*head;
	if(*head==NULL)
	{
		*head=new_node;
		(*head)->next=*head;
		(*head)->prev=*head;
		return;
	}
	while(last->next!=*head)
	{
		last=last->next;
	}
	last->next=new_node;
	new_node->prev=last;
	(*head)->prev=new_node;
}
int del(Node **head,int key)
{
	Node *last=*head;
	Node *temp;
	if(*head==NULL)
	{
		printf("LIST IS EMPTY\n");
		return;
	}
	else if((*head)!=NULL&&(*head)->data==key)
	{
		printf("DELETED %d\n",key);
		while(last->next!=*head)
		{
			last=last->next;
			temp=last->next;
		}
		*head=(*head)->next;
		(*head)->prev=last;
		last->next=*head;
		free(temp);
		return;
	}
	else
	{
		while(last->next!=*head&&last->next->data!=key)
			last=last->next;
		temp=last->next;
		if(last->next==*head)
			printf("%d DOESNOT EXIST IN THE LIST\n",key);
		else
		{
			printf("DELETED %d\n",key);
			last->next=temp->next;
			temp->next->prev=last;
			free(temp);
		}
	}
}

void DISP(Node *head)
{
	Node *last=head;
 	if(head==NULL)
 	{
 		printf("LIST IS EMPTY\n\n");
 		return;
	}
	printf("LIST IS:-\n");
	 while(last->next!=head)
	 {
	 	printf("|%p|%d|%p|",last->prev,last->data,last->next);
	 	last=last->next;
	 }
	printf("|%p|%d|%p|",last->prev,last->data,last->next);	
	printf("\n\n");
}
int main()
{
	Node *head=NULL;
	append(&head,10);
	append(&head,20);
	append(&head,30);
	append(&head,40);
	DISP(head);
	/*del(&head,10);
	DISP(head);*/
	del(&head,40);
	DISP(head);
	return 0;
}
