//Delete array elements which are smaller than next or become smaller

#include<iostream>
#include<stack>
using namespace std;

void showstack(stack <int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

void delArrElem(int *arr,int *n,int k)
{
    stack<int> s;
    s.push(arr[0]);
    int count=0;

    for(int i=1;i<*n;i++)
    {
        while(!s.empty() && s.top()<arr[i] && count<k)
        {
            s.pop();
            count++;
        }
        s.push(arr[i]);
    }

    delete arr;

    *n=s.size();
    arr=new int[*n];

    for(int i=*n-1;i>=0;i--)
    {
        arr[i]=s.top();
        s.pop();
    }
}
int main()
{
    int n=5;
    int* arr=new int[n];
    arr[0]=20;
    arr[1]=10;
    arr[2]=25;
    arr[3]=30;
    arr[4]=40;

    delArrElem(arr,&n,2);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}


