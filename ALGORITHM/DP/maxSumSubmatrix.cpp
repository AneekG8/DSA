//maximum sum sub matrix from a 2D matrix

#include<bits/stdc++.h>
using namespace std;

void maxSum(vector<vector<int>> m)
{
    int rows = m.size();
    int cols = m[0].size();

    int maxSum = INT_MIN,maxLeft,maxRight,maxUp,maxDown;

    int arr[rows];

    for(int l=0;l<cols;l++)
    {
        memset(arr,0,sizeof(arr));

        for(int r=l;r<cols;r++)
        {
            //populate arr
            for(int i=0;i<rows;i++)
                arr[i] += m[i][r];

            //if all entries are negative run two loops to find the largest

            //find max sum using kadane's algo
            int currSum = 0,start = 0,end = -1;

            for(int i=0;i<rows;i++)
            {
                currSum += arr[i],end++;

                if(maxSum < currSum)
                {
                    maxSum = currSum;
                    maxLeft = l;
                    maxRight = r;
                    maxUp = start;
                    maxDown = end;
                }

                if(currSum < 0)
                    currSum=0,start = end+1;
            }

        }
    }

    cout<<"maximum sum is: "<<maxSum<<endl;

    for(int i=maxUp;i<=maxDown;i++)
    {
        for(int j=maxLeft;j<=maxRight;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> m = {{5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}};

    maxSum(m);

}
