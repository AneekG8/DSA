//given a binary tree print the tree vertically

//!each particular horizontal distance from root of the tree is a vertical line

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/ (!important)

#include<bits/stdc++.h>
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


//!method 1

//find min and max horizontal distances from root

//now for each line no.(from min to max) traverse the tree and if hd==line no. print the node

//time taken O(n^2)

//!utility function to find min and max horizontal distance
void findMinMax(TreeNode* root,int* min,int* max,int hd)    //hd being 0 at root -ve at left and +ve at right
{
    if(root)
    {
        if(hd<*min)
            *min=hd;
        else if(hd>*max)
            *max=hd;

        findMinMax(root->left,min,max,hd-1);
        findMinMax(root->right,min,max,hd+1);
    }
}


//!for a given line no. print all the nodes with hd=line no.
void printLine(TreeNode* root,int lineNo,int hd)
{
    if(root)
    {
        if(hd==lineNo)
            cout<<root->data<<" ";

        printLine(root->left,lineNo,hd-1);
        printLine(root->right,lineNo,hd+1);
    }
}


//main function to print a tree vertically
void printVertical(Tree t)
{
    int min=0;
    int max=0;

    findMinMax(t.root,&min,&max,0);

    for(int line=min;line<=max;line++)
    {
        printLine(t.root,line,0);
        cout<<endl;
    }
}


//!method 2

//use a hash map and traverse all the nodes and map their data to their keys

//to maintain order we use map<> so time taken O(n* log n)

//using map(BST) we make sure that vertical lines are stored from left to right(min to max)
//now we can use any traversal(time taken would be same)
//but we want to make sure that for each vertical line nodes are printed level wise(top to bottom)
//so we use a level order traversal

//!utility function to map data of a node to its hd for a level
void mapLevel(TreeNode* root,int hd,int level,map<int,vector<int>>& m)
{
    if(level && root)
    {
        if(level==1)
            m[hd].push_back(root->data);

        mapLevel(root->left,hd-1,level-1,m);

        mapLevel(root->right,hd+1,level-1,m);
    }
}
//for the mapLevel function using queue<pair<node,hd>> and iterative process is a better approach


//!main function to map data of all levels and then print vertically and levelwise
void printVertical2(Tree t)
{
    int h=t.height(t.root);

    map<int,vector<int>> m;

    //map all levels
    for(int level=1;level<=h;level++)
        mapLevel(t.root,0,level,m);

    //print vertically from map
    for(auto itr=m.begin();itr!=m.end();itr++)
    {
        for(int i=0;i<(itr->second).size();i++)
            cout<<(itr->second)[i]<<" ";

        cout<<endl;
    }
}

//!using unordered map would reduce the time complexity to O(n)
//we don't have to sort the map for desired order
//we can simply use min and max hd for iteration

int main()
{
    Tree t;

    t.createTree();

    printVertical2(t);

    return 0;
}
