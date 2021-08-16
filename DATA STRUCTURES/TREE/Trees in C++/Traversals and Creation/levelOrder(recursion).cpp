//level order traversal with recursion
#include "tree.h"


//traversal for a certain level
void printLevel(TreeNode* root,int level)
{
    if(!root || !level)
        return;

    if(level==1)
    {
        cout<<root->data<<" ";
    }
    else
    {
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
}

void printLevelItr(TreeNode* root,int level)
{
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    int l = 1;

    while(q.size() > 1)
    {
        TreeNode* t = q.front();
        q.pop();

        if(!t)
        {
            l++;
            q.push(nullptr);
        }

        else
        {
            if(l == level)
                cout<<t->data<<" ";

            if(t->left)
                q.push(t->left);

            if(t->right)
                q.push(t->right);
        }

    }
}

//***reverse*** traversal for a certain level
void rprintLevel(TreeNode* root,int level)
{
    if(!root)
        return;
    if(!level)
        return;
    if(level==1)
    {
        cout<<root->data<<" ";
    }
    else if(level>1)
    {
        rprintLevel(root->right,level-1);
        rprintLevel(root->left,level-1);
    }
}


//level order traversal for whole Tree : O(n2)
void levelorder(Tree t)
{
    int h=t.height(t.root);

    //printLevel for each level
    for(int i=1;i<=h;i++)
    {
        printLevelItr(t.root,i);
    }
}



//***spiral*** level order traversal for whole Tree with reursion
void levelorderSpiral(Tree t)
{
    bool left=true;     //start from right
    int h=t.height(t.root);

    //printLevel for each level
    for(int i=1;i<=h;i++)
    {
        if(left)
            printLevel(t.root,i);
        else
            rprintLevel(t.root,i);

        left=!left;
    }
}

//SPIRAL level order traversal iterative
void levelorderSpiralItr(Tree t)
{
    stack<TreeNode*> s1;       //for right to left
    stack<TreeNode*> s2;        //for left to right

    TreeNode* temp=t.root;

    s1.push(temp);

    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            temp=s1.top();
            s1.pop();

            cout<<temp->data<<" ";

            if(temp->right)
                s2.push(temp->right);   //!IMPORTANT right child is pushed before left

            if(temp->left)
                s2.push(temp->left);
        }

        while(!s2.empty())
        {
            temp=s2.top();
            s2.pop();

            cout<<temp->data<<" ";

            if(temp->left)
                s1.push(temp->left);

            if(temp->right)
                s1.push(temp->right);
        }
    }
}
int main()
{
    Tree t;

    t.createTree();

    levelorder(t);
    cout<<endl;

    levelorderSpiral(t);
    cout<<endl;

    levelorderSpiralItr(t);
    cout<<endl;

    return 0;
}
