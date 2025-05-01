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

class Solution {
    public:
      // The given root is the root of the Binary Tree
      // Return the root of the generated BST
      void getAllNodes(Node* root,vector<int>& store){
          if(!root) return;
          store.push_back(root->data);
          getAllNodes(root->left,store);
          getAllNodes(root->right,store);
      }
      void convertToBST(Node* root,vector<int>sortedNodes,int &idx){
          if(!root) return;
          convertToBST(root->left,sortedNodes,idx);
          root->data=sortedNodes[idx];
          idx=idx+1;
          convertToBST(root->right,sortedNodes,idx);
      }
      Node *binaryTreeToBST(Node *root) {
          // Your code goes here
          if(!root) return NULL;
          vector<int> allNodes;
          getAllNodes(root,allNodes);
          sort(allNodes.begin(),allNodes.end());
          int idx=0;
          convertToBST(root,allNodes,idx);
          return root;
          
      }
  };
