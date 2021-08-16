
//reverse a stack using a temporary stack

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

stack<int> sort(stack<int> s)
{
    stack<int> temp;
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        if(temp.empty() || x>=temp.top())
            temp.push(x);
        else
        {
            while(!temp.empty() && temp.top()>x)
            {
                int y=temp.top();
                temp.pop();
                s.push(y);
            }
            temp.push(x);
        }
    }
    return temp;
}
int main()
{
    stack<int> s;

    s.push(10);
    s.push(1);
    s.push(50);
    s.push(-20);
    s.push(5);

    showstack(s);

    s=sort(s);

    showstack(s);
    return 0;
}
