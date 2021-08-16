#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
	int *arr;
	int top;
	unsigned size;
}Stack;
struct Stack* createstack( unsigned capacity ) 
{ 
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

	if (!stack) 
		return NULL; 

	stack->top = -1; 
	stack->size = capacity; 

	stack->arr = (int*) malloc(stack->size * sizeof(int)); 

	if (!stack->arr) 
		return NULL; 
	return stack; 
}
typedef struct Queue{
	Stack *stack1;
	Stack *stack2;
}Queue;
int isfull(Stack *stack) //checks if the satck is full or not
{
	if(stack->top==stack->size-1)	//or return stack->top==stack->size-1;
	return 1;
	else 				//without the else statement function will return in undefined behaviour for if(not)
	return 0;
}
int isempty(Stack *stack) //checks whether the stack is empty or not
{
	return (stack->top==-1); // returns 1 only if top is -1 else returns 0
}
//operation functions of stack
void PUSH(Stack *stack,int val)
{
	stack->arr[++stack->top]=val;
}
int POP(Stack *stack)
{
	return stack->arr[stack->top--];
}
int PEEK(Stack *stack) //returns the top element without removing it
{
	if(!isempty(stack))
	return stack->arr[stack->top];
}
void enque(Queue *queue,int x)
{
	while(!isempty(queue->stack1))
		PUSH(queue->stack2,POP(queue->stack1));
	PUSH(queue->stack1,x);
	while(!isempty(queue->stack2))
		PUSH(queue->stack1,POP(queue->stack2));
}
int deque(Queue *queue)
{
	return POP(queue->stack1);
}
void DISP(Queue *queue)
{
	if(isempty(queue->stack1))
	{
		printf("\tQUEUE IS EMPTY\n");
		return;
	}
	int i;
	for(i=(queue->stack1)->top;i>=0;i--)
		printf("|%d|",(queue->stack1)->arr[i]);
	printf("\n----------------------------------\n");
}
int main()
{
	Queue queue;
	queue.stack1=createstack(3);
	queue.stack2=createstack(3);
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
				if(isfull(queue.stack1))
				{
					printf("\tQUEUE IS FULL\n");
					break;
				}
				printf("\tENTER UR VALUE\n");
				scanf("%d",&val);
				enque(&queue,val);
				printf("\t%d INSERTED to queue\n",val);
				break;
			case 2:
				if(isempty(queue.stack1))
				{
					printf("\tQUEUE IS EMPTY\n");
					break;
				}
				printf("\t%d DELETED from queue\n",deque(&queue));
				break;
			case 3:
				printf("\tQUEUE IS:\n");
				DISP(&queue);
				break;
			case 4:
				exit(0);	
		}
	}
	return 0;
}
