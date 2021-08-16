#include<stdio.h>
// Driver code 
int main() 
{ 
    long int t;
    scanf("%ld",&t);
    while(t--){
        long long int n;
        scanf("%lld",&n);
        long long int arr[n],i=0,j=0,p=1,count=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        while(i < n)
        {
        	//printf("%lld %lld",i,j);
            p*=arr[j];
            if(p%4==0)
            {
                count+=n-j;
                j=n-1;
            }
            else if(p%4!=2)
            {
                count++;
            }
            j++;
            if(j==n && i<n)
            {
                i++;
                j=i;
                p=1;
            }
        }
        printf("%lld\n",count);
    }
	return 0; 
}
