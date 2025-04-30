#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node* LCA(Node* root, Node* n1, Node* n2) {
    if(!root) return NULL;
    
    if(root->data==n1->data || root->data==n2->data) return root;
    if(root->data<n1->data && root->data<n2->data) return LCA(root->right,n1,n2);
    if(root->data>n1->data && root->data>n2->data) return LCA(root->left,n1,n2);
    
    return root;
    
}
