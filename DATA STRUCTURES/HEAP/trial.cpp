// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    priority_queue<int> mx;

    priority_queue<int,vector<int>,greater<int>> mn;

    double mid = INT_MIN;

    public:

    //Function to balance heaps.
    void balanceHeaps()
    {
        int diff = mx.size() - mn.size();

        if(abs(diff) > 1)
        {
            if(mx.size() > mn.size())
                mn.push(mx.top()),mx.pop();

            else if(mn.size() > mx.size())
                mx.push(mn.top()),mn.pop();
        }
    }

    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(x > mid)
            mn.push(x);

        else
            mx.push(x);

        balanceHeaps();
    }


    //Function to return Median.
    double getMedian()
    {
        if(!mx.size() && !mn.size())
            return mid;

        if(mx.size() > mn.size())
            return mid = (double)mx.top();

        else if(mn.size() > mx.size())
            return mid = (double)mn.top();

        return mid = ((double)(mx.top() + mn.top()))/2.0;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends
