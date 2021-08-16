#include <iostream>
using namespace std;

typedef long long int lli;

int main() {
	// your code goes here
	int t;
	cin>>t;

	while(t--)
	{
	    lli n,k,x,y,resX,resY;

	    cin>>n>>k>>x>>y;

	    if(x==y)
	        resX = n,resY = n;

	    else
	    {
	        lli a;

	        a = x-y > 0 ? x-y : y-x;

	        if(y<x)
	        {
	            switch(k%4)
	            {
	                case 0:
	                    resX = a,resY = 0;
	                    break;

	                case 1:
	                    resX = n,resY = n-a;
	                    break;

	                case 2:
	                    resX = n-a,resY = n;
	                    break;

	                case 3:
	                    resX = 0,resY = a;
	                    break;
	            }
	        }

	        else
	        {
	            switch(k%4)
	            {
	                case 0:
	                    resX = 0,resY = a;
	                    break;

	                case 1:
	                    resX = n-a,resY = n;
	                    break;

	                case 2:
	                    resX = n,resY = n-a;
	                    break;

	                case 3:
	                    resX = a,resY = 0;
	                    break;
	            }
	        }
	    }

	    cout<<resX<<" "<<resY<<endl;
	}
	return 0;
}
