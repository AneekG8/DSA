//given f(x) which is monotonically increasing find the first value of x for which f(x) is +ve

#include<iostream>
using namespace std;

//required binary search function
int binarySearch(int l,int r);

//f(x)
int f(int x){return (x*x - 10*x - 20);}

//first we find a x(say high) for which f(x) is positive by doubling the window
int findFirstPositive()
{
    if(f(0)>0)
        return 0;

    int high=1;

    while(f(high)<=0)
        high=high*2;

    return binarySearch(high/2,high);
}

//once we have got high we are sure that desired value of x lies between high/2 and high
int binarySearch(int l,int r)
{
    if(r>=l)
    {
        int mid=(l+r)/2;

        if(mid<=0)  //if mid is <=0 x lies to the right
            return binarySearch(mid+1,r);

        if(f(mid)>0 && (mid==l || f(mid-1)<=0)) //only time mid is the desired value
            return mid;

        return binarySearch(l,mid-1);   //mid is positive but there's at least one more +ve to the right
    }

    return -1;
}

int main()
{
    cout<<"The value n where f() becomes" <<
        "positive first is "<< findFirstPositive();
    return 0;
}
