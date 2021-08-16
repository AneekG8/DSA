#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int maxTime(int h,int a,int prev)
{
    if(h<=0 || a<=0)
        return -1;

    if(dp[h][a] != -1)
        return dp[h][a];

    int f = 0,s = 0,t = 0;

    if(prev != 1)
        f = 1+maxTime(h+3,a+2,1);

    if(prev != 2)
        s = 1+maxTime(h-5,a-10,2);

    if(prev != 3)
        t = 1+maxTime(h-20,a+5,3);

    return  dp[h][a] = max(f,max(s,t));
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int h,a;

		cin>>h>>a;

		memset(dp,-1,sizeof(dp));

		cout<<maxTime(h,a,-1)<<endl;
	}
	return 0;
}

