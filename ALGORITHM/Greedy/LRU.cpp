#include<bits/stdc++.h>
using namespace std;


int pageFaults(int n, int c, int pages[]){
        // code here
        map<int,int> m;

        int p = 0,i,count = 0;

        for(i=0;count<c && i<n;i++)
        {
            auto it = m.find(pages[i]);

            if( it == m.end())
            {
                count++,p++;
                m.insert({pages[i],i}); //insert
            }
            else
                it->second = i; //update


        }

        for(;i<n;i++)
        {
            auto pageItr = m.find(pages[i]);

            if( pageItr == m.end())
            {
                p++;

                auto itr = m.begin();

                for(auto it = m.begin();it!=m.end();it++)
                {
                    if(it->second < itr->second)
                        itr = it;   //least recently used unit
                }

                m.erase(itr);   //erase LRU

                m.insert({pages[i],i}); //insert new page;

            }

            else
                pageItr->second = i;    //update

        }

        return p;

    }

int main()
{
    int pages[] = {};
}
