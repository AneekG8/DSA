#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
	int *arr;
	int front;
	int rear;
	int count;
	unsigned size;
}Queue;
Queue* createqueue( unsigned capacity ) 
{ 
	Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 

	if (!queue) 
		return NULL; 

	queue->front =0; 
	queue->size = capacity; 
	queue->rear=-1;
	queue->count=0;
	queue->arr = (int*) malloc(queue->size * sizeof(int)); 

	if (!queue->arr) 
		return NULL; 
	return queue; 
}
int isfull(Queue *queue)
{
	return queue->rear==queue->size-1;
}
int isempty(Queue *queue)
{
	return queue->count==0||queue->front==queue->size;
}
void enque(Queue *queue,int val)
{
	queue->arr[++queue->rear]=val;
	queue->count++;
}
int deque(Queue *queue)
{
	queue->count--;
	return queue->arr[queue->front++];
}
void DISP(Queue *queue)
{
	int i;
	if(isempty(queue))
	{
		printf("\tQUEUE IS EMPTY\n");
		return ;
	}
	for(i=queue->front;i<=queue->rear;i++)
		printf("\t|%d|\n",queue->arr[i]);
	printf("\t--------\n");
}
int main()
{
	Queue *queue=createqueue(3);
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
				if(isfull(queue))
					{
						printf("QUEUE IS FULL\n");
						break;
					}
				printf("\tENTER UR VALUE\n");
				scanf("%d",&val);
				enque(queue,val);
				printf("\t%d INSERTED to queue\n",val);
				break;
			case 2:
				if(isempty(queue))
				{
					printf("QUEUE IS EMPTY\n");
					break;
				}
				printf("\t%d DELETED from queue\n",deque(queue));
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
