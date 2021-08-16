//clone a tree with random pointers

#include<bits/stdc++.h>
using namespace std;

class Node{

public:
    int key;
    Node *left,*right,*random;

    Node(int x)
    {
        key=x;
        left=right=random=NULL;
    }
};


//in order
void printInorder(Node* node)
{
    if (node == NULL)
        return;

    /* First recur on left sutree */
    printInorder(node->left);

    /* then print data of Node and its random */
    cout << "[" << node->key << " ";
    if (node->random == NULL)
        cout << "NULL], ";
    else
        cout << node->random->key << "], ";

    /* now recur on right subtree */
    printInorder(node->right);
}


//create clone tree and map
Node* createClone(Node* tree,Node* clone,unordered_map<Node*,Node*>& m)
{
    if(!tree)
        return NULL;

    clone=new Node(tree->key);
    m[tree]=clone;

    clone->left=createClone(tree->left,clone->left,m);

    clone->right=createClone(tree->right,clone->right,m);

    return clone;
}

//now copy randoms using map
void copyRandom(Node* tree,Node* clone,unordered_map<Node*,Node*> m)
{
    if(tree)
    {
        clone->random=m[tree->random];

        copyRandom(tree->left,clone->left,m);

        copyRandom(tree->right,clone->right,m);
    }
}


//main function that completely clones a tree
Node* cloneTree(Node* tree)
{
    Node* clone;

    unordered_map<Node*,Node*> m;

    clone=createClone(tree,clone,m);

    copyRandom(tree,clone,m);

    return clone;
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
      // Node* tree = NULL;

    //  Test No 3
    //    Node* tree = new Node(1);

    //  Test No 4
    /*  Node* tree = new Node(1);
        tree->left = new Node(2);
        tree->right = new Node(3);
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
