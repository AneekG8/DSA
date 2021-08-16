//delete middle element of a stack with recursion
//middle element wont get pushed while returning back

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

void deleteMiddle(stack<int> &s,int n,int c=1)
{
    if(!s.empty())
    {
        int x = s.top();
        s.pop();

        deleteMiddle(s,n,c+1);

        if(c != (n+1)/2)
            s.push(x);
    }
}


int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    showstack(s);

    deleteMiddle(s,s.size());

    showstack(s);

    cout<<s.size()<<endl;
    return 0;
}

