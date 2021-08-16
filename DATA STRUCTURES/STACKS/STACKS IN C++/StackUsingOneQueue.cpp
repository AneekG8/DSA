//implement a stack with one queue

#include<iostream>
#include<queue>
using namespace std;


class stack{

    queue<int> q;

public:

    void push(int x);
    void pop();
    int top();
    bool empty(){return q.empty();}
};

void stack::push(int x)
{
    int s=q.size();
    q.push(x);
    for(int i=1;i<=s;i++)
    {
        q.push(q.front());
        q.pop();
    }
}
void stack::pop()
{
    q.pop();
}
int stack::top()
{
    return q.front();
}

void showstack(stack s)
{
    while (!s.empty())
    {
        cout << s.top()<<endl;
        s.pop();
    }
    cout << '\n';
}

int main()
{
    stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    showstack(s);

    s.pop();
    showstack(s);

    cout<<s.top()<<endl;
    return 0;
}
