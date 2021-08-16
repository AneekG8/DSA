//find LIS from a tree
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left, *right;
    int lis = -1;    //an extra lis field added
};

node* newNode( int data )
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/*void initLis(node* root,unordered_map<node*,int> lis)
{
    if(!root)
        return;

    lis[root] = -1;

    initLis(root->left,lis);

    initLis(root->right,lis);

}*/
int LIS(node* root)
{
    if(!root)
        return 0;

    if(root->lis != -1)
        return root->lis;

    node* l = root->left;
    node* r = root->right;

    //excluding root
    int exc = LIS(l)+LIS(r);

    //including root
    int inc = 1;

    if(l)
        inc += LIS(l->left)+LIS(l->right);

    if(r)
        inc += LIS(r->left)+LIS(r->right);

    return root->lis = max(inc,exc);
}


int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    //unordered_map<node*,int> lis;

    cout << "Size of the Largest"
         << " Independent Set is "
         << LIS(root);

    return 0;
}
