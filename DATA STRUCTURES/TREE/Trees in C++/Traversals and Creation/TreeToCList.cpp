//**convert** a tree to circular doubly linked list


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




//the goal is to create a function which returns head of the list

//we convert the tree to a list in its inorder fashion



//method:
/*
The idea can be described using below steps.
1) Write a general purpose function that concatenates two given circular doubly lists (This function is explained below).
2) Now traverse the given tree
….a) Recursively convert left subtree to a circular DLL. Let the converted list be leftList.
….a) Recursively convert right subtree to a circular DLL. Let the converted list be rightList.
….c) Make a circular linked list of root of the tree, make left and right of root to point to itself.
….d) Concatenate leftList with list of single root node.
….e) Concatenate the list produced in step above (d) with rightList.

Note that the above code traverses tree in Postorder fashion. We can traverse in inorder fashion also.
We can first concatenate left subtree and root, then recur for right subtree and concatenate the result
with left-root concatenation.
*/


//function for concatenating two circular lists
TreeNode* concatenate(TreeNode* leftList,TreeNode* rightList)
{
    if(!leftList)
        return rightList;
    if(!rightList)
        return leftList;

    //last node of left list
    TreeNode* leftLast=leftList->left;

    //last node of right list
    TreeNode* rightLast=rightList->left;


    leftLast->right=rightList;
    rightList->left=leftLast;

    leftList->left=rightLast;
    rightLast->right=leftList;

    return leftList;
}
TreeNode* treeToCDLL(TreeNode* root)
{

    if(root)
    {
        TreeNode* leftList=treeToCDLL(root->left);

        TreeNode* rightList=treeToCDLL(root->right);

        //make a cdll with root only
        root->left=root->right=root;

        //concatenate with left and right list
        return concatenate(concatenate(leftList,root),rightList);
    }

    return NULL;
}

TreeNode* treeToCDLL(Tree t)
{

    TreeNode* head=treeToCDLL(t.root);
    return head;
}

void printCList(TreeNode* head_ref)
{
    TreeNode* head=head_ref;
    while(head->right!=head_ref)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
    cout<<head->data<<endl;
}


int main()
{
    Tree t;

    t.createTree();

    t.inorder();
    cout<<endl;

    TreeNode* head=treeToCDLL(t);

    printCList(head);

    return 0;

}



