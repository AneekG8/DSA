//find the largest area rectangle in a matrix with sum zero


#include<bits/stdc++.h>
using namespace std;

void largestArea(vector<vector<int>> m)
{
    int rows = m.size();
    int cols = m[0].size();

    int maxArea = 0,maxLeft,maxRight,maxUp,maxDown;

    int arr[rows];

    for(int l=0;l<cols;l++)
    {
        memset(arr,0,sizeof(arr));

        for(int r=l;r<cols;r++)
        {
            //populate arr
            for(int i=0;i<rows;i++)
                arr[i] += m[i][r];

            int prefixSum[rows];
            unordered_map<int,int> m;

            prefixSum[0] = arr[0],m[0] = -1;

            for(int i=1;i<rows;i++)
                prefixSum[i] = arr[i]+prefixSum[i-1];

            int currArea = 0;

            for(int i=0;i<rows;i++)
            {
                if(m.find(prefixSum[i]) == m.end())
                    m[prefixSum[i]] = i;
                else
                {
                    int start = m.find(prefixSum[i])->second+1;
                    int end = i;

                    currArea = (end-start+1) * (r-l+1);

                    if(maxArea < currArea)
                    {
                        maxArea = currArea;
                        maxLeft = l;
                        maxRight = r;
                        maxUp = start;
                        maxDown = end;
                    }
                }
            }

        }
    }

    cout<<"maximum Area is: "<<maxArea<<endl;

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
    vector<vector<int>> m = { { 9, 7, 16, 5 }, { 1, -6, -7, 3 },
                      { 1, 8, 7, 9 }, { 7, -2, 0, 10 } };;

    largestArea(m);

}
