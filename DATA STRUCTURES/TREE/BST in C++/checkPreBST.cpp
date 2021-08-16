//check if an array can represent preorder traversal of a BST

#include<bits/stdc++.h>

using namespace std;


//the idea is similar to finding next greater element

//suppose we find a NGE for a element
//so from that index onwards right subtree of that element starts(conditions applied)

//now if we find any element smaller than current element after the NGE index(i.e in right subtree)!only problem
//we can say that the traversal is invalid

//to be precise NGE might be same for multiple nodes
//!but the right subtree we get is only of the left most node of them

//so whenever we get an NGE we make the leftmost node root

bool checkPreBST(int pre[],int n)
{
    stack<int> s;

    int root=INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(pre[i]<root)
            return false;   //smaller element in right subtree

        //last popped element that is also the leftmost element among all the elements the NGE of which is found
        while(!s.empty() && s.top()<pre[i])
        {
            root=s.top();
            s.pop();
        }

        s.push(pre[i]);
    }
    return true;
}

int main()
{
    int pre[]={40,30,35,20,80,100};

    int n=sizeof(pre)/sizeof(int);

    checkPreBST(pre,n) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    return  0;
}
