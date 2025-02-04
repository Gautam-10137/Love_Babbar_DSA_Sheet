
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    Node* prev=NULL;
    Node* head=NULL;
    void fn(Node* root){
        if(!root) return ;
        if(!root->left && !prev){
            head=root;
        }
        fn(root->left);
        if(prev) prev->right=root;   
        prev=root;
        fn(root->right);
    }
    Node* bToDLL(Node* root) {
        fn(root);
        Node* temp=head;
        while(temp && temp->right){
            temp->right->left=temp;
            temp=temp->right;
        }
        return head;
    }
};

