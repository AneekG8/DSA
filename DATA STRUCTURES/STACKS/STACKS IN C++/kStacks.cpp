#include<bits/stdc++.h>
using namespace std;

class kStacks{

int* arr;
int* top;
int* next;
int free;
public:
    kStacks(int n,int k)
    {
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        for(int i=0;i<n-1;i++)
            next[i] = i+1;

        next[n-1] = -1;

        for(int i=0;i<k;i++)
            top[i] = -1;

        free = 0;
    }

    void push(int x,int st)
    {
        st--;

        if(free == -1)
        {
            cout<<"STACK OVERFLOW"<<endl;
            return;
        }

        int i = free;   //current free

        free = next[i]; //next free

        next[i] = top[st];

        top[st] = i;

        arr[i] = x;
    }

    void pop(int st)
    {
        st--;

        if(top[st] == -1)
        {
            cout<<"STACK IS EMPTY"<<endl;
            return;
        }

        int i = top[st];

        top[st] = next[i];  //previous top

        next[i] = free;     //current free will be next free element

        free = i;   //i is being freed

        cout<<"POPPED "<<arr[i]<<endl;
    }
};

int main()
{
    kStacks s(6,3);

    s.push(1,1);
    s.push(2,1);
    s.push(3,2);
    s.push(4,3);
    s.push(5,1);
    s.push(6,2);
    s.push(7,1);

    s.pop(3);
    s.pop(2);
    s.push(10,3);
    s.pop(3);
    s.pop(3);
    s.pop(3);
}
