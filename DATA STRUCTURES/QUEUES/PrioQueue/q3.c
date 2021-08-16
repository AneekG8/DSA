#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 5
typedef struct Student{
	int ID,sem;
	char name[10];
	char dept[10];
}Student;
struct PQ
{
Student student[SIZE];
float prio[SIZE];
int count;
int front;
int rear;
};
void INST( struct PQ *a );
void DISP( struct PQ *a );
void DEL(struct PQ *a);
void swapfloat(float *,float *);
void swapstu(Student *,Student *);
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
printf("\tQUEUE IS FULL\n\n");
printf("--------------------------------------------------------------------------------------\n");
return;
}
else
{
a->rear = (a->rear + 1)%SIZE;
printf("ENTER NAME: ");
scanf("%s",(a->student[a->rear]).name);
printf("ENTER DEPARTMENT: ");
scanf("%s",(a->student[a->rear]).dept);
printf("ENTER ID:");
scanf("%d", &(a->student[a->rear]).ID);
printf("ENTER SEMESTER:");
scanf("%d",&(a->student[a->rear]).sem);
printf("ENTER CGPA:");
scanf("%f", &(a->prio[a->rear]));
(a->count)++;
int c= a->count;
int r= a->rear;
int r2;
while( c>1 )
{
r2=r-1;
if(r2==-1)
r2=SIZE-1;
if( a->prio[r] > a->prio[r2] )
{
swapfloat(&a->prio[r],&a->prio[r2]);
swapstu(&a->student[r],&a->student[r2]);
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
printf("\t\t***************************\n\t\t\tQUEUE IS:\n");
if( a->count == 0 )
{
printf("\t\t\t\tEMPTY \n");
return;
}
printf("------------------------------------------------------------------------------------\n");
for( i=a->front, c=a->count; c>0; c--, i=(i+1)%SIZE )
{
	printf("\tNAME:          ");
	printf("%s\n",(a->student[i]).name);
	printf("\tDEPARTMENT:    ");
	printf("%s\n",(a->student[i]).dept);
	printf("%d|\tID NO.:        ",a->count+1-c);			
	printf("%d\n",a->student[i].ID);
	printf("\tSEMESTER:      ");
	printf("%d\n",a->student[i].sem);
	printf("\tCGPA:          ");
	printf("%.2f",a->prio[i]);
	printf("\n");
	printf("-------------------------------------------------------------------------------------");
	printf("\n");
}
}
void DEL(struct PQ *a)
{
if(a->count==0)
return;
else
{
printf("\n\t***************************\n\tDELETED DOCUMENT: %s\n",a->student[a->front].name);
a->front=(a->front+1)%SIZE;
(a->count)--;
}
}
void swapfloat(float *a,float *b)
{
	float temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void swapstu(Student *a,Student *b)
{
	Student temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
