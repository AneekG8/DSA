#include<bits/stdc++.h>
using namespace std;

void DFSutil(int G[][8],int n,int start,int visited[])
{
    if(!visited[start])
    {
        cout<<start<<" ";

        visited[start]=1;

        for(int i=1;i<n;i++)
        {
            if(G[start][i] && !visited[i])
                DFSutil(G,n,i,visited);
        }
    }
}


void DFS(int G[][8],int n,int start)
{
    int visited[n]={0};

    DFSutil(G,n,start,visited);
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

    DFS(G,8,5);

    return 0;
}

