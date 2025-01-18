
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
    vector<int> preorderTraversal(Node* root) {
      vector<int>ans;
      stack<Node*>st;
      Node* curr=root;
      while(curr ){

        ans.push_back(curr->data);
        if(curr->right) st.push(curr->right);
        curr=curr->left;
        if(!curr && !st.empty()){
            curr=st.top();
            st.pop();
        }
      }
      return ans;

    }
};

