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


Node* deleteNode(Node* root, int key) {
    if(!root) return root;
    if(root->data==key){
        if(!root->left && !root->right) return NULL;
        if(root->left && !root->right) return root->left;
        if(!root->left && root->right) return root->right;
        Node* temp=root->right;
        while(temp->left){
            temp=temp->left;
        }
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
        return root;
    }
    else if(key<root->data){
       root->left=deleteNode(root->left,key);
    }
    else root->right=deleteNode(root->right,key);
    return root;
}
