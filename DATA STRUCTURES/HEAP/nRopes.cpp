//given n ropes find the minimum cost of connecting them into one where
//cost of connecting two ropes is equal to sum of their length


#include<bits/stdc++.h>
using namespace std;


//!start with the minimum length ropes and add them to total cost

int minCost(int arr[],int n)
{
    int sum=0;
    priority_queue<int,vector<int>,greater<int>> p(arr,arr+n);

    while(p.size()>1)
    {
        int first=p.top();
        p.pop();

        int second=p.top();
        p.pop();

        sum+=first+second;

        p.push(first+second);   //!important
    }


    return sum;
}


int main()
{
    int len[] = { 4, 3, 2, 6 };
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is " << minCost(len, size);
    return 0;
}
