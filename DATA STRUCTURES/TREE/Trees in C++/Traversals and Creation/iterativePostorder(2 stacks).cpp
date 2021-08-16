//iterative postorder traversal using two stacks

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


//the idea is to get the reverse postorder traversal in the 2nd stack using first one

//reverse postorder means (visit,right,left)
//which is similar to preorder except right node is visited before left node

void itrpostorder(Tree t)
{
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;

    TreeNode* temp=t.root;

    while(temp || !s1.empty())
    {
        if(temp)
        {
            s2.push(temp);  //except for visiting(like preorder) we push the node to s2
            s1.push(temp);

            temp=temp->right;   //(visit,right,left)
        }
        else
        {
            temp=s1.top();
            s1.pop();
            temp=temp->left;
        }
    }

    //now we fetch all items from s2
    while(!s2.empty())
    {
        temp=s2.top();
        s2.pop();

        cout<<temp->data<<" ";
    }
}

int main()
{
    Tree t;

    t.createTree();

    t.postorder();
    cout<<endl;

    itrpostorder(t);

    return 0;
}
