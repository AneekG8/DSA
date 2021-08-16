#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int x)
{
    if(x==2)    return true;

    if(x==1|| x%2==0)
        return false;

    for(int i=3;i<=sqrt(x) && i<x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

vector<int> prime_at_prime(vector<int> v)
{
    vector<int> result;

    for(int i=1;i<v.size();i++)
    {
        if(checkPrime(i) && checkPrime(v[i]))
            result.push_back(v[i]);
    }

    return result;
}
int main()
{
    vector<int> v={0,3,5,2,4,8};

    vector<int> res=prime_at_prime(v);

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";

    return 0;
}
