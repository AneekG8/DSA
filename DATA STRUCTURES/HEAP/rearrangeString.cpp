/*
Given a string with repeated characters,
the task is to rearrange characters in a string so that no two adjacent characters are same.
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<char,int> pi;

class customComp{

public:
    bool operator()(pi a,pi b)
    {
        return a.second<b.second;
    }
};
void rearrangeString(string str)
{
    unordered_map<char,int> count;

    for(int i=0;str[i]!='\0';i++)
        count[str[i]]++;

    priority_queue<pi,vector<pi>,customComp> pq(count.begin(),count.end());

    pi pre={'#',-1};

    string res;

    while(!pq.empty())
    {
        pi x=pq.top();
        pq.pop();

        res=res+x.first;

        x.second--; //freq decreases

        if(pre.second>0)
            pq.push(pre);

        pre=x;
    }

    if(res.length()==str.length())
        cout<<res<<endl;
    else
        cout<<"not possible"<<endl;
}

int main()
{
    string str = "aaabc" ;
    rearrangeString(str);
    return 0;
}
