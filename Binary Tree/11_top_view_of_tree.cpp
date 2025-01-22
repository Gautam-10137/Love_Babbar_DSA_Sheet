
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
    map<int,pair<int,int>>mp;
    void fun(Node* root,int d,int level){
        if(!root) return;
        if(mp.find(d)==mp.end()) mp[d]={level,root->data};
        else{
            if(level<mp[d].first) {
                mp[d].second=root->data;
                mp[d].first=level; 
            }
        }
        
        fun(root->left,d-1,level+1);
        fun(root->right,d+1,level+1);
        
        return;
        
    }
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        fun(root,0,0);
        for(auto it:mp){
            ans.push_back(it.second.second);
        }
        return ans;
    }
};

