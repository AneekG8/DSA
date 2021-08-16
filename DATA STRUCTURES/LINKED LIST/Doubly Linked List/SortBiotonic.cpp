//sort a biotonic doubly linked list
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
/* Given a node as next_node, insert a new node before the given node */
void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data)
{
	/*1. check if the given next_node is NULL */
	if (next_node == NULL) {
		//printf("the given next node cannot be NULL");
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
            insertBefore(&(list.head),temp,val);
        }
    }
}
DLL* sortBiotonic(DLL* List)
{
    DLL* copy_list=new DLL();
    Node* node=List->head;
    while(node)
    {
        sortedInsert(*copy_list,node->data);
        node=node->next;
    }
    delete(List);
    return copy_list;
}
int main()
{
    DLL* List=new DLL();
    List->append(2);
    List->append(5);
    List->append(7);
    List->append(12);
    List->append(10);
    List->append(6);
    List->append(4);
    List->append(1);
    List->display();
    List=sortBiotonic(List);
    List->display();
    return 0;
}
