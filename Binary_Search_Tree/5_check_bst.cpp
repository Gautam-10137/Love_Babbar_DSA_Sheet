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

pair<bool,pair<int,int>> fn(Node* root){
    if(!root) return {true,{INT_MAX,INT_MIN}};
    auto left=fn(root->left);
    auto right=fn(root->right);
    if(!left.first || !right.first || root->data<=left.second.second 
    || root->data>=right.second.first)
       return {false,{0,0}};
    int minVal = min(root->data, left.second.first);
    int maxVal = max(root->data, right.second.second);

    return {true, {minVal, maxVal}};
}

bool isBST(Node* root) {
    auto result=fn(root);
    return result.first;
}
