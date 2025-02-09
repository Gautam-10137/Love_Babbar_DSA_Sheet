
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
    bool fn(Node* root,int level,int &maxLevel){
        if(!root) return true;
        if(!root->left && !root->right){
            if(maxLevel==0) maxLevel=level;
            else if(maxLevel!=level) return false;
        }
        return fn(root->left,level+1,maxLevel) && fn(root->right,level+1,maxLevel);
    }
    bool check(Node *root) {
        int maxLevel=0;
        return fn(root,0,maxLevel);
    }
};

