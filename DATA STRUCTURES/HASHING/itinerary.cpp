/*
Given a list of tickets, find itinerary in order using the given list.

Example:

Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output:
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
It may be assumed that the input list of tickets is not cyclic and there is one ticket from every city except final destination.

*/

#include<bits/stdc++.h>
using namespace std;


//!approach

//we have to find the starting point
//now if we have to data sets(from and to) then starting point must not be in the to data set

void findItinerary(map<string,string> dataSet)
{
    //we create a reverse map for to-->from data set
    map<string,string> rev_dataSet;

    for(auto it=dataSet.begin();it!=dataSet.end();it++)
        rev_dataSet[it->second]=it->first;

    //now a key which is present in dataSet but not in the reverse one would be starting point
    map<string,string>::iterator itr;

    for(itr=dataSet.begin();itr!=dataSet.end();itr++)
        if(rev_dataSet.find(itr->first)==rev_dataSet.end()) break;

    while(itr!=dataSet.end())
    {
        cout<<itr->first<<" --> "<<itr->second<<" ";

        itr=dataSet.find(itr->second);
    }
}

int main()
{
    map<string, string> dataSet;
    dataSet["Chennai"] = "Banglore";
    dataSet["Bombay"] = "Delhi";
    dataSet["Goa"] = "Chennai";
    dataSet["Delhi"] = "Goa";

    findItinerary(dataSet);

    return 0;
}
