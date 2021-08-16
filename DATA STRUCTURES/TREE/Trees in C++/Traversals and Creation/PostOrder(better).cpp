//a postorder traversal without stack recursion

#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
#include<unordered_map>
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

//we will use a set to keep track of the visited nodes

//we can also use a bool visited flag for each node

//O(n^2)

void postorderDFS(Tree t)
{
    unordered_set<TreeNode*> visited;

    TreeNode* temp=t.root;

    while(temp && visited.find(temp) == visited.end())
    {
        //left subtree
        if(temp->left && visited.find(temp->left) == visited.end())     //temp->left->visited==false
            temp=temp->left;

        else if(temp->right && visited.find(temp->right) == visited.end())      //temp->right->visited==right
            temp=temp->right;

        else
        {
            cout<<temp->data<<" ";

            visited.insert(temp);       //temp->visited=true

            temp=t.root;
        }
    }
}


//another algorithm with O(n) complexity

//using a map to keep track of the parent node
void postorderDFS1(Tree t)
{
    unordered_map<TreeNode*,TreeNode*> m;
    m.insert(pair<TreeNode*,TreeNode*>(t.root,NULL));

    TreeNode* temp=t.root;

    while(temp)
    {
        //left subtree
        if(temp->left && m.find(temp->left) == m.end())
        {
            m.insert(pair<TreeNode*,TreeNode*>(temp->left,temp));
            temp=temp->left;
        }

        //right subtree
        else if(temp->right && m.find(temp->right) == m.end())
        {
            m.insert(pair<TreeNode*,TreeNode*>(temp->right,temp));
            temp=temp->right;
        }

        //visit
        else
        {
            cout<<temp->data<<" ";

            temp=m.find(temp)->second;
        }

    }
}

int main()
{
    Tree t;

    t.createTree();

    t.postorder();
    cout<<endl;

    postorderDFS(t);
    cout<<endl;

    postorderDFS1(t);

    return 0;
}
