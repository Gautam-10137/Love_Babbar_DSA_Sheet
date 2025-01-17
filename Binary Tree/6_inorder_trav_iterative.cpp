
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
    vector<int> inorderTraversal(Node* root) {
        vector<int>ans;
        stack<Node*> st;
        Node* curr=root;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                curr=st.top();
                ans.push_back(curr->data);
                st.pop();

               curr=curr->right;
               
            }
        }
        return ans;
    }
};

