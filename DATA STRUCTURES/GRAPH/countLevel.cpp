//given a tree represented in from of an undirected graph count nodes in a specified level

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

    int size(){return vertex;}

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

        DFS(start,visited);

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

    friend int countNodes(graph g,int level);
};

//use BFS
int countNodes(graph g,int l)
{
    queue<int> q;

    bool visited[g.size()]={false};

    vector<int> level;

    q.push(0);

    while(!q.empty())
    {
        int sz = q.size() , c = 0;

        for(int i=0;i<sz;i++)
        {
            int x = q.front();
            q.pop();

            if(!visited[x])
            {
                c++;

                for(auto it : g.adj[x])
                {
                    if(!visited[it])
                        q.push(it);
                }
            }
        }

        level.push_back(c);
    }

    return level[l];
}

int main()
{
    graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1,6);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    int level = 1;

    cout << countNodes(g,level);

    return 0;
}
