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
      void getNodes(Node* root,vector<int>&nodes){
        if(!root) return;
        getNodes(root->left,nodes);
        nodes.push_back(root->data);
        getNodes(root->right,nodes);
      }
      Node* balancedBST(vector<int> nodes,int s,int e){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        Node* root=new Node(nodes[mid]);
        root->left=balancedBST(nodes,s,mid-1);
        root->right=balancedBST(nodes,mid+1,e);
        return root;
      }
      Node* balanceBST(Node* root) {
        // Code here
        vector<int> nodes;
        getNodes(root,nodes);
        return balancedBST(nodes,0,nodes.size()-1);
        
      }
  };
