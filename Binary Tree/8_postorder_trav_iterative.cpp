
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
 vector<int> postorderTraversal(Node* root) {
        vector<int>ans;
        stack<Node*> mainS,rightS;
        Node* curr=root;
        while(curr || !mainS.empty()){
            if(!curr){
                curr=mainS.top();
                if(!rightS.empty() && curr->right && curr->right==rightS.top()){
                    rightS.pop();
                    curr=curr->right;
                }
                else{
                    ans.push_back(curr->data);
                    mainS.pop();
                    curr=NULL;
                }
                continue;
            }
            if(curr->right){
                rightS.push(curr->right);
            }
            mainS.push(curr);
            curr=curr->left;
            
            
             
        }
        
        return ans;
    }
};

