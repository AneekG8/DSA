#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int min = n/2;

    if(n%2)
        min++;

    int max = n-2;

    int c = 0;

    for(int i=min;i<=max;i++)
        c += n-i-1;

    c *= 3;

    cout<<c;
}
