//merge k number of sorted arrays of different size

#include<bits/stdc++.h>
using namespace std;

class info{

public:
    int val;    //element from an array
    int i;      //index **of** the array    v[i]
    int j;      //index of the element **in** that array   v[i][j]

    bool operator>(const info& a)const
    {
        return this->val>a.val;
    }
};
//instead of custom class we could have used pair<int,pair<int,int>>

vector<int> mergeKsorted(vector<vector<int>> v)
{
    vector<int> res;

    priority_queue<info,vector<info>,greater<info>> pq;

    //store index and first element of each array from v
    for(int i=0;i<v.size();i++)
        if(v[i].size())
            pq.push({v[i][0],i,0});

    while(!pq.empty())
    {
        info x=pq.top();

        res.push_back(x.val);

        pq.pop();

        //till the last element of that particular array
        if(x.j<v[x.i].size()-1)
            pq.push({v[x.i][x.j+1],x.i,(x.j+1)});
    }

    return res;
}


int main()
{
    vector<vector<int> > arr{ { 2, 6, 12 },
                              {  },
                              { 23, 34, 90, 2000 } };

    vector<int> output = mergeKsorted(arr);

    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";

    return 0;
}
