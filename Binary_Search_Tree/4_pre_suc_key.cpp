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

Node* first=NULL;
Node* second=NULL;

void findPre(Node* root,int key){
    if(!root) return;
    findPre(root->left,key);
    if(root->data<key){
        first=root;
    } 
    findPre(root->right,key);
    return;
}
void findSuc(Node* root,int key){
    if(!root) return;
    findSuc(root->right,key);
    if(root->data>key){
        second=root;
    } 
    findSuc(root->left,key);
    return;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    findPre(root,key);
    findSuc(root,key);
    pre=first;
    suc=second;
    return;  
}
