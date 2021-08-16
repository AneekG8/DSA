//given keys of two nodes find distance between them


#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class TreeNode{
public:
    TreeNode* left;
    int data;
    TreeNode* right;
};

class Tree{
public:
    TreeNode* root;
    queue<TreeNode*> q;

    Tree()
    {
        root=NULL;
    }

    void createTree()
    {
        int x;
        cout<<"enter root value:"<<endl;
        cin>>x;

        root=new TreeNode;
        root->data=x;
        root->left=root->right=NULL;

        q.push(root);

        while(!q.empty())
        {
            TreeNode* t=q.front();

            cout<<"enter left child for "<<t->data<<":"<<endl;
            cin>>x;

            if(x!=-1)
            {
                TreeNode* new_node=new TreeNode;
                new_node->data=x;
                new_node->left=new_node->right=NULL;

                t->left=new_node;

                q.push(new_node);
            }

            cout<<"enter right child for "<<t->data<<":"<<endl;
            cin>>x;

            if(x!=-1)
            {
                TreeNode* new_node=new TreeNode;
                new_node->data=x;
                new_node->left=new_node->right=NULL;

                t->right=new_node;

                q.push(new_node);
            }

            q.pop();
        }
    }

//RECURSIVE TREE TRAVERSALS
    void preorder(TreeNode* p)
    {

        if(p)
        {
            cout<<p->data<<" ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    void preorder()
    {
        preorder(root);
    }


    void inorder(TreeNode* p)
    {
        if(p)
        {
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }

    void inorder()
    {
        inorder(root);
    }


    void postorder(TreeNode* p)
    {
        if(p)
        {
            postorder(p->left);
            postorder(p->right);
            cout<<p->data<<" ";
        }
    }

    void postorder()
    {
        postorder(root);
    }


//ITERATIVE TREE TRAVERSALS

    void itrPreorder()
    {
        TreeNode* t=root;
        stack<TreeNode*> s;
        while(t || !s.empty())
        {
            if(t)
            {
                cout<<t->data<<" ";
                s.push(t);
                t=t->left;
            }
            else
            {
                t=s.top();
                s.pop();
                t=t->right;
            }
        }
    }

    void itrInorder()
    {
        TreeNode* t=root;
        stack<TreeNode*> s;
        while(t || !s.empty())
        {
            if(t)
            {
                s.push(t);
                t=t->left;
            }
            else
            {
                t=s.top();
                s.pop();
                cout<<t->data<<" ";
                t=t->right;
            }
        }
    }

    void itrPostorder()
    {
        TreeNode* t=root;
        stack<TreeNode*> s;
        long long int temp;
        while(t || !s.empty())
        {
            if(t)
            {
                s.push(t);
                t=t->left;
            }
            else
            {
                temp=(long long int)s.top();
                s.pop();
                if(temp>0)
                {
                    s.push((TreeNode*)(-temp));
                    t=(TreeNode*)temp;
                    t=t->right;
                }
                else
                {
                    t=(TreeNode*)(-temp);
                    cout<<t->data<<" ";
                    t=NULL;     //!important as both t's left and right subtrees are done visiting
                }
            }
        }
    }

    int count(TreeNode* t)
    {
        int x=0,y=0;
        if(t)
        {
            x=count(t->left);
            y=count(t->right);
            return x+y+1;
        }
        return x+y;
    }

    int leaf(TreeNode* t)
    {
        int x,y;
        if(t)
        {
            x=leaf(t->left);
            y=leaf(t->right);
            if(!t->left && !t->right)
                return x+y+1;
            else
                return x+y;
        }
        return 0;
    }

    int height(TreeNode* t)
    {
        int x=0,y=0;

        if(!t)
            return 0;

        x=height(t->left);
        y=height(t->right);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
};

//!method
//distance between two nodes is measured as the edges needed to be traversed from n1 to get to n2

//Dist(n1,n2)=Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)
//also
//Dist(n1,n2)=Dist(lca, n1) + Dist(lca, n2)

//distance of a node from root is the level node is on assuming the root to be on level 0


//!function to find lca

//assuming both n1 and n2 exists

//LCA is the first node which has n1 and n2 in different subtrees

//if one in any subtree of the other then the other node is the LCA


TreeNode* findLCAutil(TreeNode* root,int n1,int n2)
{
    if(!root)
        return NULL;

    if(root->data==n1 || root->data==n2)       //this basically searches for n1 or n2 and return that node
        return root;

    TreeNode* left=findLCAutil(root->left,n1,n2);

    TreeNode* right=findLCAutil(root->right,n1,n2);

    //left and right both non NULL means
    //for that node we have one node in left subtree and the other in right subtree
    if(left && right)
        return root;

    //case where at least one of them is NULL
    return (left!=nullptr) ? left : right;
}

//wrapping function
TreeNode* findLCA(Tree t,int n1,int n2)
{
    return findLCAutil(t.root,n1,n2);
}


//!function to find distance of a node from root(level)
int findLevel(TreeNode* root,int n,int level)
{
    if(!root)
        return -1;

    if(root->data==n)
        return level;

    int l=findLevel(root->left,n,level+1);

    return (l!=-1) ? l : findLevel(root->right,n,level+1);
}


//main function
int distance(Tree t,int n1,int n2)
{
   TreeNode* lca=findLCA(t,n1,n2);

   return findLevel(lca,n1,0) + findLevel(lca,n2,0);
}


int main()
{
    Tree t;

    t.createTree();

    int n1,n2;
    cin>>n1>>n2;

    cout<<distance(t,n1,n2)<<endl;

    return 0;
}
