#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

vector<vector<int>> shortestDist(vector<vector<int>> g)
{
    int n = g.size();

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int newDist = (g[i][k] == INT_MAX || g[k][j] == INT_MAX) ? INT_MAX : g[i][k] + g[k][j];

                g[i][j] = min(g[i][j],newDist);
            }
        }
    }

    return g;
}

int main()
{
    vector<vector<int>> g = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    int n = g.size();

    vector<vector<int>> dist = shortestDist(g);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dist[i][j] == INT_MAX ? cout<<"INF " : cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
