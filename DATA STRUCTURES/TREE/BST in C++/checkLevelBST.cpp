//check if an array can represent level order traversal of a BST

//for this we need to maintain record of the data and corresponding interval of each node

#include<iostream>
#include<queue>
using namespace std;

class NodeDetails{
public:
    int data;
    int min;
    int max;

    NodeDetails(int data,int min,int max)
    {
        this->data=data;
        this->min=min;
        this->max=max;
    }
};


bool checkLevelBST(int arr[],int n)
{
    queue<NodeDetails> q;
    int i=0;

    q.push(NodeDetails(arr[0],INT_MIN,INT_MAX));

    while(!q.empty() && i<n)
    {
        NodeDetails temp=q.front();
        q.pop();

        //for left child
        if(arr[i+1]>temp.min && arr[i+1]<temp.data)
            q.push(NodeDetails(arr[++i],temp.min,temp.data));

        //for right child
        if(arr[i+1]>temp.data && arr[i+1]<temp.max)
            q.push(NodeDetails(arr[++i],temp.data,temp.max));
    }

    //if the whole array is traversed
    if(i==n)
        return true;

    return false;
}

int main()
{
    int arr[]={7,4,12,3,1,10};

    int n=sizeof(arr)/sizeof(int);

    checkLevelBST(arr,n) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    return 0;
}
