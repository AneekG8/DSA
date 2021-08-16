#include<bits/stdc++.h>
using namespace std;

void func(string str,int start,int* count)
{
    if(str[start]=='\0')
        return;

    int diff;

    for(diff=start+1;str[diff]!='\0';diff++)
    {
        if(str[diff]!=str[start])
        {
            break;
        }
    }

    if(str[diff]=='\0')
    {
        (*count)++;
        return;
    }

    if(str[diff] > str[start])
    {
        for(int i=diff+1;str[i]!='\0';i++)
        {
            start=i;
            if(str[i]<str[i-1])
            {
                break;
            }
        }
    }
    else
    {
        for(int i=diff+1;str[i]!='\0';i++)
        {
            start=i;
            if(str[i]>str[i-1])
            {
                break;
            }
        }
    }

    (*count)++;

    func(str,start,count);
}
int main()
{
    string str;

    cin>>str;

    int count=0;

    func(str,0,&count);

    cout<<count;

    return 0;
}
