//Given a string str, we need to print reverse of individual words
#include<iostream>
#include<stack>
using namespace std;

void reverseIndWords(string& str)
{
    stack<char> s;
    int j=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!=' ')
            s.push(str[i]);
        else
        {
          while(!s.empty())
          {
              str[j]=s.top();
              s.pop();
              j++;
          }
          str[j]=' ';
          j++;
        }
    }

    while(!s.empty())
        {
            str[j]=s.top();
            s.pop();
            j++;
        }

}

int main()
{
    string str="geeks for geeks";
    reverseIndWords(str);
    cout<<str;
    return 0;
}
