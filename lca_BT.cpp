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
int lca(Node* root, int n1, int n2)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data == n1 || root->data == n2)
    {
        return root->data;
    }

    int left_lca = lca(root->left,n1,n2);
    int right_lca = lca(root->right,n1,n2);

    if(left_lca!=-1 && right_lca!=-1)
    {
        return root->data;
    }
    if(left_lca!=-1 && right_lca==-1)
    {
        return left_lca;
    }
    if(left_lca==-1 && right_lca!=-1)
    {
        return right_lca;
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
    int n1,n2;
    cin>>n1>>n2;
    cout<<lca(n,n1,n2);
    return 0;
}