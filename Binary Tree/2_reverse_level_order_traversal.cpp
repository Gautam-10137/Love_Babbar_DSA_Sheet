//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
       vector<int> ans;
       vector<int>temp;
       queue<Node*>q,qtemp;
       q.push(root);
       
       while(!q.empty()){
           Node* front=q.front();
           temp.push_back(front->data);
           q.pop();
           if(front->left) qtemp.push(front->left);
           if(front->right) qtemp.push(front->right);
           if(q.empty()){
               for(int i=temp.size()-1;i>=0;i--){
                   ans.push_back(temp[i]);
               }
               temp.clear();
               swap(q,qtemp);
           }
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};

