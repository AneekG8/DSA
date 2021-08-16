/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and
we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days
just before the given day, for which the price of the stock on the current day is less than or equal to
its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85},
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}


We see that S[i] on day i can be easily computed if we know the closest day preceding i,
such that the price is greater than on that day than the price on day i.
If such a day exists, let’s call it h(i), otherwise, we define h(i) = -1.
The span is now computed as S[i] = i – h(i).
*/
// C++ linear time solution for stock span problem
#include <iostream>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

// A stack based efficient method to calculate
// stock span values
void calculateSpan(int price[], int n, int S[])
{
	// Create a stack and push index of first
	// element to it
	stack<int> st;
	st.push(0);

	// Span value of first element is always 1
	S[0] = 1;

	// Calculate span values for rest of the elements
	for (int i = 1; i < n; i++) {
		// Pop elements from stack while stack is not
		// empty and top of stack is smaller than
		// price[i]
		while (!st.empty() && price[st.top()] <= price[i])
			st.pop();

		// If stack becomes empty, then price[i] is
		// greater than all elements on left of it,
		// i.e., price[0], price[1], ..price[i-1]. Else
		// price[i] is greater than elements after
		// top of stack
		S[i] = (st.empty()) ? (i + 1) : (i - st.top());

		// Push this element to stack
		st.push(i);
	}
}

// A utility function to print elements of array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

vector<int> calculateSpan(int arr[], int n)
    {
       // Your code here
       vector<int> res(n);

       stack<int> s;

       for(int i=n-1;i>=0;i--)
       {
            if(s.empty())
                s.push(i);

            else if(arr[i] <= arr[s.top()])
                s.push(i);

            else
            {
                while(arr[i] > arr[s.top()])
                {
                    res[s.top()] = s.top() - i;
                    s.pop();
                }

                s.push(i);
            }
       }

      while(!s.empty())
      {
          res[s.top()] = s.top() +1;
          s.pop();
      }

       return res;
    }
// Driver program to test above function
int main()
{
	int price[] = { 10, 4, 5, 90, 120, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	int S[n];

	// Fill the span values in array S[]
	vector<int> res = calculateSpan(price, n);

	// print the calculated span values
	for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";

	return 0;
}
