//reverse alternate levels of a binary Tree

#include<iostream>
#include<queue>
#include<stack>
#include<deque>
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

    //utility function for level order traversal
    void printLevel(TreeNode* root,int level)
    {
        if(!root)
            return;
        if(!level)
            return;
        if(level==1)
            cout<<root->data<<" ";
        else if(level>1)
        {
            printLevel(root->left,level-1);
            printLevel(root->right,level-1);
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

    void levelorder()
    {
        int h=height(root);

        for(int i=1;i<=h;i++)
        {
            printLevel(root,i);
        }
        cout<<endl;
    }
};

//utility function swap datas of two nodes
void swapData(TreeNode* a,TreeNode* b)
{
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}

//method 1 iterative

/*
1) Access nodes level by level.
2) If current level is odd, then store nodes of this level in an array.
3) Reverse the array and store elements back in tree.
*/
void reverseAlternateLevels(Tree t)
{
    queue<TreeNode*> q;
    vector<TreeNode*> v;

    int level=0;

    TreeNode* temp=t.root;
    q.push(temp);

    while(!q.empty())
    {
        level++;
        int size=q.size();

        for(int i=0;i<size;i++)
        {
            temp=q.front();
            q.pop();

            if(level%2==0)
            {
                v.push_back(temp);
            }

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        //reverse the even levels
        if(level%2==0)
        {
            int i=0;
            int j=v.size()-1;
            while(i<j)
            {
                swapData(v[i],v[j]);
                i++;
                j--;
            }
            v.clear();
        }
    }
}



//method 2 recursion

//utility function preorder method
void preorder(TreeNode* node1,TreeNode* node2,int level)
{
        if(!node1 || !node2)
            return;
        if(level%2==0)
            swapData(node1,node2);

        preorder(node1->left,node2->right,level+1);
        preorder(node1->right,node2->left,level+1);
}


//wrapper function
void reverseAlternateLevelsRecur(Tree t)
{
    preorder(t.root->left,t.root->right,2);
}
int main()
{
    Tree t;

    t.createTree();

    t.levelorder();

    reverseAlternateLevelsRecur(t);

    t.levelorder();

    return 0;
}
