
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
    // Function to return the diameter of a Binary Tree.
    pair<int,int> find(Node* root){
        if(!root) return {0,0};
        pair<int,int> left= find(root->left);
        pair<int,int> right=find(root->right);
        
        int lh=left.first;
        int rh=right.first;
        int ld=left.second;
        int rd=right.second;
        
        pair<int,int> ans;
        ans.first=1+max(lh,rh);
        ans.second=max(lh+rh,max(ld,rd));
        return ans;
        
    }
    int diameter(Node* root) {
        return find(root).second;
    }
};

