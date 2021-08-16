//print postorder traversal from given inorder and preorder

#include<iostream>

using namespace std;

//utility function search

//returns index of val in arr
int search(int arr[],int val,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==val)
            return i;
    }
    return -1;
}

void printPostorder(int in[],int pre[],int n)
{
    //find index of root in inorder
    int root=search(in,pre[0],n);

    //traverse left subtree

    //if left subtree is not empty
    if(root!=0)
        printPostorder(in,pre+1,root);

    //traverse right subtree

    //if right subtree is not empty
    if(root!=n-1)
        printPostorder(in+root+1,pre+root+1,n-root-1);

    //print root
    cout<<pre[0]<<" ";
}

int main()
{
    int in[]={4,2,5,1,3,6};
    int pre[]={1,2,4,5,3,6};

    int n=sizeof(in)/sizeof(int);

    printPostorder(in,pre,n);

    return 0;
}
