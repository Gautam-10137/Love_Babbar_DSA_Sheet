
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
    int fn(Node* root){
        if(!root) return 0;
        
        int leftS=fn(root->left);
        int rightS=fn(root->right);
        
        int sum=root->data;
        root->data=leftS+rightS;
        sum+=leftS+rightS;
        return sum;
    }
    void toSumTree(Node *node)
    {
       fn(node);
       return;
    }
};

