//

#include<bits/stdc++.h>
using namespace std;

class huffmanTreeNode{

public:
    char data;
    int freq;
    huffmanTreeNode *left,*right;

    huffmanTreeNode()
    {

    }

    huffmanTreeNode(char data,int freq)
    {
        this->data = data;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }

    huffmanTreeNode(char data,int freq,huffmanTreeNode* left,huffmanTreeNode* right)
    {
        this->data = data;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

class cmp{

public:
    bool operator()(huffmanTreeNode* a,huffmanTreeNode* b)
    {
        return a->freq > b->freq;
    }
};


//returns root of the huffman tree
huffmanTreeNode* buildHuffmanTree(string data,int freq[],int n)
{
    priority_queue<huffmanTreeNode*,vector<huffmanTreeNode*>,cmp> pq;

    for(int i=0;i<n;i++)
    {
        pq.push(new huffmanTreeNode(data[i],freq[i]));
    }

    huffmanTreeNode* top;

    while(pq.size() != 1)
    {
        huffmanTreeNode* leftChild = pq.top();  //first min
        pq.pop();

        huffmanTreeNode* rightChild = pq.top();  //second min
        pq.pop();

        top = new huffmanTreeNode('$',leftChild->freq + rightChild->freq,leftChild,rightChild);   //internal node

        pq.push(top);
    }

    return top;
}

void printHuffmanCodesUtil(huffmanTreeNode* root,string str)
{
    if(!root)
        return;

    if(root->data != '$')
        cout<<root->data<<" : "<<str<<endl;

    printHuffmanCodesUtil(root->left,str + "0");

    printHuffmanCodesUtil(root->right,str + "1");
}

void printHuffmanCodes(string data,int freq[],int n)
{
    huffmanTreeNode* root = buildHuffmanTree(data,freq,n);
    return printHuffmanCodesUtil(root,"");
}

int main()
{
    string data = "abcdef";
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = data.size();

    printHuffmanCodes(data, freq, size);

    return 0;
}

