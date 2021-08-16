//populate a tree i.e connect each node to its inorder successor

#include<iostream>
using namespace std;

class TreeNode{
public:
    TreeNode* left;
    int data;
    TreeNode* right;
    TreeNode* next;

    TreeNode(int x)
    {
        data=x;
        left=right=next=NULL;
    }
};

void populate(TreeNode* root)
{
    static TreeNode* next=NULL;

    //reverse inorder
    if(root)
    {
        populate(root->right);

        root->next=next;

        next=root;

        populate(root->left);
    }
}

int main()
{
     TreeNode *root = new TreeNode(10);
     root->left = new TreeNode(8);
     root->right = new TreeNode(12);
     root->left->left = new TreeNode(3);

     populate(root);

     //first inorder root
     TreeNode* node=root;
     while(node->left)
     {
         node=node->left;
     }

     //inorder traversal using next
     while(node)
     {
         cout<<node->data<<" ";
         node=node->next;
     }

     return 0;
}
