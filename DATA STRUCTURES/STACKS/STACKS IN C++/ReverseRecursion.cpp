//reverse a stack using recursion only

#include<iostream>
#include<stack>
using namespace std;

void showstack(stack <int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

void push_back(stack<int> *s,int a)
{
    if(s->empty())
        s->push(a);
    else
    {
        int x=s->top();
        s->pop();
        push_back(s,a);
        s->push(x);
    }

}

void reverseStack(stack<int>& s)
{
    int x;
    x=s.top();
    s.pop();
    if(!s.empty())
        reverseStack(s);
    push_back(&s,x);
}
int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    showstack(s);

    reverseStack(s);

    showstack(s);


    return 0;
}
