/*
Two pairs (a, b) and (c, d) are said to be symmetric if c is equal to b and a is equal to d.
For example, (10, 20) and (20, 10) are symmetric. Given an array of pairs find all symmetric pairs in it.
It may be assumed that the first elements of all pairs are distinct.
*/
#include<bits/stdc++.h>
using namespace std;


/*

A Simple Solution is to go through every pair, and check every other pair for symmetric. This solution requires O(n2) time.

A Better Solution is to use sorting.
Sort all pairs by the first element. For every pair, do a binary search for the second element in the given array, i.e.,
check if the second element of this pair exists as the first element in the array.
If found, then compare the first element of pair with the second element (as first element of each pair is distinct).
Time Complexity of this solution is O(nLogn).

An Efficient Solution is to use Hashing.
The first element of pair is used as key and the second element is used as the value.
The idea is to traverse all pairs one by one. For every pair, check if its second element is in the hash table.
If yes, then compare the first element with the value of the matched entry of the hash table.
If the value and the first element match, then we found symmetric pairs.
Else, insert the first element as a key and second element as value.

*/
typedef pair<int,int> pi;

void findSymPairs(vector<pi> v)
{
    unordered_map<int,int> m;

    for(int i=0;i<v.size();i++)
    {
        if(m.find(v[i].second)!= m.end() && m[v[i].second]==v[i].first)
            cout<<v[i].second<<","<<v[i].first<<endl;
        else
            m[v[i].first]=v[i].second;
    }
}

int main()
{
    vector<pi> v={{11, 20}, {30, 40}, {5, 10}, {40, 30}, {10, 5}};

    findSymPairs(v);

    return 0;
}
