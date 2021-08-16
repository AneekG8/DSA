//check for balanced parentheses in a string
#include<iostream>
#include<stack>
using namespace std;

bool check(string str)
{
    stack<char> s;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
           s.push(str[i]);
        else
        {
            switch(str[i])
            {
            case ')':
                if( s.empty() || s.top()!='(') return false;
                s.pop();
                break;
            case '}':
                if(s.empty() || s.top()!='{') return false;
                s.pop();
                break;
            case ']':
                if(s.empty() || s.top()!='[') return false;
                s.pop();
                break;
            }
        }
    }
    if(!s.empty()) return false;
    return true;
}

int main()
{
    string str;
    cin>>str;

    check(str) ? cout<<"balanced"<<endl : cout<<"not balanced"<<endl;

    return 0;
}
