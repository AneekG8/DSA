//implement queue using only one stack

#include<iostream>
#include<stack>
using namespace std;

class queue{
private:
    stack<int> s;
public:
    bool empty()
    {
        return s.empty();
    }
    void enqueue(int x)
    {
        s.push(x);
    }
    void dequeue()
    {
        if(this->empty())
            return;
        else if(s.size()==1)
        {
            s.pop();
            return;
        }
        else
        {
            int x=s.top();
            s.pop();
            dequeue();
            s.push(x);
        }
    }
    void display()
    {
        stack<int> temp=s;
        while(!temp.empty())
        {
            cout<<temp.top()<<endl;
            temp.pop();        }
        }
};

int main()
{
    queue q;
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    q.display();

    q.dequeue();
    q.display();

    return 0;

}
