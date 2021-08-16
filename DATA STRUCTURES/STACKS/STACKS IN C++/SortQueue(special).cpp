/*
Given a Queue consisting of first n natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are:
1. Push and pop elements from the stack
2. Pop (Or enqueue) from the given Queue.
3. Push (Or Dequeue) in the another Queue.

Algorithm:
1. Initialize the expected_element = 1
2. Check if either front element of given Queue or top element of the stack have expected_element
….a) If yes, increment expected_element by 1, repeat step 2.
….b) Else, pop front of Queue and push it to the stack. If the popped element is greater than top of the Stack, return “No”.
*/

#include<iostream>
#include<stack>
#include<queue>
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

bool checkSortQueue(queue<int> q)
{
        stack<int> s;
        int n=q.size();
        int expected=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            if(front==expected)
                expected++;
            else
            {
                if(!s.empty() && s.top() < front)
                    return false;
                else
                    s.push(front);
            }
            while(!s.empty() && s.top()==expected)
            {
                s.pop();
                expected++;
            }
        }
        if(expected-1==n && s.empty())
            return true;
        return false;
}
int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(6);
    q.push(3);
    q.push(4);

    checkSortQueue(q) ? (cout<<"YES"<<endl) : (cout<<"NO"<<endl);
    return 0;
}


