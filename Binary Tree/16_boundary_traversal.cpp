
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
   vector<int> leftB,leafB,rightB;
    void fillLeftB(Node* root){
        if(!root || (!root->left && !root->right)) return;
        leftB.push_back(root->data);
        if(root->left)fillLeftB(root->left);
        else fillLeftB(root->right);
        return;
    }
    void fillRightB(Node* root){
        if(!root || (!root->left && !root->right)) return;
        if(root->right)fillRightB(root->right);
        else fillRightB(root->left);
        rightB.push_back(root->data);
        return;
    }
    void fillLeafB(Node* root){
        if(!root) return;
        if(!root->left && !root->right) leafB.push_back(root->data);
        fillLeafB(root->left);
        fillLeafB(root->right);
        return;
    }
   
    vector<int> boundaryTraversal(Node *root) {
        fillLeftB(root->left);
        fillRightB(root->right);
        fillLeafB(root->left);
        fillLeafB(root->right);
        vector<int>ans;
        ans.push_back(root->data);
        for(int it:leftB) ans.push_back(it);
        for(int it:leafB) ans.push_back(it);
        for(int it:rightB) ans.push_back(it);
        return ans;
    }
};

