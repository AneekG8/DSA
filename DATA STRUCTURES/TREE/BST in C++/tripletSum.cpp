//find triplet from a BST that adds up to a given sum

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


//!method 1: brute force time: O(n^3)

//!method 2: store inorder in an array and then search for triplets
//time: O(n^2)  space: O(n)

//!method 3: convert tree into a DLL in place and search for triplets
//time: O(n^2)   space: O(logn) only if tree is balanced
//!this method modifies the tree


void printList(TreeNode* tail)
{
    while(tail)
    {
        cout<<tail->data<<" ";
        tail=tail->left;
    }
}
void DLLfromTree(TreeNode* root,TreeNode*& head,TreeNode*& tail)
{
    if(root)
    {
        DLLfromTree(root->right,head,tail);

        root->right=head;

        if(head)
            head->left=root;

        head=root;

        //tail will store the right most node only
        if(!tail)
            tail=root;

        DLLfromTree(root->left,head,tail);
    }
}

//search for triplets in a DLL
bool searchTriplets(TreeNode* head,TreeNode* tail,int sum)
{
    bool present=false;

    while(head!=tail->left)
    {
        TreeNode* start=head->right;
        TreeNode* end=tail;

        while(start!=end && start->left!=end)
        {
            int s=start->data+end->data;

            if(s==(sum-head->data))
            {
                cout<<head->data<<"+"<<start->data<<"+"<<end->data<<"="<<sum<<endl;

                start=start->right;
                end=end->left;

                present=true;
            }

            else if(s<(sum-head->data))
                start=start->right;

            else
                end=end->left;
        }

        head=head->right;
    }

    return present;
}

void findTripletSum(BST t,int sum)
{
    //convert to DLL
    TreeNode* head=nullptr,*tail=nullptr;

    DLLfromTree(t.root,head,tail);

    //search in DLL
    if(searchTriplets(head,tail,sum))
        return;

    cout<<"none"<<endl;
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

    findTripletSum(t,38);

    return 0;
}
