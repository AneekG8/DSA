#include <iostream>
#include<queue>
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

void reverseQueue(queue<int> *q)
{
    if(q->empty())
        return;
    int x=q->front();
    q->pop();
    reverseQueue(q);
    q->push(x);
}

void pseudo_reverse_k(queue<int> *q,int k)  // 1 2 3 4 5 ---> 3 4 5 2 1     || k = 2
{

    if(k>0)
    {
        int x=q->front();
        q->pop();
        pseudo_reverse_k(q,k-1);
        q->push(x);
    }
}

void reverse_k(queue<int> *q,int k)
{
    reverseQueue(q);       // 1 2 3 4 5 -----> 5 4 3 2 1
    pseudo_reverse_k(q,q->size()-k);        // 5 4 3 2 1 ------> 2 1 3 4 5      || q.size()-k = 3
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    showQueue(q);

    reverse_k(&q,3);

	showQueue(q);

	return 0;
}
