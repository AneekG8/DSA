//given a graph find a mother vertex if exists

#include<bits/stdc++.h>
using namespace std;


//GRAPH class

class graph{

list<int>* adj;
int vertex;

public:
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
            visited[x]=true;

            for(auto it=adj[x].begin();it!=adj[x].end();it++)
                if(!visited[*it])    DFS(*it,visited);
        }
    }

    void DFS(int start)
    {
        bool visited[vertex]={false};

        DFS(start,visited);

        cout<<endl;
    }

    int findMother()
    {
        bool visited[vertex]={false};

        int m_v=0;

        //possible mother vertex
        for(int i=0;i<vertex;i++)
        {
            if(!visited[i])
            {
                DFS(i,visited);
                m_v=i;
            }
        }

        //check if it is a mother vertex
        memset(visited,true,sizeof(visited));

        DFS(m_v,visited);

        for(int i=0;i<vertex;i++)
            if(!visited[i]) return -1;

        return m_v;
    }
};

int main()
{
    graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout << "A mother vertex is " << g.findMother();

    return 0;
}
