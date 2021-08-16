#include "graph.h"

int minDist(vector<int> dist,bool selected[],int n)
{
    int currMin = INT_MAX,ind = -1;

    for(int i=0;i<n;i++)
    {
        if(!selected[i] && dist[i]<currMin)
            ind = i,currMin = dist[i];
    }

    return ind;
}

vector<int> djikstra(vector<vector<int>> g,int src)
{
    int v = g.size();

    bool selected[v] = {false};

    vector<int> dist(v);

    for(int i=0;i<v;i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for(int i=0;i<v;i++)
    {
        int vertex = minDist(dist,selected,v);

        if(vertex == -1)
            break;

        selected[vertex] = true;

        for(int j=0;j<v;j++)
        {
            if(!selected[j] && g[vertex][j] && g[vertex][j]+dist[vertex]<dist[j])
                dist[j] = g[vertex][j]+dist[vertex];
        }
    }

    return dist;
}

vector<int> dijkstraList(undirected_wgraph g,int src)
{
    vector<int> dist(g.vertex,INT_MAX);

    dist[src] = 0;

    set<pi> s;

    s.insert({0,src});

    while(!s.empty())
    {
        auto x = *(s.begin());

        s.erase(x);

        int curr_v = x.second;

        int curr_dist = x.first;

        auto curr_list = g.adj[curr_v];

        for(auto it = curr_list.begin(); it != curr_list.end(); it++)
        {
            if(curr_dist + it->second < dist[it->first])
                s.erase({dist[it->first],it->second}),dist[it->first] = curr_dist + it->second,s.insert({(curr_dist + it->second),it->first});
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> m = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    undirected_wgraph g(9);

    for(int i=0;i<m.size();i++)
    {
        for(int j=i;j<m.size();j++)
        {
            if(m[i][j])
                g.addEdge(i,j,m[i][j]);
        }
    }


    /*g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);
    g.addEdge(2,3,7);
    g.addEdge(2,5,4);
    g.addEdge(2,8,2);
    g.addEdge(2,1,4);
    g.addEdge(3,4,9);
    g.addEdge(3,5,14);
    g.addEdge(4,5,10);
    g.addEdge(5,6,2);
    g.addEdge(6,7,1);
    g.addEdge(6,8,6);
    g.addEdge(7,8,7);*/

    vector<int> dist = dijkstraList(g,0);

    for(int i=0;i<dist.size();i++)
        cout<<dist[i]<<" ";

    return 0;
}
