#include<bits/stdc++.h>
using namespace std;

vector<int> topoSortBfs(int v,vector<int> adj[])
{
    int indeg[v] = {0};

    //fill the in-degree array
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<adj[i].size();j++)
            indeg[adj[i][j]]++;
    }

    queue<int> q;

    for(int i=0;i<v;i++)
    {
        if(!indeg[i])
            q.push(i);
    }

    vector<int> res;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        res.push_back(x);

        for(int i=0;i<adj[x].size();i++)
        {
            indeg[adj[x][i]]--;

            if(!indeg[adj[x][i]])
                q.push(adj[x][i]);
        }
    }

    return res;
}


//DFS

void dfs(int s,bool visited[],stack<int>& stk,vector<int> adj[])
    {
        if(!visited[s])
        {
            visited[s] = true;

            for(int i=0;i<adj[s].size();i++)
                dfs(adj[s][i],visited,stk,adj);

            stk.push(s);
        }
    }

vector<int> topoSortDfs(int V, vector<int> adj[])
	{
	    // code here
	    bool visited[V] = {false};
	    vector<int> res;
	    stack<int> stk;

	    for(int i=0;i<V;i++)
	        dfs(i,visited,stk,adj);

	    /*int n = res.size();

	    for(int i=0;i<n;i++)
	        swap(res[i],res[n-i-1]);*/

        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }

	    return res;
	}
