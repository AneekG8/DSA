//Design a Data Structure SpecialStack that supports all the stack operations like
//push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return
//minimum element from the SpecialStack. All these operations of SpecialStack must be O(1).
// To implement SpecialStack, you should only use standard Stack data structure
// and no other data structure like arrays, list, .. etc.
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

class SpecialStack{
stack<int> s;
stack<int> min;
public:
    void push(int x)
    {
        s.push(x);
        if(s.size()==1)
            min.push(x);
        else
        {
            if(x<min.top())
                min.push(x);
        }
    }
    void pop()
    {
        if(s.top()==min.top())
        {
            s.pop();
            min.pop();
        }
        else
        {
            s.pop();
        }
    }
    int getMin()
    {
        return min.top();
    }
    void display()
    {
        showstack(s);
    }
};

int main()
{
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin()<<endl;
    s.pop();
    cout << s.getMin()<<endl;
    return 0;
}
