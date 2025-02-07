
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
    pair<bool,int> fn(Node* root){
        if(!root) return {true,0};
        if(!root->right && !root->left) return {true,root->data};
        auto left=fn(root->left);
        auto right=fn(root->right);
        int sum=left.second+right.second;
        if(root->data!=sum || !left.first || !right.first) return {false,sum+root->data};
        return {true,root->data+sum};
    }
    bool isSumTree(Node* root) {
        bool ans=fn(root).first;
        return ans;
    }
};

