//sorted insertion with head and tail pointer
#include<iostream>
using namespace std;

typedef struct Node{
    int p;  //priority
    char info;
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
        head->p=val;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    bool isPresent(int key)
    {
        Node* check=head;
        while(check)
        {
            if(check->p==key) return true;
            check=check->next;
        }
        return false;
    }
    bool isEmpty()
    {
        return head==NULL?true:false;
    }
    void push(int val,char c)
    {
        Node* new_node=new Node;
        new_node->p=val;
        new_node->info=c;
        new_node->next=head;
        new_node->prev=NULL;
        if(head)
            head->prev=new_node;
        head=new_node;
        if(!tail)
            tail=new_node;
    }
    void append(int val,char c)
    {
        Node* new_node=new Node;
        tail=new_node;
        Node* last=head;
        new_node->p=val;
        new_node->info=c;
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
        while(curr->p!=key)
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
            cout<<node->info<<"|"<<node->p<<" ";
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
            cout<<node->p<<" ";
            node=node->prev;
        }
        cout<<endl;
    }
};
/* Given a node as next_node, insert a new node before the given node */
void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data,char c)
{
	/*1. check if the given next_node is NULL */
	if (next_node == NULL) {
		printf("the given next node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* 3. put in the data */
	new_node->p = new_data;
    new_node->info=c;
	/* 4. Make prev of new node as prev of next_node */
	new_node->prev = next_node->prev;

	/* 5. Make the prev of next_node as new_node */
	next_node->prev = new_node;

	/* 6. Make next_node as next of new_node */
	new_node->next = next_node;

	/* 7. Change next of new_node's previous node */
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
	/* 8. If the prev of new_node is NULL, it will be
	the new head node */
	else
		(*head_ref) = new_node;

}


void sortedInsert(DLL &list,int val,char c)     //descending order
{
    if(!list.head)
        list.push(val,c);
    else{
        if(val>list.head->p)
            list.push(val,c);
        else{
            Node* temp=list.head;
            while(temp && val<temp->p)
                temp=temp->next;
            if(!temp)
                list.append(val,c);
            else
                insertBefore(&(list.head),temp,val,c);
        }
    }
}
class PQ{

public:
    DLL list;
    void push(int val,char c)
    {
        sortedInsert(list,val,c);
    }
    void pop()
    {
        list.Delete(list.head->p);
    }
    Node* top()
    {
        return list.head;
    }
    void display()
    {
        list.display();
    }

};
int main()
{
    PQ q;
    q.push(2,'A');
    q.push(5,'Z');
    q.push(1,'J');
    q.push(10,'F');
    q.display();
    q.pop();
    q.display();
    cout<<q.top()->info<<"|"<<q.top()->p<<endl;
    q.pop();
    q.display();
    cout<<q.top()->info<<"|"<<q.top()->p<<endl;
    return 0;
}
template<typename t>
void swap(t *a,t *b)
{
    t temp=*b;
    *a=*b;
    *b=temp;
}
