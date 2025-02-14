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


// Function to search a node in BST.
bool search(Node* root, int x) {
    if(!root) return false;
    if(root->data==x) return true;
    if(root->data<x) return search(root->right,x);
    return search(root->left,x);
}
