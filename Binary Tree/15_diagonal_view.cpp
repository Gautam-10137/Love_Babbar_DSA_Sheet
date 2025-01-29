
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
    map<int,vector<int>>mp;
    
    void fn(Node *root,int level){
        if(!root) return;
        mp[level].push_back(root->data);    
        fn(root->left,level+1);
        fn(root->right,level);
        return;
    }
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        fn(root,0);
        for(auto it:mp){
            for(auto val:it.second){
                ans.push_back(val);
            }    
        }
        return ans;
    }
};

