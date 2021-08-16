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
void ENQUE(Node **head,int val)
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
}
int DEQUE(Node **head)
{
	int x=(*head)->data;
	*head=(*head)->next;
	return x;
}
int PEEK(Node *head)
{
	Node *last=head;
	if(last==NULL)
	{
		printf("QUEUE IS EMPTY\n");
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
int main()
{
	Node *head=NULL;
		int n,val;
	while(1)
	{
		printf("for ENQUEUE press 1\n");
		printf("for DEQUEUE press 2\n");
		printf("for DISPLAY press 3\n");
		printf("for EXIT press 4\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\tENTER UR VALUE\n");
				scanf("%d",&val);
				ENQUE(&head,val);
				printf("\t%d INSERTED to queue\n",val);
				break;
			case 2:
				if(isempty(head))
				{
					printf("\t\tQUEUE IS EMPTY\n");
					break;
				}
				printf("\t%d DELETED from queue\n",DEQUE(&head));
				break;
			case 3:
				printf("\tQUEUE IS:\n");
				DISP(head);
				break;
			case 4:
				exit(0);	
		}
	}
	return 0;
}
