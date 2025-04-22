#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
    Node *next; 

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

class Solution {
    public:
      Node* prev=NULL;
      void inorder(Node* root){
          if(!root) return;
          inorder(root->left);
          if(prev) prev->next=root;
          prev=root;
          inorder(root->right);
      }
      void populateNext(Node *root) {
          inorder(root);
      }
  };
