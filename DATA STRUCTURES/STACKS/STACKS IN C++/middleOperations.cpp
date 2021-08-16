#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node()
    {

    }

    Node(int x)
    {
        data = x;
        prev = next = nullptr;
    }
};
class stack{

Node* head = nullptr;
Node* mid = nullptr;
Node* tail = nullptr;

bool move = false;

public:
    void push(int x)
    {
        if(!head)
        {
            head = new Node(x);
            tail = head;
            mid = head;
        }

        else
        {
            tail->next = new Node(x);

            tail->next->prev = tail;

            tail = tail->next;

            if(move)
                mid = mid->next;

            move = !move;
        }
    }

    void pop()
    {
        if(tail == head)
        {
            delete(tail);
            tail = head = mid = nullptr;
            move = false;
        }

        else
        {
            if(!move)
                mid = mid->prev;

            move = !move;

            tail = tail->prev;

            delete(tail->next);

            tail->next = nullptr;
        }
    }

    bool isEmpty()
    {
        if(head)
            return false;
        return true;
    }

    int getMid()
    {
        return mid->data;
    }

    void deleteMid()
    {
        if(!head)
            return;

        if(mid == head)
        {
            head = head->next;

            if(head)
            {
                head->prev = nullptr;
                move = false;
            }

            tail = head;
            delete(mid);
            mid = head;
            move = !move;
        }

        else
        {
            Node* temp = mid;

            if(!move)
            {
                mid = mid->prev;
                mid->next = temp->next;
                temp->next->prev = mid;
            }

            else
            {
                mid = temp->next;

                mid->prev = temp->prev;
                temp->prev->next = mid;
            }

            delete(temp);

            move = !move;
        }
    }

    void display()
    {
        Node* curr = tail;

        if(!curr)
        {
            cout<<"EMPTY!!";
            return;
        }

        while(curr)
        {
            cout<<curr->data<<" ";
            curr = curr->prev;
        }
    }
};

int main()
{
    stack s;

    s.push(1);
    s.display();
    cout<<endl<<s.getMid()<<endl;
    s.push(2);
    s.display();
    cout<<endl<<s.getMid()<<endl;
    s.push(3);
    s.display();
    cout<<endl<<s.getMid()<<endl;
    s.push(4);
    s.display();
    cout<<endl<<s.getMid()<<endl;

    s.deleteMid();
    s.display();
    cout<<endl;

    s.deleteMid();
    s.display();
    cout<<endl;


    s.deleteMid();
    s.display();
    cout<<endl;


    s.deleteMid();
    s.display();
    cout<<endl;


}
