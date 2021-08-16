#include<bits/stdc++.h>
using namespace std;

class Job
{
public:
    char id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
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
void jobScheduling1()
{

}



int main ()
{
    Job arr[] =  { { 'a', 2, 100 }, { 'b', 1, 19 },
                   { 'c', 2, 27 },  { 'd', 1, 25 },
                   { 'e', 3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following jobs need to be "
         << "executed for maximum profit\n";
    jobScheduling(arr,n);
    return 0;
}
