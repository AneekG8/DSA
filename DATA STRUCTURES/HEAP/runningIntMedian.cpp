/*
Given that integers are being read from a data stream. Find the median of
all the elements read so far starting from the first integer till the last integer.
This is also called the Median of Running Integers.
The data stream can be any source of data, for example, a file, an array of integers, input stream etc.

What is Median?

Median can be defined as the element in the data set which separates
the higher half of the data sample from the lower half. In other words,
we can get the median element as, when the input size is odd, we take the middle element
of sorted data. If the input size is even, we pick an average of middle two elements in the sorted stream.
*/

#include<bits/stdc++.h>
#include<cmath>
using namespace std;

void runningIntMedian(double arr[],int n)
{
    priority_queue<double,vector<double>,greater<double>> g; //greater half
    priority_queue<double> s;  //smaller half

    s.push(arr[0]);

    double med=arr[0];

    cout<<med<<" ";

    for(int i=1;i<n;i++)
    {
        if(arr[i]>med)
            g.push(arr[i]);
        else
            s.push(arr[i]);

        //difference between size of two halves can't be > 1
        int diff=s.size()-g.size();
        if(abs(diff) > 1)
        {
            if(s.size()>g.size())
            {
                g.push(s.top());
                s.pop();
            }

            else
            {
                s.push(g.top());
                g.pop();
            }
        }

        if(s.size()>g.size())
        {
            med=(double)s.top();
            cout<<med<<" ";
        }

        else if(g.size()>s.size())
        {
            med=(double)g.top();
            cout<<med<<" ";
        }

        else
        {
            med=(s.top()+g.top())/2.0;
            cout<<med<<" ";
        }

    }
}


int main()
{
    double arr[] = {15,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    runningIntMedian(arr, n);
    return 0;
}
