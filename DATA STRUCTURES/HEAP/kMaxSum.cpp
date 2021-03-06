/*Instead of brute forcing through all the possible sum combinations we should find a way to limit
 our search space to possible candidate sum combinations.
1. Sort both arrays array A and array B.

2. Create a max heap i.e priority_queue in C++ to store the sum combinations along with the
indices of elements from both arrays A and B which make up the sum. Heap is ordered by the sum.

3. Initialize the heap with the maximum possible sum combination i.e (A[N ? 1] + B[N ? 1]
where N is the size of array) and with the indices of elements from both arrays (N ? 1, N ? 1).
The tuple inside max heap will be (A[N-1] + B[N ? 1], N ? 1, N ? 1). Heap is ordered by first value i.e sum of both elements.

4. Pop the heap to get the current largest sum and along with the indices of the element that make up the sum.
Let the tuple be (sum, i, j).
4.1. Next insert (A[i ? 1] + B[j], i ? 1, j) and (A[i] + B[j ? 1], i, j ? 1)
into the max heap but make sure that the pair of indices i.e (i ? 1, j) and (i, j ? 1) are not
already present in the max heap. To check this we can use set in C++.
4.2 Go back to 4 until K times.
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> ppi;

typedef pair<int,int> pi;

void kMaxSum(int* a,int *b,int n,int k)
{
    sort(a,a+n);
    sort(b,b+n);

    priority_queue<ppi> pq;

    set<pi> s;

    pq.push({a[n-1]+b[n-1],{n-1,n-1}});

    s.insert({n-1,n-1});

    for(int c=0;c<k;c++)
    {
        cout<<pq.top().first<<endl;

        int i=pq.top().second.first;
        int j=pq.top().second.second;

        pq.pop();

        if(s.find({i-1,j})==s.end() &&i>0)
        {
            pq.push({a[i-1]+b[j],{i-1,j}});
            s.insert({i-1,j});
        }


        if(s.find({i,j-1})==s.end()&& j>0)
        {
            pq.push({a[i]+b[j-1],{i,j-1}});
            s.insert({i,j-1});
        }
    }
}

int main()
{
    int a[]={1,4,2,3};
    int b[]={2,5,1,6};

    int n=sizeof(a)/sizeof(int);

    int k=16;

    kMaxSum(a,b,n,k);

    return 0;
}
