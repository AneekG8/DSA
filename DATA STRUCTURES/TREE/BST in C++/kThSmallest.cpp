//find kth smallest element in a BST starting from 1

#include<iostream>
using namespace std;

class TreeNode{

public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int lcount;

    TreeNode(int x)
    {
        data=x;
        left=right=nullptr;
        lcount=0;
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
        {
            root->lcount++;
            root->left=insert(root->left,x);

        }
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
             return;
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


//do inorder traversal
//return the node when kth node is visited

//!using morris inorder traversal we can do it in O(1) extra space

//TIME: O(n)

void kthSmallestUtil(TreeNode* root,int& k,TreeNode*& res)
{
    if(!root || k<0)
        return;
    if(root)
    {
        kthSmallestUtil(root->left,k,res);

        if(k==1)
        {
            res=root;
            k--;    //because of the return statement k does not decrease in this step
            return;
        }
        k--;

        //for unnecessary recursive calls
        if(k<=0)
            return;

        kthSmallestUtil(root->right,k,res);
    }
}

TreeNode* kthSmallestInorder(BST t,int k)
{
    TreeNode* res;

    kthSmallestUtil(t.root,k,res);

    return res;
}


//!another method is to keep track of the rank of the nodes

//for this method we need to find the count o the nodes in left subtree

//so if k==lcount+1 root is the kth node return root
//if(k<lcount+1) search in left subtree only
//else search in right subtree

//so if we use a recursive function to find lcount we will need extra time

//rather we will manipulate the BST class and add lcount member in each node
// so while inserting we can increment the lcount to get its rank

TreeNode* kThSmallest(TreeNode* root,int k)
{
    if(!root)
        return NULL;

    if(k==root->lcount+1)
        return root;

    else if(k<root->lcount+1)
        return kThSmallest(root->left,k);

    else
        return kThSmallest(root->right,k-root->lcount-1);
}

//wrapping function
TreeNode* kThSmallest(BST t,int k)
{
    return kThSmallest(t.root,k);
}
int main()
{
    BST t;

    t.insert(20);
    t.insert(8);
    t.insert(22);
    t.insert(4);
    t.insert(12);
    t.insert(10);
    t.insert(14);

    t.inorder();

    cout<<kthSmallestInorder(t,4)->data<<endl;

    return 0;
}
