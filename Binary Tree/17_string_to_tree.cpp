
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
 Node* fn(string str, int& i) {
    if (i >= str.size()) return NULL;

    // Extract root value
    int num = 0;
    if(!isdigit(str[i])) return NULL;
    while (i < str.size() && isdigit(str[i])) {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    
    Node* root = new Node(num);

    // Process left subtree
    if (i < str.size() && str[i] == '(') {
        i++; // Move past '('
        root->left = fn(str, i);
        i++; // Move past ')'
    }

    // Process right subtree
    if (i < str.size() && str[i] == '(') {
        i++; // Move past '('
        root->right = fn(str, i);
        i++; // Move past ')'
    }

    return root;
 } 

 Node* treeFromString(string str) {
    int i=0;
    return fn(str,i);
 }
};

