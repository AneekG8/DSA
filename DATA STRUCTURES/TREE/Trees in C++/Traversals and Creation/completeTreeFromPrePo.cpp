//create a tree from its preorder and postorder traversal given that its a complete tree

//!important not possible for general tree


#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class TreeNode{
public:
    TreeNode* left;
    int data;
    TreeNode* right;

    TreeNode()
    {

    }

    TreeNode(int x)
    {
        data=x;
        left=right=NULL;
    }
};

class Tree{
public:
    TreeNode* root;
    queue<TreeNode*> q;

    Tree()
    {
        root=NULL;
    }

    Tree(TreeNode* node)
    {
        root=node;
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
                    t=NULL;
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

//utility function search

//returns index of val in arr
int search(int arr[],int val,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==val)
            return i;
    }
    return -1;
}


//method recursion

//root of the tree is pre[0]
//now if array.length is > 1 pre[1] must be left child of root
//root->left=pre[1];

//!now we find index of root->left in postorder

//!IMPORTANT left part of rleft in postorder would be leftsubtree of rleft

//so including rleft this subarray would be left subtree of root

//and right part would be right subtree(excluding root)

TreeNode* buildTreeFromPrePo(int pre[],int post[],int n)
{
    if(n==0)
        return NULL;
    if(n==1)
        return new TreeNode(pre[0]);

    TreeNode* root=new TreeNode(pre[0]);

    //index of root->left in postorder
    int rleft=search(post,pre[1],n);

    //left subtree of root
    root->left=buildTreeFromPrePo(pre+1,post,rleft+1);

    //right subtree of root
    root->right=buildTreeFromPrePo(pre+rleft+2,post+rleft+1,n-rleft-2);

    return root;
}


int main()
{
    int pre[]={1, 2, 4, 8, 9, 5, 3, 6, 7};

    int post[]={8, 9, 4, 5, 2, 6, 7, 3, 1};

    int n=sizeof(pre)/sizeof(int);

    Tree t(buildTreeFromPrePo(pre,post,n));

    t.preorder();
    cout<<endl;

    return 0;
}
