//merge k number of sorted arrays

#include<iostream>
#include<queue>
#include<vector>
#define COLS 4
using namespace std;

class info{

public:
    int val;
    int index;
    int* arr;

    bool operator>(const info& a)const
    {
        return this->val>a.val;
    }
};


vector<int> mergeKsorted(int arr[][COLS],int n,int k)
{
    vector<int> res;

    priority_queue<info,vector<info>,greater<info>> pq;

    for(int i=0;i<k;i++)
        pq.push({arr[i][0],0,*(arr+i)});

    while(!pq.empty())
    {
        info x=pq.top();

        res.push_back(x.val);

        pq.pop();

        if(x.index<n-1)
        {
            pq.push({*(x.arr+1),(x.index+1),(x.arr+1)});
        }
    }

    return res;
}


int main()
{
     int arr[][COLS] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);

    vector<int> v=mergeKsorted(arr,COLS,k);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";


    return 0;
}
