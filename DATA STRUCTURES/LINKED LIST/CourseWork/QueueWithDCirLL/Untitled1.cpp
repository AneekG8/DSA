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
void del(Node **head,int key)
{
	Node *last=*head;
	Node *temp;
	if(*head==NULL)
	{
		printf("QUEUE IS EMPTY\n");
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
			printf("%d DOESNOT EXIST IN THE QUEUE\n",key);
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
 		printf("EMPTY\n\n");
 		return;
	}
	printf("QUEUE IS:-\n");
	 while(last->next!=head)
	 {
	 	printf("|%d|",last->data);
	 	last=last->next;
	 }
	printf("|%d|",last->data);	
	printf("\n\n");
}
int main()
{
	Node *queue=NULL;
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
				/*if(isfull(queue))
					{
						printf("QUEUE IS FULL\n");
						break;
					}*/
				printf("\tENTER UR VALUE\n");
				scanf("%d",&val);
				append(&queue,val);
				printf("\t%d INSERTED to queue\n",val);
				break;
			case 2:
				/*if(isempty(queue))
				{
					printf("QUEUE IS EMPTY\n");
					break;
				}*/
				del(&queue,queue->data);
				break;
			case 3:
				printf("\tQUEUE IS:\n");
				DISP(queue);
				break;
			case 4:
				exit(0);	
		}
	}
	return 0;
}
