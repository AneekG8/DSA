//interleave a queue using one stack only  || 1 2 3 4 ----> 1 3 2 4
#include <iostream>
#include<queue>
#include<stack>
using namespace std;

showQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void inteleave(queue<int> *q)
{
    stack<int> s;

    int half=q->size()/2;

    //dequeue and push first half elements into a stack
    for(int i=0;i<half;i++)
    {
        s.push(q->front());
        q->pop();
    }

    //push stack elements into queue again
    while(!s.empty())
    {
        q->push(s.top());
        s.pop();
    }

    //pop the first half elements and push them back to the queue
    for(int i=0;i<half;i++)
    {
        q->push(q->front());
        q->pop();
    }

    //dequeue and push first half elements into a stack
    for(int i=0;i<half;i++)
    {
        s.push(q->front());
        q->pop();
    }

    //now interleave queue and stack
    while(!s.empty())
    {
        q->push(s.top());
        s.pop();

        q->push(q->front());
        q->pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    showQueue(q);

    inteleave(&q);

	showQueue(q);

	return 0;
}
