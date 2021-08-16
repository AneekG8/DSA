#include<bits/stdc++.h>
using namespace std;


//GRAPH class

class directed_graph{

public:
    list<int>* adj;
    int vertex;

    directed_graph(int v)
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

        for(int i=start,c=0;c<vertex;i=(i+1)%vertex,c++)    //this loop is used in case we want to reach the nodes which are unreachable from starting vertex
            if(!visited[i]) DFS(i,visited);

        cout<<endl;
    }

    void DFSitr(int start)
    {
        bool visited[vertex] = {false};

        for(int i=start,c=0;c<vertex;i=(i+1)%vertex,c++)    //this loop is used in case we want to reach the nodes which are unreachable from starting vertex
        {
            if(!visited[i])
            {
                stack<int> s;

                s.push(i);

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
            }
        }

        cout<<endl;
    }
};

class undirected_graph{

public:

    list<int>* adj;
    int vertex;

    undirected_graph(int v)
    {
        adj=new list<int>[v];
        vertex=v;
    }

    void addEdge(int v1,int v2)
    {
        adj[v1].push_back(v2);

        if(v1 != v2)
            adj[v2].push_back(v1);
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

        for(int i=start,c=0;c<vertex;i=(i+1)%vertex,c++)    //this loop is used in case we want to reach the nodes which are unreachable from starting vertex
            if(!visited[i]) DFS(i,visited);

        cout<<endl;
    }

    void DFSitr(int start)
    {
        bool visited[vertex] = {false};

        for(int i=start,c=0;c<vertex;i=(i+1)%vertex,c++)    //this loop is used in case we want to reach the nodes which are unreachable from starting vertex
        {
            if(!visited[i])
            {
                stack<int> s;

                s.push(i);

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
            }
        }

        cout<<endl;
    }
};

typedef pair<int,int> pi;

class directed_wgraph{

public:
    list<pi>* adj;
    int vertex;

    directed_wgraph(int v)
    {
        adj=new list<pi>[v];
        vertex=v;
    }

    void addEdge(int v1,int v2,int w)
    {
        adj[v1].push_back({v2,w});
    }

};

class undirected_wgraph{

public:

    list<pi>* adj;
    int vertex;

    undirected_wgraph(int v)
    {
        adj=new list<pi>[v];
        vertex=v;
    }

    void addEdge(int v1,int v2,int w)
    {
        adj[v1].push_back({v2,w});

        if(v1 != v2)
            adj[v2].push_back({v1,w});
    }
};
