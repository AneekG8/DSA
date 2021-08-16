//given three arrays check if {a,b,c} exists such that a+b+c=sum(given) and they are from different arrays

#include<bits/stdc++.h>
using namespace std;

//!brute force O(n^3)



//!we can always reduce time complexity to O(n^2) using hashing

//we store elements of array 1 in a hash map

//now we take pairs from remaining 2 arrays [O(n^2)] and check if sum-sum(pair) exists [O(1)] in the hash map or not

typedef vector<int> v;
void findTripletSum(v a,v b,v c,int sum)
{
    unordered_set<int> m;

    for(int i=0;i<a.size();i++)
        m.insert(a[i]);

    for(int i=0;i<b.size()-1;i++)
    {
        for(int j=i+1;j<c.size();j++)
        {
            if( m.find(sum-b[i]-c[j]) != m.end() )
                cout<<sum-b[i]-c[j]<<"+"<<b[i]<<"+"<<c[j]<<"="<<sum<<endl<<endl;
        }
    }
}

int main()
{
    v a1 = { 1 , 2 , 3 , 4 , 5 };
    v a2 = { 2 , 3 , 6 , 1 , 2 };
    v a3 = { 3 , 2 , 4 , 5 , 6 };
    int sum = 9;
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);
    int n3 = sizeof(a3) / sizeof(a3[0]);
    findTripletSum(a1, a2, a3, sum);


    return 0;
}
