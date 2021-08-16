//given two linked lists create two linked lists representing union and intersection of former two

#include<bits/stdc++.h>
using namespace std;

//!method

//create a hash map which stores occurrences of each node in both lists

//for union create a list with all nodes in map

//for union create lists with nodes having 2 occurrences

//!if lists are allowed to have duplicates then instead of mapping keys(nodes) with occurrences
//!map them to their corresponding lists. if they appear in both the lists then intersection

//time O(m + n)

void getUnionIntersection(list<int> a,list<int> b,list<int>* u,list<int>* i)
{
    unordered_map<int,pair<bool,bool>> m;   //two bbol flags mark appearances of nodes in corresponding lists

    for(auto itr=a.begin();itr!=a.end();itr++)
        m[*itr]={true,false};

    for(auto itr=b.begin();itr!=b.end();itr++)
    {
        if(m.find(*itr)==m.end())
            m[*itr]={false,true};

        else
            m[*itr]={true,true};
    }

    for(auto itr=m.begin();itr!=m.end();itr++)
    {
        u->push_back(itr->first);

        if(m[itr->first].first && m[itr->first].second)
            i->push_back(itr->first);
    }
}


//!other methods

//1)use brute force O(m*n)

//2)merge sort both linked lists O(nlogn)
//then  use sorted algorithm for union and intersection

//time O(mlogm + nlogn)



int main()
{
    list<int> a,b;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(4);

    b.push_back(1);
    b.push_back(3);
    b.push_back(5);
    b.push_back(6);
    b.push_back(4);

    list<int> u,i;

    getUnionIntersection(a,b,&u,&i);

    for(auto itr=u.begin();itr!=u.end();itr++)
        cout<<*itr<<" ";

    cout<<endl;

    for(auto itr=i.begin();itr!=i.end();itr++)
        cout<<*itr<<" ";

    return 0;
}
