//array representation of a tree

//!important
//if i is the parent node then left child is at 2*i+1 and right child should be at 2*i+2

#include<iostream>
#include<vector>

using namespace std;

class Tree{

public:
    vector<int> v;

    void createTree()
    {
        int x;

        cout<<"enter root element:"<<endl;

        cin>>x;

        v.push_back(x);

        int i;

        for(i=0;i<v.size();i++)
        {
            if(v[i] != -1)
            {
                //get left child
                cout<<"enter left child of "<<v[i]<<endl;
                cin>>x;
                v.push_back(x);

                //get right child
                cout<<"enter right child of "<<v[i]<<endl;
                cin>>x;
                v.push_back(x);
            }
            else
                continue;
        }
    }

    void display()
    {
        int i;

        for(i=0;i<v.size();i++)
        {
            if(v[i]==-1)
                cout<<"- ";
            else
                cout<<v[i]<<" ";
        }

        cout<<endl;
    }

    void inorder(int i)
    {
        if(v[i] == -1)
            return;

        inorder(2*i + 1);

        cout<<v[i]<<" ";

        inorder(2*i + 2);
    }

    void inorder()
    {
        inorder(0);
    }

};

int main()
{
    Tree t;

    t.createTree();

    t.display();

    t.inorder();

    return 0;
}
