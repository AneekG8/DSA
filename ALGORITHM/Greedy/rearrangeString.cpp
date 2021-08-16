#include<bits/stdc++.h>
using namespace std;

//rearrange a string such that no adjacent letters are same
class Key{

public:
    char ch;
    int freq;

    bool operator<(const Key& a) const
    {
        return freq < a.freq;
    }
};

string rearrange(string str)
{
    int n= str.size();

    priority_queue<Key> pq;

    unordered_map<char,int> m;

    for(int i=0;i<n;i++)
    {
        if(m.find(str[i]) == m.end())
            m[str[i]] = 1;

        else
            m[str[i]]++;
    }

    for(auto it=m.begin();it!=m.end();it++)
        pq.push({it->first,it->second});

    int i = 0;

    Key prev = {'$',-1};

    string res = "";

    while(!pq.empty())
    {
        Key curr_top = pq.top();
        pq.pop();

        res += curr_top.ch;
        i++;

        if(prev.ch != '$' && prev.freq > 0)
            pq.push(prev);

        prev = {curr_top.ch,curr_top.freq-1};
    }

    if(res.size() < n)
        return "not possible";
    else
        return res;

}

int main()
{
    cout<<rearrange("geeksforgeeks");
}
