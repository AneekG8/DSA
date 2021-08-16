#include<bits/stdc++.h>
using namespace std;

//smallest number from given sum and number of digits

string smallestNumber(int s,int d)
{
    if(s > 9*d)
        return "-1";

    if(d == 1)
        return to_string(s);

    string str(d,'a');

    int i=d-1;

    for(;i>=1;i--)
    {
        s--;

        str[i] = s>9 ? '9' : '0'+s;

        s -= s>9 ? 9 : s;

        s++;
    }

    str[0] = '0' + s;

    return str;
}
int main()
{
    cout<<smallestNumber(20,3);
}

