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
	return queue->count==queue->size;
}
int isempty(Queue *queue)
{
	return queue->count==0;
}
void enque(Queue *queue,int val)
{
	queue->rear=(queue->rear+1)%queue->size;
	queue->arr[queue->rear]=val;
	queue->count++;
}
int deque(Queue *queue)
{
	int x=queue->arr[queue->front];
	queue->front=(queue->front+1)%queue->size;
	queue->count--;
	return x;
}
void DISP(Queue *queue)
{
	int i=queue->count;
	int j=queue->front;
	if(isempty(queue))
	{
		printf("\tQUEUE IS EMPTY\n");
		return ;
	}
	while(i)
	{
		printf("\t|%d|\n",queue->arr[j]);
		j=(j+1)%queue->size;
		i--;
	}
	printf("\t--------\n");
}
int main()
{
	Queue *queue=createqueue(5);
	int n,val;
	printf("%d\n",2*2);
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
					printf("\tQUEUE IS FULL\n");
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
					printf("\tQUEUE IS EMPTY\n");
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
