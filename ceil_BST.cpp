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
int ceil(Node* n, int x){
    if(n==NULL){
        return -1;
    }
    
    int ans=0;
    while(n!=NULL){
        if(n->data==x){
            return n->data;
        }
        if(x<n->data){
            ans = n->data;
            n = n->left;
        }
        else if(x>n->data){
            n = n->right;
        }
    }
    return ans;
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
    int x; 
    cin>>x;
    cout<<ceil(n,x)<<endl;
    return 0;
}