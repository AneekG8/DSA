//find the connected components in a graph

#include"graph.h"
#include"disjoint_set.h"
using namespace std;

void get_componentUtil(undirected_graph g,int start,bool visited[],vector<int>& component)    //get the nodes in a component from a starting vertex
{
    if(!visited[start])
    {
        visited[start] = true;

        component.push_back(start);

        for(auto it : g.adj[start])
        {
            get_componentUtil(g,it,visited,component);
        }
    }
}

vector<int> get_component(undirected_graph g,int start,bool visited[])
{
    vector<int> component;

    get_componentUtil(g,start,visited,component);

    return component;
}

//gets all the components
vector<vector<int>> get_components(undirected_graph g)
{
    bool visited[g.vertex];

    vector<vector<int>> components;

    for(int i=0;i<g.vertex;i++)
    {
        if(!visited[i])
            components.push_back(get_component(g,i,visited));
    }

    return components;
}

int main()
{
    undirected_graph g(6);

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,5);

    vector<vector<int>> components = get_components(g);

    cout<<"total number of components: "<<components.size()<<endl;

    for(int i=0;i<components.size();i++)
    {
        for(int j=0;j<components[i].size();j++)
            cout<<components[i][j]<<" ";

        cout<<endl;
    }

    disjoint_set s(g.vertex);

    for(int i=0;i<g.vertex;i++)
    {
        for(auto it : g.adj[i])
        {
            s.make_union(i,it);
        }
    }

    cout<<"components: "<<s.diff_sets();

}
