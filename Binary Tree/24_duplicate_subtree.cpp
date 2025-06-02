
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
    unordered_map<string,int> mp;
    bool isPresent=false;
    string isSubTreePresent(Node* root){
        if (!root) return "";

    // Leaf node — do not include in map
    if (!root->left && !root->right) {
        return to_string(root->data)+','+',';
    }

    string left = isSubTreePresent(root->left);
    string right = isSubTreePresent(root->right);
    string subtree = to_string(root->data) + "," + left + "," + right;

    mp[subtree]++;
    if (mp[subtree] == 2) {
        isPresent = true;
    }

    return subtree;
    }
    
    int dupSub(Node *root) {
        mp.clear(); // clear global map for safe repeated calls
    isPresent = false;
    isSubTreePresent(root);
    return isPresent ? 1 : 0;
    }
};

