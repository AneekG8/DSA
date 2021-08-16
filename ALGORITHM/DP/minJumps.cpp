#include<bits/stdc++.h>

using namespace std;

int minJumpsRecur(int arr[],int n)
{
    if(arr[0] == 0)
        return -1;

    if(n==1)
        return 0;

    int res = INT_MAX;

    for(int i=0;i<n-1;i++)
    {
        if(i+arr[i] >= n-1)
        {
            //int jumps = minJumpsRecur(arr,i);
            //if()
            res = min(res,1+minJumpsRecur(arr,i+1));
        }
    }

    return res;
}

int minJumpsDP(int arr[],int n)
    {
        int jumps[n],jump_from[n];

        if(arr[0] == 0)
            return -1;

        jumps[0] = 0;
        jump_from[0] = 0;

        for(int i=1;i<n;i++)
        {
            jumps[i] = INT_MAX;
            jump_from[i] = -1;

            for(int j=0;j<i;j++)
            {
                if(j+arr[j] >= i)
                {
                    if(1+jumps[j] < jumps[i])
                    {
                        jumps[i] = 1+jumps[j];
                        jump_from[i] = j;
                    }
                }
            }
        }

        return jumps[n-1] == INT_MAX ? -1 : jumps[n-1];
    }

int minJumpsLinear(int arr[],int n)
{
    if(n <= 1)
        return 0;

    if(arr[0] == 0)
        return -1;

    int max_reach = arr[0];

    int steps_available = arr[0];

    int jumps = 1;

    for(int level=1;level<n;level++)
    {
        if(level == n-1)
            return jumps;

        if(level + arr[level] > max_reach)
            max_reach = level+arr[level];

        steps_available--;

        if(steps_available == 0)
        {

            jumps++;

            steps_available = max_reach-level;

            if(steps_available == 0)
                return -1;
        }
    }

    return -1;
}

    int main()
    {

        int arr[]={2,3,1,1,2,4,2,0,1,1};

        cout<<minJumpsLinear(arr,10);
    }
