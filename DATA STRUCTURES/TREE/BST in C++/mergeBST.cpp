//merge two BST in O(h1+h2) extra space


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

//method

//we will do iterative inorder traversal of the trees simultaneously

void mergeBST(BST t1,BST t2)
{
    TreeNode* curr1=t1.root;

    TreeNode* curr2=t2.root;

    stack<TreeNode*> s1,s2;

    if(!curr1)
    {
        t2.inorder();
        return;
    }

    if(!curr2)
    {
        t1.inorder();
        return ;
    }


    while(curr1 || curr2 || !s1.empty() || s2.empty())
    {
        if(curr1 || curr2)
        {
            if(curr1)
            {
                s1.push(curr1);
                curr1=curr1->left;
            }
            if(curr2)
            {
                s2.push(curr2);
                curr2=curr2->left;
            }
        }

        else
        {
            //if any of the stack is empty that means that tree is exhausted
            //print the other tree
            if(s1.empty())
            {
                while(!s2.empty())
                {
                    curr2=s2.top();
                    s2.pop();

                    curr2->left=NULL;
                    t2.inorder(curr2);
                }
                return;
            }

            if(s2.empty())
            {
                while(!s1.empty())
                {
                    curr1=s1.top();
                    s1.pop();

                    curr1->left=NULL;
                    t1.inorder(curr1);
                }
                return;
            }

            curr1=s1.top();
            s1.pop();

            curr2=s2.top();
            s2.pop();

            if(curr1->data < curr2->data)
            {
                cout<<curr1->data<<" ";

                curr1=curr1->right;

                s2.push(curr2);
                curr2=NULL;
            }

            else
            {
                cout<<curr2->data<<" ";

                curr2=curr2->right;

                s1.push(curr1);
                curr1=NULL;
            }
        }
    }
}

int main()
{
    BST t1;

    t1.insert(100);
    t1.insert(50);
    t1.insert(300);
    t1.insert(20);
    t1.insert(70);

    BST t2;
    t2.insert(80);
    t2.insert(60);
    t2.insert(40);
    t2.insert(50);
    t2.insert(120);

    mergeBST(t1,t2);

    cout<<endl;

    t1.inorder();

    t2.inorder();

    return 0;
}
