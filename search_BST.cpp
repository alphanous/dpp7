#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Node{
    public:
    int data;
    Node *left, *right;
    Node (int val){
        data = val;
        left = right = NULL;
    }
};
bool search(Node* n, int x){
    if(n==NULL)
    {
        return false;
    }
    if(n->data==x)
    {
        return true;
    }

    bool left = search(n->left,x);
    if(!left){
        bool right = search(n->right,x);
        return right;
    }
    else{
        return left;
    }
}
int main()
{
    Node* n = new Node(60);
    n->left = new Node(30);
    n->right = new Node(90);
    n->left->left = new Node(10);
    n->left->right = new Node(40);
    n->right->left = new Node(70);
    n->right->right = new Node(100);
    int x; // node to be searched
    cin>>x;
    if(search(n,x)){
        cout<<"present"<<endl;
    }
    else{
        cout<<"not present"<<endl;
    }
    return 0;
}