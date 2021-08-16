//evaluate an expression tree
//the data part of nodes here are taken as strings for the sake of multiple digit numbers


#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class TreeNode{
public:
    TreeNode* left;
    string data;
    TreeNode* right;

    TreeNode()
    {

    }

    TreeNode(string x)
    {
        left=right=NULL;
        data=x;
    }
};


//utility function
bool isOperator(char c)
{
    if(c=='+' || c== '-' || c=='*' || c=='/' || c=='^')
        return true;

    return false;
}


//expression tree class
class expTree{

public:
    TreeNode *root;

    /*void createTree(string postfix)  //single digit integer postfix expression
    {
        stack<TreeNode*> s;

        TreeNode *t,*t1,*t2;

        for(int i=0; postfix[i]!='\0'; i++)
        {
            if(!isOperator(postfix[i]))
            {
                t=new TreeNode(postfix[i]);
                s.push(t);
            }
            else
            {
                t=new TreeNode(postfix[i]);

                t2=s.top();
                s.pop();

                t1=s.top();
                s.pop();

                t->left=t1;
                t->right=t2;

                s.push(t);
            }
        }

        root=s.top();
        s.pop();
    }*/

    void createTree()
    {
        string x;
        cout<<"enter root value:"<<endl;
        cin>>x;

        root=new TreeNode;
        root->data=x;
        root->left=root->right=NULL;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            TreeNode* t=q.front();

            cout<<"enter left child for "<<t->data<<":"<<endl;
            cin>>x;

            if(x!="_")
            {
                TreeNode* new_node=new TreeNode;
                new_node->data=x;
                new_node->left=new_node->right=NULL;

                t->left=new_node;

                q.push(new_node);
            }

            cout<<"enter right child for "<<t->data<<":"<<endl;
            cin>>x;

            if(x!="_")
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

    //in order to print the parantheses
    //we need a pair of parantheses for each operator
    void inorder(TreeNode* p)
    {
        if(p)
        {
            //only operators have both the children
            if(p->left && p->right)
                cout<<"(";

            inorder(p->left);
            cout<<p->data;
            inorder(p->right);

            if(p->left && p->right)
                cout<<")";
        }
    }

    void inorder()
    {
        inorder(root);
    }

    //evaluation of tree
    int eval(TreeNode* root)
    {
        //empty tree
        if(!root)
            return 0;

        //for leaf nodes
        if(!root->left && !root->right)
            return stoi(root->data);

        //for operators
        else
        {
            int l_val=eval(root->left);
            int r_val=eval(root->right);

            if(root->data=="/")
                return l_val/r_val;

            if(root->data=="*")
                return l_val*r_val;

            if(root->data=="+")
                return l_val+r_val;

            if(root->data=="-")
                return l_val-r_val;
        }
    }

    int eval()
    {
        eval(root);
    }

};

int main()
{
    expTree t;

    t.createTree();

    t.inorder();

    cout<<endl<<t.eval()<<endl;

    return 0;
}

