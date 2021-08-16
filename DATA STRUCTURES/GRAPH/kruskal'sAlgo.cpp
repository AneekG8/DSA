#include<bits/stdc++.h>
#include"disjoint_set.h"
using namespace std;

typedef pair<int,pair<int,int>> ppi;

/*class disjoint_set{

public:
    int* s;

    disjoint_set(int n)
    {
        s = new int[n];
        memset(s,-1,sizeof(s));
    }

    int findP(int i)
    {
        if(s[i] <= 0)
            return i;

        return s[i] = findP(s[i]);
    }

    void make_union(int u,int v)
    {
        int pu = findP(u);

        int pv = findP(v);

        if(pu == pv)
            return;

        if(s[pu] < s[pv])   //both negative as they are parents || lesser one has more members(higher rank)
        {
            s[pu] += s[pv];
            s[pv] = pu;  //pv is connected to pu
        }

        else
         {
            s[pv] += s[pu];
            s[pu] = pv;  //pu is connected to pv
         }
    }
};*/

/*void create_union(int u,int v,int set[])
{
    if(set[u]<set[v])
    {
        set[u]+=set[v];
        set[v]=u;
    }
    else
    {
        set[v]+=set[u];
        set[u]=v;
    }
}

int find(int u,int s[])
{
    int x=u;

    while(s[x]>0)
        x=s[x];

    return x;
}*/

void kruskals(vector<ppi> edges,int v)
{
    priority_queue<ppi,vector<ppi>,greater<ppi>> e(edges.begin(),edges.end());

    disjoint_set s(v+1);

    ppi res[v-1];   //cost,vertex,vertex

    for(int i=0;i<v-1;i++)
    {
        if(e.empty())
            break;

        ppi min_edge=e.top();
        e.pop();

        int v1=min_edge.second.first;
        int v2=min_edge.second.second;

        if(s.findParent(v2)!= s.findParent(v1))  //they don't make a cycle
        {
            res[i]=min_edge;

            s.make_union(v1,v2);
        }
        else i--;   //stay there
    }

    int total_cost=0;

    for(int i=0;i<v-1;i++)
    {
        total_cost+=res[i].first;

        cout<<"edge: "<<res[i].second.first<<"-->"<<res[i].second.second<<" || cost: "<<res[i].first<<endl;
    }

    cout<<"total cost: "<<total_cost<<endl;
}

int main()
{
    vector<ppi> edges;  //cost vertex vertex

    edges={{25,{1,2}},
           {5,{1,6}},
           {7,{2,3}},
           {6,{2,7}},
           {10,{3,4}},
           {12,{4,5}},
           {11,{4,7}},
           {18,{5,6}},
           {16,{5,7}}
          };

    kruskals(edges,7);

    return 0;
}
