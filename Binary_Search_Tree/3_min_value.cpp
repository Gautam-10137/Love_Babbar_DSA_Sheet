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


int findMin(Node* root){
    if(!root) return INT_MAX;
    
    return min(root->data,min(findMin(root->left),findMin(root->right)));
}

int minValue(Node* root) {
    if(!root) return -1;
    return findMin(root);
}
