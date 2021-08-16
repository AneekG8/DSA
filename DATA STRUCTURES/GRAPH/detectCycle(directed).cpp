#include<bits/stdc++.h>
using namespace std;


//GRAPH class

class graph{

public:

    list<int>* adj;
    int vertex;

    graph(int v)
    {
        adj=new list<int>[v];
        vertex=v;
    }

    void addEdge(int v1,int v2)
    {
        adj[v1].push_back(v2);
    }

    void BFS(int start)
    {
        bool visited[vertex]={false};

        queue<int> q;

        q.push(start);

        while(!q.empty())
        {
            int x=q.front();

            q.pop();

            if(!visited[x])
            {
                cout<<x<<" ";

                visited[x]=true;

                for(auto it=adj[x].begin();it!=adj[x].end();it++)
                {
                    if(!visited[*it])   q.push(*it);
                }
            }
        }

        cout<<endl;
    }

    void DFS(int start,bool visited[])
    {
        int x=start;

        if(! visited[x])
        {
            cout<<x<<" ";

            visited[x]=true;

            for(auto it=adj[x].begin();it!=adj[x].end();it++)
                if(!visited[*it])    DFS(*it,visited);
        }
    }

    void DFS(int start)
    {
        bool visited[vertex]={false};

        for(int i=start,c=0;c<vertex;i=(i+1)%vertex,c++)
            if(!visited[i]) DFS(i,visited);

        cout<<endl;
    }

    void DFSitr(int start)
    {
        stack<int> s;

        s.push(start);

        bool visited[vertex]={false};

        while(!s.empty())
        {
            int x=s.top();
            s.pop();

            if(!visited[x])
            {
                cout<<x<<" ";

                visited[x]=true;

                for(auto itr=adj[x].begin();itr!=adj[x].end();itr++)
                    if(!visited[*itr]) s.push(*itr);
            }
        }

        cout<<endl;
    }
};

bool hasCycleUtil(int v,bool visited[],bool recStack[],graph G,vector<int>* cycle)
{
    if(!visited[v])
    {
        visited[v]=true;
        recStack[v]=true;

        for(auto it=G.adj[v].begin();it!=G.adj[v].end();it++)
        {
            if(!visited[*it] && hasCycleUtil(*it,visited,recStack,G,cycle))
            {
                cycle->push_back(*it);
                return true;
            }

            else if(recStack[*it])
            {
                cycle->push_back(*it);
                return true;
            }//back edge
        }
    }

    recStack[v]=false;
    return false;
}

bool hasCycle(graph G)
{
    vector<int> cycle;
    bool visited[G.vertex] = {false};

    bool recStack[G.vertex] = {false};

    for(int i=0;i<G.vertex;i++)
    {
        if(hasCycleUtil(i,visited,recStack,G,&cycle))
        {
            for(int i=0;i<cycle.size();i++)
                cout<<cycle[i]<<" --> ";

            cout<<cycle[0]<<endl;

            return true;
        }
    }

    return false;
}

int main()
{
    graph G(7);

    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(0,3);
    G.addEdge(4,0);
    G.addEdge(4,3);
    G.addEdge(3,6);
    G.addEdge(5,6);
    G.addEdge(6,4);

    cout<<hasCycle(G)<<endl;

    return 0;
}
