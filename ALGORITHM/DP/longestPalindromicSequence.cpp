#include<bits/stdc++.h>

using namespace std;

int lps(string str,int l,int r)
{
    if(l>r)
        return 0;

    if(l == r)
        return 1;

    if(str[l] == str[r])
        return 2+lps(str,l+1,r-1);

    return max(lps(str,l,r-1),lps(str,l+1,r));
}

int main()
{
    string str = "BBABCBCAB";
    int n = str.size();
    cout << "The length of the LPS is "
         << lps(str, 0, n-1);
    return 0;
}

