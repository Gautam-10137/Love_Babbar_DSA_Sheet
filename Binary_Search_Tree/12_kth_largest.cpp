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
    void fn(Node* root,int& idx,int k,int& ans){
        if(!root) return;
        
        fn(root->right,idx,k,ans);
        idx++;
        if(idx==k){
            ans=root->data;
            return;
        }
        fn(root->left,idx,k,ans);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans=0;
        int idx=0;
        fn(root,idx,k,ans);
        return ans;
    }
  };
