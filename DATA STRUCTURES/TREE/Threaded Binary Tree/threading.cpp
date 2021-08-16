//create threads in a Binary Tree

//threading is basically linking a node's right child(which is null) to its inorder successor

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class TreeNode{
public:
    TreeNode* left;
    int data;
    TreeNode* right;

    //indicates if a node is thread node
    bool isThread=false;
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

//!method 1
//store inorder in an array
//scan every node in array and for a node with right==null link it to next element
//time: O(n)  space: O(n)

//!method 2
//we do reverse inorder and keep track of successor
//if node's right is null we connect i to its successor
//time: O(n) space: O(h)
void createThreadUtil(TreeNode* root,TreeNode* succ)
{
    if(root)
    {
        createThreadUtil(root->right,succ);

        if(!root->right && succ)
        {
            root->right=succ;
            root->isThread=true;
        }

        succ=root;

        createThreadUtil(root->left,succ);
    }
}

void createThread(Tree t)
{
    createThreadUtil(t.root,nullptr);
}

//!method 3 of threading
//morris inorder traversal
//time: O(n)  space: O(1)


//utility function to get leftmost node
TreeNode* findLeftmost(TreeNode* node)
{
    while(node && node->left)
        node=node->left;

    return node;
}


//!traversing a threaded binary tree

void inorderThreaded(Tree t)
{
    createThread(t);

    //find the leftmost node
    TreeNode* curr=findLeftmost(t.root);

    while(curr)
    {
        //we start the loop with either a leftmost node or a node whose left subtree has been visited
        cout<<curr->data<<" ";

        //ending the loop with a node whose left subtree is visited
        if(curr->isThread)
            curr=curr->right;

        //ending the loop with a leftmost node
        else
            curr=findLeftmost(curr->right);
    }
}

int main()
{
    Tree t;

    t.createTree();

    t.inorder();
    cout<<endl;

    inorderThreaded(t);

    return 0;
}
