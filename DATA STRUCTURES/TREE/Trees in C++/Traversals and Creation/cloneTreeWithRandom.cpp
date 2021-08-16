#include<iostream>
#include<unordered_map>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child*/
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node *random;

    Node(int x)
    {
        data=x;
        left=right=random=NULL;
    }
};

/* The function should clone the passed tree and return
   root of the cloned tree */
Node* copyLeftRight(Node *root,unordered_map<Node*,Node*>& m)
{
    if(!root)
        return NULL;

    Node* clone=new Node(root->data);
    m[root]=clone;  //store equivalent cloned nodes

    clone->left=copyLeftRight(root->left,m);

    clone->right=copyLeftRight(root->right,m);

    return clone;
}

void cloneRandom(Node *root,Node* clone,unordered_map<Node*,Node*>& m)
{
    if(!root)
        return;

    clone->random=m[root->random];

    cloneRandom(root->left,clone->left,m);

    cloneRandom(root->right,clone->right,m);
}
Node* cloneTree(Node* root)
{
   //Your code here
   if(root)
   {
    unordered_map<Node*,Node*> m;

    Node* clone=copyLeftRight(root,m);

    cloneRandom(root,clone,m);

    return clone;
   }
   return NULL;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;

    /* First recur on left sutree */
    printInorder(node->left);

    /* then print data of Node and its random */
    cout << "[" << node->data << " ";
    if (node->random == NULL)
        cout << "NULL], ";
    else
        cout << node->random->data << "], ";

    /* now recur on right subtree */
    printInorder(node->right);
}

int main()
{
    //Test No 1
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;

    //  Test No 2
    //    tree = NULL;

    //  Test No 3
    //    tree = newNode(1);

    //  Test No 4
    /*    tree = newNode(1);
        tree->left = newNode(2);
        tree->right = newNode(3);
        tree->random = tree->right;
        tree->left->random = tree;
    */

    cout << "Inorder traversal of original binary tree is: \n";
    printInorder(tree);

    Node *clone = cloneTree(tree);

    cout << "\n\nInorder traversal of cloned binary tree is: \n";
    printInorder(clone);

    return 0;
}
