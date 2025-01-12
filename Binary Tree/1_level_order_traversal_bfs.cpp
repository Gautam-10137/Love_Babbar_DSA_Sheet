//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};



class Solution {
  public:
    // Function to return the level order traversal of a tree.
    vector<vector<int>> levelOrder(Node *root) {
       queue<Node*> q;
       q.push(root);
       vector<vector<int>> bfs;
       while(!q.empty()){
           int size=q.size();
           vector<int>level;
           while(size--){
               Node* front=q.front();
               q.pop();
               level.push_back(front->data);
               if(front->left) q.push(front->left);
               if(front->right) q.push(front->right);
           }
           bfs.push_back(level);
       }
       return bfs;
    }
};

