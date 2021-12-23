// https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1

#include<bits/stdc++.h>

using namespace std;


string smallestString(string str)
{
    int n = str.size();

    int arr[26];

    memset(arr,-1,sizeof(arr));

    //store first occurences
    for(int i=0;i<n;i++)
    {
        if(arr[str[i]-'a'] == -1)
            arr[str[i]-'a'] = i;
    }

    bool flag = false;
    char f,s = 'z' + 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<str[i]-'a';j++)
        {
            if(arr[j] > arr[str[i]-'a'])
            {
                flag = true;
                f = str[i];
                s = 'a'+j;
                break;
            }
        }

        if(flag)
            break;
    }

    if(flag)
    {
        for(int i=0;i<n;i++)
        {
            if(str[i] == f)
                str[i] = s;

            else if(str[i] == s)
                str[i] = f;
        }
    }

    return str;
}

int main()
{
    cout<<smallestString("ccad");
    return 0;
}
