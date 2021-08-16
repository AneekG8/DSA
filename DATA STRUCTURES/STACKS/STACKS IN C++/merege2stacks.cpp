//merge(Stack s1, Stack s2): Merge contents of s2 into s1.

//Time Complexity of all above operations should be O(1).

//use linked list for O(1)

#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
    Node* prev;
}Node;

class DLL{
public:
    Node* head;
    Node* tail;
    DLL()
    {
        head=NULL;
        tail=NULL;
    }
    DLL(int val)
    {
        head=new Node;
        head->data=val;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    bool isPresent(int key)
    {
        Node* check=head;
        while(check)
        {
            if(check->data==key) return true;
            check=check->next;
        }
        return false;
    }
    bool isEmpty()
    {
        return head==NULL?true:false;
    }
    void push(int val)
    {
        Node* new_node=new Node;
        new_node->data=val;
        new_node->next=head;
        new_node->prev=NULL;
        if(head)
            head->prev=new_node;
        head=new_node;
        if(!tail)
            tail=new_node;
    }
    void append(int val)
    {
        Node* new_node=new Node;
        tail=new_node;
        Node* last=head;
        new_node->data=val;
        new_node->next=NULL;
        if(head)
        {
            while(last->next)
            {
                last=last->next;
            }
            last->next=new_node;
        }
        else
        {
            head=new_node;
        }
        new_node->prev=last;

    }
    void Delete(int key)
    {
        if(isEmpty() || !isPresent(key)) return;
        Node* curr=head;
        while(curr->data!=key)
        {
            curr=curr->next;
        }
        if(curr==tail)
            tail=tail->prev;
        if(curr==head)
            head=curr->next;
        else
            curr->prev->next=curr->next;
        if(curr->next)
            curr->next->prev=curr->prev;
        delete(curr);
    }
    void display()
    {

        if(isEmpty())
        {
            cout<<"LIST IS EMPTY!"<<endl;
            return;
        }
        Node* node=head;
        while(node)
        {
            cout<<node->data<<" ";
            node=node->next;
        }
        cout<<endl;
    }
    void rdisplay()
    {

        if(isEmpty())
        {
            cout<<"LIST IS EMPTY!"<<endl;
            return;
        }
        Node* node=tail;
        while(node)
        {
            cout<<node->data<<" ";
            node=node->prev;
        }
        cout<<endl;
    }
};

class stack{
public:
    DLL list;
    stack()
    {
    }
    void push(int x)
    {
        list.push(x);
    }
    void pop()
    {
        list.Delete(list.head->data);
    }
    int top()
    {
        return list.head->data;
    }
    bool empty()
    {
        return list.isEmpty();
    }
    void display()
    {
        list.display();
    }
};

void merge(stack* s1,stack* s2)     //merge stack 1 on top of stack 2
{
    s1->list.tail->next=s2->list.head;
    s2->list.head->prev=s1->list.tail;
    s1->list.tail=s2->list.tail;
}
int main()
{
    stack ms1;
    stack ms2;

    ms1.push(6);
    ms1.push(5);
    ms1.push(4);
    ms2.push(9);
    ms2.push(8);
    ms2.push(7);
    merge(&ms1,&ms2);
    ms1.display();
    ms1.pop();
    ms1.pop();
    ms1.pop();
    ms1.pop();
    ms1.display();
    cout<<ms1.top()<<endl;
    return 0;
}
