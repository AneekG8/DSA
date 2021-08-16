#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;

    int test_case = 1;

	while(T--)
	{
		int n,k,b,t;

		cin>>n>>k>>b>>t;

		int p[n],v[n];

		for(int i=0;i<n;i++)
            cin>>p[i];

		for(int i=0;i<n;i++)
            cin>>v[i];

        int impossible = 0,swaps = 0,c = 0;

        for(int i=n-1;i>=0;i--)
        {
            if(b-p[i] <= t*v[i])    //possible to reach
            {
                c++;
                swaps += impossible;
            }
            else
                impossible++;   //cannot reach

            if( c == k)
                break;
        }

        if(c < k)
            cout<<"Case #"<<test_case<<": IMPOSSIBLE"<<endl;
        else
            cout<<"Case #"<<test_case<<": "<<swaps<<endl;

        test_case++;
	}
	return 0;
}


