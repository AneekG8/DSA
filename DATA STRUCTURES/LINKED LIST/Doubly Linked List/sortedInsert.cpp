//sorted insertion with head and tail pointer
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
/* Given a node as next_node, insert a new node before the given node */
void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data)
{
	/*1. check if the given next_node is NULL */
	if (next_node == NULL) {
		printf("the given next node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* 3. put in the data */
	new_node->data = new_data;

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


void sortedInsert(DLL &list,int val)
{
    if(!list.head)
        list.push(val);
    else{
        if(val<list.head->data)
            list.push(val);
        else{
            Node* temp=list.head;
            while(temp && val>temp->data)
                temp=temp->next;
            if(!temp)
                list.append(val);
            else
                insertBefore(&(list.head),temp,val);
        }
    }
}
int main()
{
    DLL List;
    sortedInsert(List,5);
    sortedInsert(List,10);
    sortedInsert(List,15);
    sortedInsert(List,7);
    sortedInsert(List,0);
    sortedInsert(List,25);
    List.display();
    List.rdisplay();
    return 0;
}
template<typename t>
void swap(t *a,t *b)
{
    int temp=*b;
    *a=*b;
    *b=temp;
}
