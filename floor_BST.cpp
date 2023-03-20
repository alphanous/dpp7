#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
int floor(Node* root, int x)
{
    if(root==NULL)
    {
        return 0;
    }
    int res=0;
    while(root!=NULL){
        if(root->data==x){
            return root->data;
        }

        if(x<root->data)
        {
            root = root->left;
        }
        else if(x>root->data)
        {
            res = root->data;
            root = root->right;
        }
    }
    return res;
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
    cout<<floor(n,x)<<endl;
    return 0;
}