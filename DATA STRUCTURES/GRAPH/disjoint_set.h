#include<bits/stdc++.h>
using namespace std;

class disjoint_set{

private:
    int* parent;
    int* rank;
    int n;

public:

    disjoint_set(int n)
    {
        this->n = n;

        parent = new int[n];

        rank = new int[n];

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findParent(int i)
    {
        if(parent[i] == i)
            return i;

        return parent[i] = findParent(parent[i]);
    }

    void make_union(int u,int v)
    {
        int pu = findParent(u);

        int pv = findParent(v);

        if(pu == pv)
            return;

        if(rank[pu] >= rank[pv])
        {
            rank[pu] += rank[pv];

            parent[pv] = pu;
        }

        else
        {
            rank[pv] += rank[pu];

            parent[pu] = pv;
        }
    }

    //return number of different sets
    int diff_sets()
    {
        int count = 0;

        for(int i=0;i<n;i++)
        {
            if(parent[i] == i)
                count++;
        }

        return count;
    }
};
