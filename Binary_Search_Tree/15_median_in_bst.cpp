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

class Solution {
    public:
    
    int countNodes(struct Node* root){
        if(!root) return 0;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    void getNodes(struct Node* root,int& idx,int& num){
        if(!root) return;
        if(idx<0) return;
        getNodes(root->left,idx,num);
        idx--;
        if(idx==0){
            num=root->data;
            return;
        }
        getNodes(root->right,idx,num);
    }
    float findMedian(struct Node *root) {
        // Code here
        
        int n=countNodes(root);
        
        
        int idx=n/2;
        int num1=0;
        getNodes(root,idx,num1);
        int num2=0;
        idx=n/2+1;
        getNodes(root,idx,num2);
        
        if(n%2==0){
            return (num1+num2)/2.0;
        }
        else{
            return num2*1.0;
        }
    }
  };
