#include<bits/stdc++.h>
using namespace std;

void BFS(int G[][8],int n,int start)
{
    queue<int> q;

    int visited[n]={0};

    q.push(start);

    while(!q.empty())
    {
        int x=q.front();

        q.pop();

        if(!visited[x])
        {
            cout<<x<<" ";
            visited[x]=1;

            for(int i=1;i<n;i++)
            {
                if(!visited[i] && G[x][i])
                    q.push(i);
            }
        }
    }

}

int main()
{
    int G[][8]={
                {0,0,0,0,0,0,0,0},
                {0,0,1,0,1,0,0,0},
                {0,1,0,1,0,0,0,0},
                {0,0,1,0,1,0,0,0},
                {0,1,0,1,0,1,0,0},
                {0,0,0,1,1,0,1,1},
                {0,0,0,0,0,1,0,0},
                {0,0,0,0,0,1,0,0}
               };

    BFS(G,8,7);

    return 0;
}
