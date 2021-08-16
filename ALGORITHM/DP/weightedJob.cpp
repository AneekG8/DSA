#include<bits/stdc++.h>
using namespace std;

class Job{
public:
    int start,finish,profit;
};

bool jobComp(Job a,Job b)
{
    return a.start < b.start;
}

bool jobComp1(Job a,Job b)
{
    return a.finish < b.finish;
}

int maxProfitHelp(Job arr[],int n,int start,int finish)
{
    if(n == 0)
        return 0;

    if(arr[n-1].finish<=start)
        return max(arr[n-1].profit+maxProfitHelp(arr,n-1,arr[n-1].start,arr[n-1].finish),maxProfitHelp(arr,n-1,start,finish));

    return maxProfitHelp(arr,n-1,start,finish);
}

int latestNonConflict(Job arr[],int i)
{
    for(int j=i-1;j>=0;j--)
    {
        if(arr[j].finish<=arr[i].start)
            return j;
    }

    return -1;
}
int maxProfitRecur(Job arr[],int n)
{
    if(n == 1)
        return arr[n-1].profit;

    int inc = arr[n-1].profit;

    int l = latestNonConflict(arr,n-1);

    if(l != -1)
        inc += maxProfitRecur(arr,l+1);

    int exc = maxProfitRecur(arr,n-1);

    return max(inc,exc);
}

int maxProfitDP(Job arr[],int n)
{
    int table[n+1];

    table[1] = arr[0].profit;

    for(int i=2;i<=n;i++)
    {
        int inc = arr[i-1].profit;

        int l = latestNonConflict(arr,i-1);

        if(l != -1)
            inc += table[l+1];

        int exc = table[i-1];

        table[i] = max(inc,exc);
    }

    return table[n];
}

int maxProfit(Job arr[],int n)
{
    sort(arr,arr+n,jobComp1);
    return maxProfitDP(arr,n);
}

int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << maxProfit(arr, n);
    return 0;
}
