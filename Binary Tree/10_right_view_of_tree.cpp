
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
   vector<int> rightView(Node *root)
    {
       vector<int>ans;
       queue<Node*>q,qtemp;
       q.push(root);
      
       while(!q.empty()){
           Node* front=q.front();
           q.pop();
           if(front->left) qtemp.push(front->left);
           if(front->right) qtemp.push(front->right);
           
           if(q.size()==0){
               ans.push_back(front->data);
               swap(q,qtemp);
           } 
       }
       return ans;
    }
};

