//Given a Binary Search Tree, find median of it.

//!If no. of nodes are even: then median = ((n/2th node + (n/2+1)th node) /2
//!If no. of nodes are odd : then median = (n/2+1)th node.

#include<iostream>
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


//!first we find count of nodes using morris inorder traversal for O(1) space

//utility function to find inorder predecessor
TreeNode* findInPre(TreeNode* root)
{
    TreeNode* pre=root->left;

    while(pre->right && pre->right!=root)
    {
        pre=pre->right;
    }

    return pre;
}

int count(BST t)
{
    TreeNode* curr=t.root;

    int count=0;

    while(curr)
    {
        if(!curr->left)
        {
            //visit
            count++;

            //go to right subtree
            curr=curr->right;
        }

        else
        {
            //find inorder predecessor
            TreeNode* pre=findInPre(curr);

            //if not threaded
            if(!pre->right)
            {
                //thread
                pre->right=curr;

                //go to left child
                curr=curr->left;
            }

            //if thread exists
            else
            {
                //remove thread
                pre->right=NULL;

                //visit
                count++;

                //go to right subtree
                curr=curr->right;
            }
        }
    }
    return count;
}


//now main function that returns median using morris inorder
int median(BST t)
{
    int median=0;

    TreeNode* curr=t.root;

    int n=count(t);

    int c=0;

    while(curr)
    {
        if(c>=n/2+1)
            break;

        if(!curr->left)
        {
            //visit
            c++;

            //only if n is even
            if(n%2==0 && c==n/2)
                median+=curr->data;

            if(c==n/2+1)
                median+=curr->data;

            //go to right subtree
            curr=curr->right;
        }

        else
        {
            //find inorder predecessor
            TreeNode* pre=findInPre(curr);

            //if not threaded
            if(!pre->right)
            {
                //thread
                pre->right=curr;

                //go to left child
                curr=curr->left;
            }

            //if thread exists
            else
            {
                //remove thread
                pre->right=NULL;

                //visit
                c++;

                //only if n is even
                if(n%2==0 && c==n/2)
                    median+=curr->data;

                if(c==n/2+1)
                    median+=curr->data;

                //go to right subtree
                curr=curr->right;
            }
        }


    }

    return (n%2==0) ? median/2 : median;
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

    cout<<median(t)<<endl;

    return 0;
}
