
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
        auto left=fn(root->left);
        auto right=fn(root->right);
        int lh=left.second;
        int rh=right.second;
        int lb=left.first;
        int rb=right.first;
        
        if(!lb || !rb || abs(lh-rh)>1) return {false,max(lh,rh)+1};
        return {true,max(lh,rh)+1};
    }
    bool isBalanced(Node* root) {
        bool ans=fn(root).first;
        return ans;
    }
};

