//merge sort for linked lists

#include<iostream>
using namespace std;


class Node{

public:
    int data;

    Node* next;

    Node()
    {

    }

    Node(int val)
    {
        data=val;
        next=nullptr;
    }

    void display()
    {
        Node* t = this;

        while(t)
        {
            cout<<t->data<<" ";
            t=t->next;
        }

        cout<<endl;
    }
};

//(recursive)sorted merge function to merge two sorted LL

Node* sortedMerge(Node* f,Node* s)
{
    Node* res=nullptr;

    if(f==nullptr)
        return s;

    else if(s==nullptr)
        return f;

    if(f->data < s->data)
    {
        res=f;

        res->next=sortedMerge(f->next,s);
    }

    else
    {
        res=s;

        res->next=sortedMerge(f,s->next);
    }

    return res;
}

//iterative sorted merge for LL

Node* sortedMergeItr(Node* f,Node* s)
{
    Node* res=nullptr;  //start of result list
    Node* tail=res;     //end of result list

    while(f && s)
    {
        if(f->data < s->data)
        {
            if(!res)
            {
               res=f;
               tail=res;
            }
            else
            {
                Node* temp=f->next;
                tail->next=f;
                f=temp;
                tail=tail->next;
            }
        }

        else
        {
           if(!res)
            {
               res=s;
               tail=res;
            }
            else
            {
                Node* temp=s->next;
                tail->next=s;
                s=temp;
                tail=tail->next;
            }
        }
    }

    if(!f)
        tail->next=s;
    else if(!s)
        tail->next=f;

    return res;
}


//merge sort for LL

//utility function to split the list in two halves

void frontBackSplit(Node* head,Node** front,Node** back)
{
    Node* slow=head;
    Node* fast=slow;

    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    *front=head;

    *back=slow->next;

    slow->next=NULL;
}


void mergeSort(Node** head_ref)
{
    Node* head=*head_ref;

    Node* frontPart;

    Node* backPart;

    if(!head || !(head->next))
        return;

    frontBackSplit(head,&frontPart,&backPart);

    mergeSort(&frontPart);

    mergeSort(&backPart);

    *head_ref=sortedMerge(frontPart,backPart);
}

int main()
{
    Node* f = new Node(2);

    f->next = new Node(4);

    f->next->next= new Node(3);

    f->next->next->next = new Node(1);

    f->display();

    mergeSort(&f);

    f->display();


    return 0;
}
