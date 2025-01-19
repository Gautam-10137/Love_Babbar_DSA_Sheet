
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
    vector<int> leftView(Node *root) {
        vector<int>ans;
        if(!root) return ans;
        queue<Node*> q,qtemp;
        q.push(root);
        ans.push_back(root->data);
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front->left) qtemp.push(front->left);
            if(front->right) qtemp.push(front->right);
            if(q.empty()){
                if(qtemp.empty()) break;
                swap(q,qtemp);
                ans.push_back(q.front()->data);
            }
        }
        return ans;
    }
};

