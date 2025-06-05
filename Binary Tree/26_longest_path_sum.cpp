
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

// using stack and queue

class Solution {
public:
    void findLongestPathSum(Node* root,int& ans, int sum, int depth, int& maxDepth){
        if(depth>maxDepth ){
            ans=sum;
            maxDepth=depth;
        }
        if(depth==maxDepth) ans=max(sum,ans);
        
        if(!root) return;
        
        findLongestPathSum(root->left,ans,sum + root->data,depth+1,maxDepth);
        findLongestPathSum(root->right,ans,sum + root->data,depth+1,maxDepth);
        
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int ans=0;
        int maxDepth=0;
        findLongestPathSum(root,ans,0,0,maxDepth);
        return ans;
        
    }
};

