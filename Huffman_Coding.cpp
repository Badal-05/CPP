#include<queue>
#include<iostream>
#include<string>

using namespace std;

struct Node{
    char letter;
    int freq;
    struct Node *left,*right;
    Node(char l,int f)
    {
        letter = l;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct compare{
    bool operator()(Node *left, Node *right){
        return left->freq > right->freq;
    }
};

void printcode(Node *root,string s)
{
    if(root != NULL)
    {
        if(root->letter!='*'){
            cout<<root->letter<<"-->"<<s<<endl;
        }
        printcode(root->left,s+"0");
        printcode(root->right,s+"1");
    }
}

void Huffman(char a[],int f[],int n){
    priority_queue<Node*,vector<Node*>,compare> pq;
    for(int i = 0 ; i < n; i++){
        pq.push(new Node(a[i],f[i]));
    }
    Node *lchild,*rchild;
    while(pq.size()!=1){
        lchild = pq.top();
        pq.pop();
        rchild = pq.top();
        pq.pop();
        Node *temp = new Node('*',lchild->freq+rchild->freq);
        temp->left = lchild;
        temp->right = rchild;
        pq.push(temp);
    }
    printcode(pq.top()," ");
}


int main(){
    char arr[] = {'a','b','c','d','e'};
    int freq[]={5,9,12,13,45};
    int n = 5;
    Huffman(arr,freq,n);
}