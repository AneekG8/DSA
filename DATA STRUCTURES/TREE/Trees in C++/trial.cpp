#include<iostream>
#include<vector>
#include "tree.h"

using namespace std;

typedef TreeNode Node;
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	int rev = 0;

	vector<int> res;

	queue<Node*> q;

	stack<int> s;

	if(root)
	    q.push(root);

	while(!q.empty())
	{
	    for(int i=0;i<q.size();i++)
	    {
	        Node* t = q.front();
	        q.pop();

            //visit
	        if(rev == 0)
	            res.push_back(t->data);
	        else
            {
                cout<<"into stack "<<t->data<<endl;
                s.push(t->data);
            }

	        //children
	        if(t->left)
	            q.push(t->left);

	        if(t->right)
	            q.push(t->right);
	    }

	    while(!s.empty())
	        res.push_back(s.top()),s.pop();

	    if(rev == 0)
            rev = 1;
        else
            rev = 0;
	}

	return res;
}
int main()
{
    Tree t;
    t.createTree();

    vector<int> v = zigZagTraversal(t.root);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}
