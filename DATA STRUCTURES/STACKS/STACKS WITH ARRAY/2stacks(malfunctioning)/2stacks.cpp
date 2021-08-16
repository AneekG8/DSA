#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Stacks{
int *arr;
int SIZE;
int top1, top2;
}Stacks;
Stacks *create2stacks(int n)
{
Stacks *stacks = new Stacks;
stacks->SIZE=n;
stacks->arr= new int[n];
stacks->top1=-1;
stacks->top2=n;
return stacks;
}
void PUSH1 (Stacks *stacks,int x)
{
if (stacks->top1<stacks->top2-1)
{
stacks->top1 ++ ;
stacks->arr[stacks->top1]=x;
}
else
{
printf("stack overflow\n");
exit(1);
}
}
void PUSH2 (Stacks *stacks,int x)
{
if (stacks->top1<stacks->top2-1)
{
stacks->top2--;
stacks->arr[stacks->top2]=x;
}
else
{
printf("stack overflowed\n");
exit(2);
}
}
int POP1(Stacks *stacks)
{
    if (stacks->top1>=0)
    {
        int x=stacks->arr[stacks->top1--];
        return x;

    }

    return -1;
}
int POP2(Stacks *stacks)
{
if (stacks->top2<stacks->SIZE)
{
int x=stacks->arr[stacks->top2++];
return x;

}

return -1;
}
void DISP1(Stacks stacks)
{
while(stacks.top1!=-1)
printf("%d\n",stacks.arr[stacks.top1--]);
}
void DISP2(Stacks stacks)
{
while(stacks.top2!=stacks.SIZE)
printf("%d\n",stacks.arr[stacks.top2++]);
}
int main()
{
Stacks *stacks=create2stacks(7);
PUSH1(stacks,10);
PUSH1(stacks,20);
PUSH1(stacks,30);
PUSH1(stacks,40);
PUSH2(stacks,40);
PUSH2(stacks,50);
PUSH2(stacks,60);
DISP1(*stacks);
DISP2(*stacks);
return 0;
}

