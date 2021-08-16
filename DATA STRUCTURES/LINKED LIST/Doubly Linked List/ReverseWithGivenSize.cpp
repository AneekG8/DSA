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

void reverse(Node** head,int k)
{
    Node* last=*head;
    int x=k;
    while(last->next && x-1)
    {
        last=last->next;
        x--;
    }

    Node* last_prev=(*head)->prev;
    Node* head_next=last->next;
    Node* head_prev=(*head)->prev;

    Node* curr;
    Node* temp=*head;
    while(temp && k)
    {
        curr=temp;
        temp=curr->next;
        swap(curr->prev,curr->next);
        k--;
    }
    last->prev=last_prev;
    (*head)->next=head_next;


    if(last_prev)
        last_prev->next=last;

    *head=temp;
}
void reverseWithGivenSize(DLL* List,int k)
{
    Node* head=List->head;
    int x=k;
    while(x-1)
    {
        List->head=List->head->next;
        x--;
    }
    while(head)
    {
        reverse(&head,k);
    }
}
int main()
{
    DLL List(1);
    List.append(2);
    List.append(3);
    List.append(4);
    List.append(5);
    List.append(6);
    List.append(7);
    List.append(8);
    List.display();
    reverseWithGivenSize(&List,3);
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
