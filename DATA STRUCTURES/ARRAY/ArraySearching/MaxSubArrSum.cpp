#include<bits/stdc++.h>
using namespace std;
int findmaxsum(int *a,int *b,int n,int m)
{
	int i,curr_max=INT_MIN,max_so_far=INT_MIN;
	for(i=0;i<n;i++)
	{
		if(binary_search(b,b+m,a[i]))
		{
			curr_max=-100;
			continue;
		}
		else
		{
			curr_max=max(a[i],(curr_max+a[i]));
		}
		max_so_far=max(max_so_far,curr_max);
	}
	return max_so_far;
}
void get_max_sum(int a[],int b[],int n,int m)
{
	sort(b,b+m);
	int maxSum=findmaxsum(a,b,n,m);
	if(maxSum==INT_MIN)
	{
		cout<<"no possible max sum"<<endl;
	}
	else
	{
		cout<<"max sum is "<<maxSum<<endl;
	}
}
int main() 
{ 
    int A[] = { -8,-1,-5,-9}; 
    int B[] = { 2, 8, 7 }; 
  
    int n = sizeof(A) / sizeof(A[0]); 
    int m = sizeof(B) / sizeof(B[0]); 
  
    // Calling fucntion 
    get_max_sum(A, B, n, m); 
    return 0; 
}
