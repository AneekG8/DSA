/*
Given a dictionary that contains mapping of employee and his manager as a number of (employee, manager) pairs like below.
{ "A", "C" },
{ "B", "C" },
{ "C", "F" },
{ "D", "E" },
{ "E", "F" },
{ "F", "F" }

In this example C is manager of A,
C is also manager of B, F is manager
of C and so on.

Write a function to get no of employees under each manager in the hierarchy not just their direct reports. It may be assumed that an employee directly reports to only one manager. In the above dictionary the root node/ceo is listed as reporting to himself.

Output should be a Dictionary that contains following.

A - 0
B - 0
C - 2
D - 0
E - 1
F - 5
*/

#include<bits/stdc++.h>
using namespace std;

//approach using reverse map
void getEmployees(unordered_map<string,string> m)
{
    unordered_map<string,vector<string>> rev_m;

    for(auto it=m.begin();it!=m.end();it++)
        rev_m[it->second].push_back(it->first);

    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<" --> "<<rev_m[it->first].size()<<endl;
}

int main()
{
    unordered_map<string,string> m;
    m["a"]="c";
    m["b"]="c";
    m["c"]="f";
    m["d"]="e";
    m["e"]="f";
    m["f"]="f";

    getEmployees(m);

    return 0;
}

