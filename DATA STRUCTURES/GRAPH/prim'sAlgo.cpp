#include<bits/stdc++.h>
using namespace std;

#define I INT_MAX

void prims(int cost[8][8],int v) //v=number of vertex
{
    int near[]={I,I,I,I,I,I,I,I};

    int edges[2][v-1] {0};

    //find the minimum cost edge
    int min=I,v1,v2;

    for(int i=1;i<=v;i++)
    {
        for(int j=i;j<=v;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                v1=i;
                v2=j;
            }
        }
    }

    //store the first minimum cost edge
    edges[0][0]=v1;
    edges[1][0]=v2;

    //mark them as already taken
    near[v1]=0;
    near[v2]=0;

    //update the nearest vertices from v1 and v2
    for(int i=1;i<=v;i++)
    {
        if(near[i])
        {
            if(cost[i][v1]<cost[i][v2])
                near[i]=v1;
            else
                near[i]=v2;
        }
    }

    //repeat the process to find the other edges
    for(int i=1;i<v-1;i++)
    {
        int new_v;  //next vertex taken

        min=I;

        //find the minimum cost edge with either of v1 and v2
        for(int j=1;j<=v;j++)
        {
            if(near[j] && cost[j][near[j]] < min)
            {
                min=cost[j][near[j]];
                new_v=j;
            }
        }

        //store the edge
        edges[0][i]=new_v;
        edges[1][i]=near[new_v];

        //mark the new vertex as taken
        near[new_v]=0;

        //update the near array(check if any remaining vertex is nearest from new vertex)
        for(int j=1;j<=v;j++)
        {
            if(near[j] && cost[j][new_v]<cost[j][near[j]])
                near[j]=new_v;
        }
    }

    for(int j=0;j<v-1;j++)
    {
        cout<<"edge: "<<edges[0][j]<<"-->"<<edges[1][j]<<" || cost: "<<cost[edges[0][j]][edges[1][j]]<<endl;
    }
}

int main()
{
    int cost[8][8]={ {I, I, I, I, I, I, I, I},
                    {I, I, 25, I, I, I, 5, I},
                    {I, 25, I, 12, I, I, I, 10},
                    {I, I, 12, I, 8, I, I, I},
                    {I, I, I, 8, I, 16, I, 14},
                    {I, I, I, I, 16, I, 20, 18},
                    {I, 5, I, I, I, 20, I, I},
                    {I, I, 10, I, 14, 18, I, I},
                  };

    prims(cost,7);

    return 0;
}
