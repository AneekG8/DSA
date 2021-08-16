//construct an expression from a given postfix expression

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class TreeNode{
public:
    TreeNode* left;
    char data;
    TreeNode* right;

    TreeNode()
    {

    }

    TreeNode(char x)
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

    void createTree(string postfix)  //single digit integer postfix expression
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

};

int main()
{
    expTree t;

    string postfix;
    cin>>postfix;

    t.createTree(postfix);

    t.inorder();

    return 0;
}
