/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit if and only if the job is completed by its deadline.
The task is to find the number of jobs done and the maximum profit.
*/

// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

// https://www.geeksforgeeks.org/job-sequencing-problem/    (2 solutions)
#include<bits/stdc++.h>
using namespace std;

class Job
{
public:
    char id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class disjoint_set{

private:
    int* parent;    

public:
    disjoint_set(int n)
    {
        parent = new int[n];

        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int find(int i)     //greatest availabe slot for a deadline (i)
    {
        if(parent[i] == i)
            return i;

        return parent[i] = find(parent[i]);
    }

    void make_union(int u,int v)
    {
        parent[v] = u;  //join slot and slot-1
    }
};

bool cmp(Job a,Job b)
{
    return a.profit > b.profit;
}


//GREEDY O(n2)
void jobScheduling(Job arr[],int n)
{
    int profit = 0,c = 0;
    char jobs[n];
    bool slots[n];

    memset(slots,false,sizeof(slots));

    sort(arr,arr+n,cmp);

    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].dead)-1;j>=0;j--)
        {
            //greatest available slot
            if(!slots[j])
            {
                slots[j] = true;
                jobs[j] = arr[i].id;
                profit += arr[i].profit;
                c++;
                break;
            }
        }
    }

    cout<<"maximum profit: "<<profit<<" with jobs: "<<c<<endl;

    cout<<"order of jobs: ";
    for(int i=0;i<n;i++)
    {
        if(slots[i])
            cout<<jobs[i]<<" ";
    }
}


//GREEDY SOLUTION O(nlogn) using DISJOINT SET
void jobScheduling1(Job arr[],int n)
{
    sort(arr,arr+n,cmp);

    int max_deadline = 0,profit = 0,j = 0;

    for(int i=0;i<n;i++)
        max_deadline = max(max_deadline,arr[i].dead);

    disjoint_set s(max_deadline+1);

    cout<<"order of jobs: "<<" ";

    for(int i=0;i<n;i++)
    {
        int slot = s.find(arr[i].dead);

        if(slot > 0)    //feasible
        {
            cout<<arr[i].id<<" ";

            profit += arr[i].profit;

            j++;

            s.make_union(slot-1,slot);
        }
    }

    cout<<endl<<"maximum profit: "<<profit<<" with jobs: "<<j<<endl;
}



int main ()
{
    Job arr[] =  { { 'a', 2, 100 }, { 'b', 1, 19 },
                   { 'c', 2, 27 },  { 'd', 1, 25 },
                   { 'e', 3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);

    jobScheduling1(arr,n);

    cout << "Following jobs need to be "
         << "executed for maximum profit\n";
    
    jobScheduling(arr,n);

    return 0;
}
