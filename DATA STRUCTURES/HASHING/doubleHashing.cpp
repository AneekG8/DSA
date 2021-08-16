#include<bits/stdc++.h>
using namespace std;

#define TABLE_SIZE 10
#define PRIME 7

class double_hash{

public:
    int* hashTable;
    int curr_size;
    int table_size;

    double_hash(int s)
    {
        hashTable=new int[s];
        curr_size=0;
        table_size=s;

        for(int i=0;i<table_size;i++)
            hashTable[i]=INT_MIN;
    }

    bool isfull()
    {
        return curr_size==table_size;
    }

    int hash1(int key)
    {
        return key%10;
    }

    int hash2(int key)
    {
        int prime=PRIME;
        return (prime-(key%prime));
    }

    int target_index(int key,int i)
    {
        return (hash1(key)+i*hash2(key))%table_size;
    }

    void insert(int key)
    {
        int i=0;

        //till there is collison
        while(hashTable[target_index(key,i)]!=INT_MIN)
            i++;

        hashTable[target_index(key,i)]=key;
    }

    void search(int key)
    {
        int i=0;

        //till there is collison
        while(hashTable[target_index(key,i)]!=key)
        {
            if(hashTable[target_index(key,i)]==INT_MIN)     //empty place
            {
                cout<<key<<" does not exist"<<endl;
                return;
            }
            i++;
        }

        cout<<key<<" found"<<endl;
    }

    void display()
    {
        for(int i=0;i<table_size;i++)
        {
            if(hashTable[i]==INT_MIN)
                cout<<i<<" --> "<<"-"<<endl;
            else
                cout<<i<<" --> "<<hashTable[i]<<endl;
        }
    }
};


int main()
{
    int a[] = { 19, 27, 36, 10, 64 };
    int n = sizeof(a) / sizeof(a[0]);

    // inserting keys into hash table
    double_hash h(TABLE_SIZE);
    for (int i = 0; i < n; i++) {
        h.insert(a[i]);
    }
    // searching some keys
    h.search(36); // This key is present in hash table
    h.search(100); // This key does not exist in hash table
    // display the hash Table
    h.display();
    return 0;
}
