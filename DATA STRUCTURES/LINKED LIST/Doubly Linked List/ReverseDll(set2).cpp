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

//push function to insert a node to the beginning
void push(DLL* List,Node* new_node)
{
        new_node->next=List->head;
        new_node->prev=NULL;
        if(List->head)
            List->head->prev=new_node;
        List->head=new_node;
}

void reverse(DLL* List)
{
    DLL* new_list=new DLL;
    Node* curr=List->head;
    Node* next=NULL;

    while(curr)
    {
        next=curr->next;
        push(new_list,curr);
        curr=next;
    }

    List->head=new_list->head;
}

int main()
{
    DLL List;

    Node* node=new Node;
    node->data=1;
    push(&List,node);

    List.append(2);
    List.append(3);
    List.append(4);
    List.append(5);
    List.append(6);
    List.append(7);
    List.append(8);

    List.display();

    node=new Node;
    node->data=0;
    push(&List,node);

    List.display();

    reverse(&List);
    List.display();
    return 0;
}
template<typename t>
void swap(t *a,t *b)
{
    int temp=*b;
    *a=*b;
    *b=temp;
}
