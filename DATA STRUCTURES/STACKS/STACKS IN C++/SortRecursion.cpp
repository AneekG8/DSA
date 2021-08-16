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

void sortedInsert(stack<int> &s,int val)
{
    if(s.empty())
        s.push(val);
    else
    {
        if(s.top() < val)
        {
            int x = s.top();
            s.pop();

            sortedInsert(s,val);

            s.push(x);
        }

        else
            s.push(val);
    }
}

void sort(stack<int> &s)
{
    if(!s.empty())
    {
        int x = s.top();
        s.pop();

        sort(s);

        sortedInsert(s,x);
    }
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

    sort(s);

    showstack(s);
    return 0;
}
