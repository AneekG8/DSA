#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *left,*right;
}Node;
Node *newnode(int key)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=key;
	temp->left=temp->right=NULL;
	return temp;
}
Node *insert(Node *node,int key)
{
	if(node==NULL)
		return newnode(key);
	else if(key<node->data)
	{
		node->left=insert(node->left,key);
	}
	else if(key>node->data)
	{
		node->right=insert(node->right,key);
	}
	return node;
}
void inorder(Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 
int main()
{
	Node *root=NULL;
	root=insert(root,10);
	insert(root,20);
	insert(root,50);
	insert(root,40);
	insert(root,30);
	insert(root,50);
	inorder(root);
	return 0;
}
