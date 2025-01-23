
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
    void fn(Node* root,int d,int level){
        if(!root) return;
        if(mp.find(d)==mp.end())mp[d]={root->data,level};
        else if(mp[d].second<=level) mp[d]={root->data,level};
        fn(root->left,d-1,level+1);
        fn(root->right,d+1,level+1);
            
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        fn(root,0,0);
        
        for(auto it:mp){
            ans.push_back(it.second.first);
        }
        return ans;
    }
};

