//find pairs from a BST with a given sum

#include<iostream>
#include<stack>
#include<unordered_set>
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


//!method

//do both in-order and reverse in-order traversal simultaneously

//time O(n)

//space O(logn) height=logn *for balanced*

void findPairSum(BST t,int sum)
{
    if(!t.root)
        return;

    TreeNode* t1=t.root;

    TreeNode* t2=t.root;

    stack<TreeNode*> s1,s2;

    while(1)
    {
        while(t1)
        {
            s1.push(t1);
            t1=t1->left;
        }

        while(t2)
        {
            s2.push(t2);
            t2=t2->right;
        }

        if(s1.empty() || s2.empty())
            break;

        t1=s1.top();
        t2=s2.top();

        if(t1->data>t2->data)
            break;

        if(t1->data+t2->data == sum)
        {
            if(t1->data!=t2->data)
                cout<<t1->data<<"+"<<t2->data<<"="<<sum<<endl;

            s1.pop();
            s2.pop();

            t1=t1->right;
            t2=t2->left;
        }

        else if(t1->data+t2->data>sum)
        {
            s2.pop();
            t2=t2->left;
            t1=nullptr;
        }

        else
        {
            s1.pop();
            t1=t1->right;
            t2=nullptr;
        }
    }
}

//!another method with hashing
void findPairSumUtil(TreeNode* root,unordered_set<int>& s,int sum)
{
    if(root)
    {
        findPairSumUtil(root->left,s,sum);

        if(s.find(sum-root->data)!=s.end())
        {
            cout<<root->data<<"+"<<sum-root->data<<"="<<sum<<endl;
        }
        else
            s.insert(root->data);

        findPairSumUtil(root->right,s,sum);
    }
}

//!method 3
//if we are allowed to modify the tree we can convert it to a DLL and then search pairs
//space: O(1)  time: O(n)



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

    unordered_set<int> s;
    findPairSumUtil(t.root,s,24);

    return 0;
}
