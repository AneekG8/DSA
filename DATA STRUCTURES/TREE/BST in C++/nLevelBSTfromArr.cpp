//check that if a BST with n  level can be created from an array of n size

#include<iostream>
using namespace std;

//array method

bool checkNLevelBST(int arr[],int n)
{
    int min=INT_MIN;

    int max=INT_MAX;

    for(int i=1;i<n;i++)
    {
        //insert at right
        if(arr[i]>arr[i-1] && arr[i]>min && arr[i]<max)
            min=arr[i-1];

        //insert at left
        else if(arr[i]<arr[i-1] && arr[i]>min && arr[i]<max)
            max=arr[i-1];

        else return false;
    }

    return true;
}

//what else we could have done is that
//create a n level tree
//check if its a  binary tree or not

int main()
{
    int arr[]={500, 200, 90, 250, 100};

    int n=sizeof(arr)/sizeof(n);

    checkNLevelBST(arr,n) ? cout<<"YES" : cout<<"NO"<<endl;

    return 0;
}
