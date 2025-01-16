
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
    Node* invertTree(Node* root) {
        if(!root || (!root->left && !root->right)) return root;

        auto left=invertTree(root->left);
        auto right=invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
};
