//reverse a stack without recursion in O(1) space and O(n) time

//ALGO:
//use stack with linked list

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
    DLL()
    {
        head=NULL;
    }
    DLL(int val)
    {
        head=new Node;
        head->data=val;
        head->next=NULL;
        head->prev=NULL;
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
    }
    void append(int val)
    {
        Node* new_node=new Node;
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
};

//reverse the original linked list

//swap next and prev pointer of each node
//set the head

void reverse(DLL *List)
{
    Node* curr;
    Node* temp=List->head;
    while(temp)
    {
        curr=temp;
        temp=curr->next;
        swap(curr->prev,curr->next);
    }
    List->head=curr;
}

//stack with DLL structure
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

void reverse(stack* s)
{
    reverse(&(s->list));
}
int main()
{
    stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.display();

    reverse(&s);

    s.display();

    s.pop();
    cout<<s.top()<<endl;
    s.display();


    return 0;
}
template<typename t>
void swap(t *a,t *b)
{
    int temp=*b;
    *a=*b;
    *b=temp;
}
