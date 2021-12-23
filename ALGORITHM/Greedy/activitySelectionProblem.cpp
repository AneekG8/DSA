/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i])
where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room
when only one meeting can be held in the meeting room at a particular time?
Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/

// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class meeting{
    public:
        int start,end;
};

bool cmp(meeting a,meeting b)
{
    return a.end < b.end;
}
int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        meeting m[n];

        for(int i=0;i<n;i++)
        {
            m[i].start = s[i];
            m[i].end = e[i];
        }

        sort(m,m+n,cmp);

        int result = 0,last = INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(m[i].start > last)
                result++,last = m[i].end;
        }

        return result;
    }

int main()
{
    int S[] = {1,3,0,5,8,5};
    int F[] = {2,4,6,7,9,9};

    int n = sizeof(S)/sizeof(int);

    cout<<maxMeetings(S,F,n);

    return 0;
}
