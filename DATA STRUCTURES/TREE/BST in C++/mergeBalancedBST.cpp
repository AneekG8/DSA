//merge two balanced trees to make one balanced tree


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


//function to create list from tree inplace
TreeNode* treeToDLL(TreeNode* curr)
{
    static TreeNode* head=NULL;

    if(curr)
    {
        treeToDLL(curr->right);

        if(head)
        {
            curr->right=head;
            head->left=curr;
        }
        head=curr;

        treeToDLL(curr->left);
    }

    return head;
}

void fixPrevPtr(TreeNode* curr)
{
    static TreeNode* prev=NULL;
    if(curr)
    {
        fixPrevPtr(curr->left);

        curr->left=prev;
        prev=curr;

        fixPrevPtr(curr->right);
    }
}

//now we fix the next(right) pointers

//method:
//as we have already connected the nodes(as a chain) with left pointers

//we can easily traverse starting from rightmost node
//and fix the right pointers

TreeNode* fixNextPtr(TreeNode* root)
{
    TreeNode* last=root;

    //rightmost node
    while(last->right)
        last=last->right;

    //traverse to left and fix the next(right) pointers
    while(last->left)
    {
        last->left->right=last;
        last=last->left;
    }

    return last;    //this will be head of the list as we finish at the leftmost node
}

TreeNode* treeToDLL2(TreeNode* root)
{
    fixPrevPtr(root);

    return fixNextPtr(root);
}

//merge two sorted lists in place
TreeNode* SortedMerge(TreeNode* a,TreeNode* b)
{
    TreeNode* result = NULL;
    static TreeNode* p=NULL;
    /* Base cases */
    if (a == NULL)
    {
        b->left=p;
        return b;
    }
    else if (b == NULL)
    {
        a->left=p;
        return(a);

    }
    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;

        result->left=p;

        p=result;

        result->right = SortedMerge(a->right, b);


    }
    else
    {
        result = b;

        result->left=p;

        p=result;

        result->right = SortedMerge(a, b->right);


    }
    return(result);
}


//function to create a BST from a sorted linked list of n nodes in place
TreeNode* sortedListToBST(TreeNode* head_ref,int n)
{
    static TreeNode* head=head_ref;

    if(n<=0)
        return NULL;

    //construct left subtree
    TreeNode* left=sortedListToBST(head,n/2);

    //make the middle element root
    TreeNode* root=head;

    root->left=left;

    //traverse to right
    head=head->right;

    //construct right subtree
    root->right=sortedListToBST(head,n-n/2-1);

    return root;
}


//utility function to count node
int count(TreeNode* head)
{
    if(!head)
        return 0;
    return count(head->right)+1;
}


void printList(TreeNode* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
    cout<<endl;
}

void rprintList(TreeNode* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->left;
    }
    cout<<endl;
}



//main function to merge two balanced BST
BST mergeBalancedBST(BST t1,BST t2)
{
    //convert the trees to linked lists
    TreeNode* head1=treeToDLL(t1.root);

    TreeNode* head2=treeToDLL2(t2.root);

    //merge those two sorted linked lists
    TreeNode* mergeHead=SortedMerge(head1,head2);


    //convert the sorted list to BST
    BST t;

    t.root=sortedListToBST(mergeHead,count(mergeHead));

    return t;

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
    t2.insert(40);
    t2.insert(120);

    BST mergedTree=mergeBalancedBST(t1,t2);

    mergedTree.inorder();

    return 0;
}
