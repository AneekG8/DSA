#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

vector<pi> allShortestPaths(vector<int> adj[],int v,int src)
{
    vector<pi> dist(v,{INT_MAX,-1});

    dist[src] = {0,-1};

    queue<int> q;

    q.push(src);

    while(!q.empty())
    {
        int i = q.front();
        q.pop();

        for(auto j : adj[i])
        {
            if(dist[i].first + 1 < dist[j].first)
            {
                dist[j].first = dist[i].first + 1;
                dist[j].second = i;

                q.push(j);
            }
        }
    }

    return dist;
}

void shortestPath(vector<int> adj[],int v,int src,int target)
{
    vector<pi> dist = allShortestPaths(adj,v,src);

    if(dist[target].first == INT_MAX)
        cout<<"Not Reachable"<<endl;

    else
    {
        while(target != -1)
        {
            cout<<target<<" <-- ";
            target = dist[target].second;
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> adj[] = {{1,3},{1,2,3},{1,6},{0,4},{3,5},{4,6},{2,5,7},{6},{6,7}};

    shortestPath(adj,9,1+++++++++++++++++++++++++++++++++++,3);
}
