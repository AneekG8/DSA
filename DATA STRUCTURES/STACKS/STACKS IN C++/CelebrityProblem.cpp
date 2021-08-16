/*
The Celebrity Problem
In a party of N people, only one person is known to everyone. Such a person may be present in the party,
if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “.
Find the stranger (celebrity) in the minimum number of questions.

We can describe the problem input as an array of numbers/characters representing persons in the party.
We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise.

Algorithm:
Create a stack and push all the id’s in the stack.
Run a loop while there are more than 1 element in the stack.
Pop top two element from the stack (represent them as A and B)
Check if A knows B, then A can’t be a celebrity and push B in stack.
Check if A doesn’t know B, then B can’t be a celebrity push A in stack
Assign the remaining element in the stack as the celebrity
Run a loop from 0 to n-1 and find the count of persons who knows the celebrity
and the number of people whom the celebrity knows. if the count of persons who knows the celebrity
is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.
*/

#include<iostream>
#include<stack>
#define N 8
using namespace std;

bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};

bool MATRIX1[N][N]={ {0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 1, 0, 0},
                     {0, 0, 1, 0} };
bool knows(int a,int b)
{
    return MATRIX[a][b];
}

int findCelebrity(int n)
{
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        s.push(i);      //candidates
    }

    int A=s.top();
    s.pop();

    int B=s.top();
    s.pop();

    while(s.size()>1)
    {
        if(knows(A,B))
        {
            A=s.top();      //A can't be candidate so change A
            s.pop();
        }
        else
        {
            B=s.top();      //B can't be candidate so change B
            s.pop();
        }
    }

    //loop ends and we are left with 3 candidates
    int C=s.top();  //last candidate
    s.pop();

    if(knows(C,B))
        C=B;
    if(knows(C,A))
        C=A;

    //now possible candidate is C
    for(int i=0;i<n;i++)
    {
        if((C!=i) &&  (knows(C,i) || !knows(i,C)))
            return -1;
    }

    return C;
}

//by elimination process
int findCeleb(int n)
{
    // code here
        stack<int> s;

        for(int i=0;i<n;i++)
            s.push(i);

        while(s.size() > 1)
        {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            // if(!M[a][b] && M[b][a])
            //     s.push(a);

            // else if(!M[b][a] && M[a][b])
            //     s.push(b);

            if(knows(a,b))
                s.push(b);

            else
                s.push(a);
        }

        // if(s.empty())
        //     return -1;

        int c = s.top();    //check for the potential candidate

        for(int i=0;i<n;i++)
        {
            if(i == c)
                continue;

            if(!knows(i,c) || knows(c,i))
                return -1;
        }

        return c;

}
int main()
{
    int n = 4;
    int id = findCeleb(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}
