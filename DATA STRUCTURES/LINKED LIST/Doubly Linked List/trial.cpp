#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j;
	    cin>>n;
	    int arr[n][n];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    for(j=0;j<n;j++)
	    {
	        for(i=n-1;i>=0;i--)
	        {
	            cout<<arr[i][j]<<" ";
	        }
	    }
	}
	return 0;
}
