//create a BST from preorder traversal

#include<iostream>
#include<stack>
using namespace std;

class TreeNode{

public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        data=x;
        left=right=nullptr;
    }
};


class BST{

public:
    TreeNode* root;

    BST()
    {
        root=nullptr;
    }

    //!IMPORTANT for using a void recursive function use a double pointer
    //to manipulate the actual root

    //this is the recursive function with double pointer
    /*void insert(TreeNode** root,int x)
    {
        if(!*root)
        {
            *root=new TreeNode(x);
            //return *root;
        }
        if((*root)->data==x)
            return; //root;
        else if(x<(*root)->data)
            insert(&((*root)->left),x);
        else
            insert(&((*root))->right,x);

            //return root;
     }

     //wrapper function for insert(double pointer)
     void insert(int x)
     {
         insert(&root,x);
     }*/

     //!RECURSIVE function for insertion

    TreeNode* insert(TreeNode* root,int x)
    {
        if(!root)
        {
            root=new TreeNode(x);
            return root;
        }

        if(root->data==x)
            return root;    //!important

        else if(x<root->data)
            root->left=insert(root->left,x);

        else
            root->right=insert(root->right,x);

            return root;
     }

     //wrapper function for insert
     void insert(int x)
     {
         root=insert(root,x);
     }

     //!ITERATIVE function for insertion
     void insertItr(int x)
     {
         if(!root)
         {
             root=new TreeNode(x);
         }

         //keep track of the previously visited node
         TreeNode* p,*c=root;

         while(c)
         {
             p=c;

             if(c->data==x)
                return;

             else if(x<c->data)
                c=c->left;

             else
                c=c->right;
         }

         if(x<p->data)
            p->left=new TreeNode(x);

         else
            p->right=new TreeNode(x);
     }


     //!RECURSIVE function for search
     TreeNode* search(TreeNode* root,int x)
     {
         if(!root)
            return nullptr;

         if(root->data==x)
            return root;

         else if(x<root->data)
            return search(root->left,x);

         else
            return search(root->right,x);
     }

     //wrapper function for search
     TreeNode* search(int x)
     {
         return search(root,x);
     }


     //!ITERATIVE function for search
     TreeNode* searchItr(int x)
     {
         TreeNode* curr=root;

         while(curr)
         {
             if(curr->data==x)
                return curr;

             else if(x<curr->data)
                curr=curr->left;

             else
                curr=curr->right;
         }

         return curr;
     }



     //!inorder
     void inorder(TreeNode* root)
     {
         if(root)
         {
             inorder(root->left);

             cout<<root->data<<" ";

             inorder(root->right);
         }
     }

     //wrapper for inorder
     void inorder()
     {
         inorder(root);
         cout<<endl;
     }

     int height(TreeNode* root);

     TreeNode* inPre(TreeNode* root);

     TreeNode* inSucc(TreeNode* root);

     TreeNode* Delete(TreeNode* root,int x)
     {
         if(!root)
            return nullptr;

         //leaf node
         if(!root->left && ! root->right && root->data==x)
         {
             delete(root);

             return nullptr;
         }

         if(x<root->data)
         {
             root->left=Delete(root->left,x);
         }

         else if(x>root->data)
         {
             root->right=Delete(root->right,x);
         }

         else
         {
             if(height(root->left)>height(root->right))
             {
                 TreeNode* q=inPre(root);

                 root->data=q->data;

                 root->left=Delete(root->left,q->data);
             }

             else
             {
                 TreeNode* q=inSucc(root);

                 root->data=q->data;

                 root->right=Delete(root->right,q->data);
             }
         }

         return root;
     }

     //wrapping function for deletion

     void Delete(int x)
     {
         root=Delete(root,x);
     }

};


int BST::height(TreeNode* root)
{
    if(!root)
        return 0;

    int x=height(root->left);

    int y=height(root->right);

    return (x>y) ? x+1 : y+1;
}

TreeNode* BST::inPre(TreeNode* root)
{
    TreeNode* pre=root->left;

    while(pre->right)
        pre=pre->right;

    return pre;
}

TreeNode* BST::inSucc(TreeNode* root)
{
    TreeNode* succ=root->right;

    while(succ->left)
        succ=succ->left;

    return succ;
}


//!ITERATIVE function for creating a BST from preorder

BST buildFromPreItr(int pre[],int n)
{
    BST t;

    TreeNode* p;

    stack<TreeNode*> s;
    s.push(new TreeNode(INT_MAX));

    int i=0;

    while(i<n)
    {
        //first step create the root
        if(!t.root)
        {
            t.root=new TreeNode(pre[i++]);

            p=t.root;
        }

        if(pre[i] < p->data)
        {
            //left child of p
            p->left=new TreeNode(pre[i++]);

            //push p to stack
            s.push(p);

            //keep track of the latest node
            p=p->left;
        }

        else
        {
            if(pre[i] > p->data && pre[i] < s.top()->data)
            {
                p->right=new TreeNode(pre[i++]);

                p=p->right;
            }
            else
            {
                p=s.top();
                s.pop();
            }
        }
    }

    return t;
}

//!RECURSIVE solution from BST from preorder
//!O(n^2)
TreeNode* buildFromPreRecurUtil(int pre[],int n)
{
    if(n==0)
        return NULL;

    if(n==1)
        return new TreeNode(pre[0]);

    else
    {
        //create root
        TreeNode* root=new TreeNode(pre[0]);

        //find the index of first element in pre[] that is greater than root
        //basically from there right subtree starts
        int i;
        for(i=1;i<n;i++)
        {
            if(pre[i]>root->data)
                break;
        }

        root->left=buildFromPreRecurUtil(pre+1,i-1);

        root->right=buildFromPreRecurUtil(pre+i,n-i);

        return root;
    }
}

//wrapping function
BST buildFromPreRecur(int pre[],int n)
{
    BST t;

    t.root=buildFromPreRecurUtil(pre,n);

    return t;
}


//!METHOD 2 RECURSION
/*
The idea used here is inspired from method 3 of this post. The trick is to set a range {min .. max} for every node.
Initialize the range as {INT_MIN .. INT_MAX}.
The first node will definitely be in range, so create root node.
To construct the left subtree, set the range as {INT_MIN …root->data}.
If a values is in the range {INT_MIN .. root->data},
the values is part part of left subtree. To construct the right subtree, set the range as {root->data..max .. INT_MAX}.
*/

TreeNode* buildFromPreRecur2(int pre[],int min,int max,int n)
{
    static int i=0;

    if(i>=n)
        return NULL;

    TreeNode* root=NULL;
    if(pre[i]>min && pre[i]<max)
    {
        root=new TreeNode(pre[i++]);

        root->left=buildFromPreRecur2(pre,min,root->data,n);

        root->right=buildFromPreRecur2(pre,root->data,max,n);
    }

    return root;
}

//wrapping function
BST buildFromPreRecur2(int pre[],int n)
{
    BST t;

    t.root=buildFromPreRecur2(pre,INT_MIN,INT_MAX,n);

    return t;
}


int main()
{
    int pre[]={30,20,10,15,25,40,50,45};

    int n=sizeof(pre)/sizeof(int);

    BST t=buildFromPreRecur2(pre,n);

    t.inorder();

    return 0;
}
