#include<bits/stdc++.h>
using namespace std;

int derangements(int n)
{
    if(n<=0)
        return 0;

    if(n <= 2)
        return n-1;

    return (n-1)*(derangements(n-1)+derangements(n-2));
}

int der(int n)
{

    if(n<=0)
        return 0;

    if(n <= 2)
        return n-1;

    int a = 0,b = 1,res;

    for(int i=3;i<=n;i++)
    {
        res = (i-1)*(a+b);
        a=b;
        b=res;
    }

    return res;

}

int main()
{
    cout<<der(4);
}
