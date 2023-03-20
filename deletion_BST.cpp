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
void inorder(Node* n)
{
    if(n==NULL)
    {
        return;
    }
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}
Node* delete_Node(Node* root, int x){
    if(root == NULL){
        return NULL;
    }
    if(x<root->data){
        root->left = delete_Node(root->left,x);
    }
    else if(x>root->data)
    {
        root->right = delete_Node(root->right,x);
    }
    else{
        if(root-> left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp = root->right;
            while(temp->left!=NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_Node(root->right,temp->data);
            return root;
        }
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
    int x; // node to be deleted
    cin>>x;
    inorder(n);
    cout<<endl;
    delete_Node(n,x);
    inorder(n);
    return 0;
}
