//check that if every node of a BST has single child only from its given preorder traversal

#include<iostream>
using namespace std;

//if every node has single child
//all elements right to that node must be either lesser or greater

//so if we find that both the first element after that node and the last element of pre
//are either lesser or greater than current node return true

//because as it is a valid BST
//suppose we the first element after current node is lesser

//now if we find an element that is greater than current,so from there right subtree starts

//now there must not be any element lesser than current node residing in its right subtree

//so first and last node after current element being in the same subtree ensures the same for all other

bool checkSingleChild(int arr[],int n)
{
    for(int i=0;i<n-2;i++)
    {
        int firstDiff=arr[i]-arr[i+1];

        int lastDiff=arr[i]-arr[n-1];

        //both are of same sign
        if((firstDiff*lastDiff) < 0)
            return false;
    }
    return true;
}


int main()
{
    int pre[]={20, 10, 11, 13, 12};

    int n=sizeof(pre)/sizeof(int);

    checkSingleChild(pre,n) ? cout<<"YES" : cout<<"NO"<<endl;

    return 0;
}
