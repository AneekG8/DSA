#include<bits/stdc++.h>
using namespace std;

class flight{

public:
    int arv,dep,fuel,urg;

    flight()
    {

    }

    flight(int a,int d,int f,int u)
    {
        arv = a;
        dep = d;
        fuel = f;
        urg = u;
    }
};

class comp{

public:
    bool operator()(const& a,const& b)
    {
        if(a.arv == b.arv)
        {
            if(a.dep == b.dep)
            {
                if(a.urg == b.urg)
                    return a.fuel > b.fuel;

                return a.urg > b.urg;
            }

            return a.dep > b.dep;
        }

        a.arv > b. arv;
    }
};
int main()
{
    int runways[10];

    flight arr[20];

    priority_queue<flight,vector<flight>,comp>> pq(arr,arr+20);

    while(!pq.empty())
    {
        flight f = pq.top();
        pq.pop();

        //search
        for(int i = 0;i<10;i++)

    }
}
