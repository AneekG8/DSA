#include"graph.h"

bool isBipartiteUtil(undirected_graph g,int i,int col[],int curr)
{
    if(col[i] != -1 && col[i] != curr)
        return false;

    if(col[i] == curr)
        return true;

    bool res = true;

    col[i] = curr;

    for(auto it: g.adj[i])
        res = res && isBipartiteUtil(g,it,col,!curr);

    return res;
}

bool isBipartite(undirected_graph g)
{
    int col[g.vertex];

    memset(col,-1,sizeof(col));

    bool res = true;

    for(int i=0;i<g.vertex;i++)
    {
        if(col[i] == -1)
            res = res && isBipartiteUtil(g,i,col,0);
    }

    return res;
}

int main()
{
    undirected_graph g(7);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(4,5);
    g.addEdge(6,5);
    //g.addEdge(4,6);

    cout<<isBipartite(g);
}

