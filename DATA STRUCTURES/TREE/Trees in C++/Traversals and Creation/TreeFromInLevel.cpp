//build tree from its inorder and levelorder traversal


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

//utility function

// returns level order subtree array
int* extractLevel(int in[],int level[],int m,int n)   //m is the size of inorder left(or right) subtree array
{
    int* newlevel=new int[m];

    int j=0;
    //!note in[] here is already the left (or right) subtree
    //!whereas level[] is the actual level[](including previous level)

    //now we extract only those nodes from the actual level[] which are present in in[]
    for(int i=0;i<n;i++)
    {
        if(search(in,level[i],m)!=-1)
        {
            newlevel[j]=level[i];
            j++;
        }
    }

    return newlevel;
}

TreeNode* buildTree(int in[],int level[],int n)
{
    if(n<=0)
        return NULL;
    if(n==1)
        return new TreeNode(level[n-1]);

    TreeNode* root=new TreeNode(level[0]);

    //index of root in inorder
    int r=search(in,level[0],n);

    //extract left and right subtree levels
    int* llevel=extractLevel(in,level,r,n);

    int* rlevel=extractLevel(in+r+1,level,n-r-1,n);

    //if left subtree exists
    if(r!=0)
        root->left=buildTree(in,llevel,r);

    //if right subtree exists
    if(r!=n-1)
        root->right=buildTree(in+r+1,rlevel,n-r-1);

    return root;
}

//wrapper function
Tree createTree(int in[],int level[],int n)
{
    Tree t;
    t.root=buildTree(in,level,n);

    return t;
}
int main()
{
    int in[]={4,8,10,12,14,20,22};
    int level[]={20,8,22,4,12,10,14};

    int n=sizeof(in)/sizeof(int);

    Tree t=createTree(in,level,n);

    t.inorder();
    cout<<endl;

    t.preorder();

    return 0;
}


