#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

class Solution {
    public:
    
    int getCount(Node *root, int l, int h) {
        // your code here
        if(!root) return 0;
        if(root->data<l) return getCount(root->right,l,h);
        if(root->data>h) return getCount(root->left,l,h);
        return 1+getCount(root->left,l,h)+ getCount(root->right,l,h);
    }
  };
