// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


void swap(int a,int b)
{
    int t = a;
    a=b;
    b=t;
}
class Solution
{
    private:
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
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
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
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";

        cout<<endl;

        cout << check(N, res, adj) << endl;
    }

    return 0;
}  // } Driver Code Ends
