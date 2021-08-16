#include"graph.h"

bool hasCycle(undirected_graph g,int start,bool visited[],int parent)
{
    if(!visited[start])
    {
        visited[start] = true;

        for(auto it=g.adj[start].begin();it!=g.adj[start].end();it++)
        {
            if(!visited[*it])
            {
                if(hasCycle(g,*it,visited,start))
                    return true;
            }
            else if(*it != parent)
                return true;
        }
    }

    return false;
}

bool hasCycle(undirected_graph g)
{
    bool visited[g.vertex] = {false};

    for(int i=0;i<g.vertex;i++)
    {
        if(!visited[i] && hasCycle(g,i,visited,-1))
            return true;
    }

    return false;
}
int main()
{
    undirected_graph g(6);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(3,5);
    //g.addEdge(4,4);
    //g.addEdge(4,5);

    cout<<hasCycle(g);

    return 0;
}
