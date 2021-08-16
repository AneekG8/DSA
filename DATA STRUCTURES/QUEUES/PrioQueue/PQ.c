#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 5
struct PQ
{
char queue[SIZE];
int prio[SIZE];
int count;
int front;
int rear;
};
void INST( struct PQ *a );
void DISP( struct PQ *a );
void DEL(struct PQ *a);
void swapint(int *,int *);
int main( void )
{
struct PQ A;
int i,n;
A.count=0;
A.front=0;
A.rear=-1;
while(1)
{
printf("INST press 1\n");
printf("DEL press 2\n");
printf("DISP press 3\n");
printf("EXIT press 4\n");
scanf("%d",&n);
switch(n)
{
case 1: INST( &A );
DISP( &A );
break;
case 2:DEL(&A);
DISP( &A );
break;
case 3: DISP( &A );
break;
case 4: exit(0);
}
}

return 0;
}
void INST( struct PQ *a )
{

int val;
if( a->count == SIZE )
{
printf("FULL HAIN BOSS \n");
}
else
{
a->rear = (a->rear + 1)%SIZE;
printf("INSERT a CHAR:");
getchar();
scanf("%c", &(a->queue[a->rear]));
printf("INSERT the priority value:");
scanf("%d", &(a->prio[a->rear]));
(a->count)++;
int c= a->count;
int r= a->rear;
int r2;
while( c>1 )
{
r2=r-1;
if(r2==-1)
r2=SIZE-1;
if( a->prio[r] >a->prio[r2] )
{
swapint(&a->prio[r],&a->prio[r2]);
char ch = a->queue[r2];
a->queue[r2] = a->queue[r];
a->queue[r] = ch;
r--;
if(r==-1)
r=SIZE-1;
c--;
}
else
break;

}
}
}
void DISP( struct PQ *a )
{
int i,c;
if( a->count == 0 )
printf(" EMPTY \n");
printf(" ID\tPRIORITY\n");
for( i=a->front, c=a->count; c>0; c--, i=(i+1)%SIZE )
{
printf("|%c|\t",a->queue[i]);
printf("|%d|",a->prio[i]);
printf("\n");
printf("-------------");
printf
("\n");
}
}
void DEL(struct PQ *a)
{
if(a->count==0)
{
printf("\nTHE PQUEUE IS EMPTY\n");
}
else
{
printf("\nTHE ELEMENTED TO BE DELETED : %c\n",a->queue[a->front]);
a->front=(a->front+1)%SIZE;
(a->count)--;
}
}
void swapint(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
