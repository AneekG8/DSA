//Morris Preorder Traversal of binary trees

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

//utility function to get inorder predecessor

//inorder predecessor of a node is the rightmost node in its left subtree
//if a node has left child it must have a inorder predecessor
//if it does not have a left child we can directly visit the node(though it still might have an inorder predecessor)
TreeNode* findInorderPred(TreeNode* t)
{
    TreeNode* pre=t->left;
    while(pre->right && pre->right!=t)
        pre=pre->right;
    return pre;
}

//the difference with morris inorder and preorder traversal is:
//current node is visited when right child of predecessor points to null(while threading) in preorder
//while in case of inorder current node is visited while removing the thread
//in preorder threads are used only to track the way back

void MorrisPreorder(Tree t)
{
    TreeNode* current=t.root;

    if(!current)
        return;

    while(current)
    {
        //if current does not have left child visit the node and proceed to right
        if(!current->left)
        {
            cout<<current->data<<" ";
            current=current->right;
        }

        //in case current node has a left child
        //we need to find its inorder precedessor
        //right child of predecessor must be null for the first traversal
        //as it is the right most node of the left subtree of current
        //we connect predecessor to the current node through the right child(threading)
        //we visit the current node
        //and we traverse to left

        //once predecessor of a node is visited we will get to the node again(first while threading)
        //now right child of predecessor of this current node is current node itself
        //so we undo the threading,visit the node and proceed to right

        else
        {
            TreeNode* pre=findInorderPred(current);

            if(!pre->right)
            {
                cout<<current->data<<" ";
                pre->right=current;
                current=current->left;
            }
            else
            {
                pre->right=NULL;
                current=current->right;
            }
        }
    }
}

int main()
{
    Tree t;

    t.createTree();

    t.preorder();

    cout<<endl;

    MorrisPreorder(t);

    return 0;
}

