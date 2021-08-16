//implement a stack using priority queue

#include<iostream>
#include<queue>
using namespace std;

class stack{

int p = 0;
priority_queue<pair<int,int>> q;

public:
    void push(int x)
    {
        p++;
        q.push(make_pair(p,x));
    }

    void pop()
    {
        q.pop();
    }

    int top()
    {
        pair<int,int> top=q.top();
        return top.second;
    }

    void display()
    {
        priority_queue<pair<int,int>> temp=q;
        while(!temp.empty())
        {
            cout<<temp.top().second<<endl;
            temp.pop();
        }
    }
};

int main()
{
    stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.display();

    s.pop();
    s.display();

    cout<<s.top()<<endl;
    return 0;
}
