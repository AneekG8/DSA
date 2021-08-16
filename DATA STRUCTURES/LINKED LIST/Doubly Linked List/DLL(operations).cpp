#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
    Node* prev;
}Node;

class DLL{
private:
    Node* head;
public:
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
    Node* getLast()
    {
        Node* last=head;
        while(last->next)
            last=last->next;
        return last;
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
int main()
{
    DLL List(5);
    List.append(20);
    List.push(10);
    List.push(15);
    List.append(30);
    List.display();
    List.Delete(5);
    List.display();
    List.append(40);
    List.display();
    return 0;
}
