// https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1#

//page faults in LRU in O(n * c)    n = no. of pages || c = capacity of cache
#include<bits/stdc++.h>
using namespace std;

int pageFaults(int n, int c, int pages[])
{
    // code here
    unordered_map<int,int> m;   //page,timestamp
    
    int pf = 0 , t = 0;
    
    for(int i=0;i<n;i++)
    {
        int p = pages[i];
        
        if(m.find(p) != m.end())
        {
            m[p] = ++t;
        }
        
        else
        {
            pf++;
            
            if(m.size() == c)
            {
                int lru = -1,minT = INT_MAX;
                for(auto it : m)
                {
                    if(it.second < minT)
                    {
                        lru = it.first;
                        minT = it.second;
                    }
                }
                
                if(lru != -1)
                    m.erase(lru);
            }
            
            m[p] = ++t;
        }
    }
    
    return pf;
}

int main()
{
    int pages[] = {5, 0, 1, 3, 2, 4, 1, 0, 5};

    cout<<pageFaults(9,4,pages);

    return 0;
}
