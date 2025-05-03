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
    void storeInorder(Node* root,vector<int>&inorder){
        if(!root) return;
        storeInorder(root->left,inorder);
        inorder.push_back(root->data);
        storeInorder(root->right,inorder);
    }

    vector<int> merge(vector<int>arr1,vector<int>arr2){
        vector<int>arr;
        int i=0,j=0;
        int m=arr1.size(),n=arr2.size();
        while(i<m && j<n){
            if(arr1[i]<arr2[j]) arr.push_back(arr1[i++]);
            else arr.push_back(arr2[j++]);
        }
        while(i<m) arr.push_back(arr1[i++]);
        while(j<n) arr.push_back(arr2[j++]);
        return arr;    
    }

    Node* sortedListToBST(vector<int>arr,int s,int e){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        Node* root=new Node(arr[mid]);
        root->left=sortedListToBST(arr,s,mid-1);
        root->right=sortedListToBST(arr,mid+1,e);
        return root;
    }

    Node* mergeTrees(Node* root1, Node* root2){

        vector<int> arr1;
        storeInorder(root1,arr1);

        vector<int> arr2;
        storeInorder(root2,arr2);
      
        vector<int>arr=merge(arr1,arr2);
        
        return sortedListToBST(arr,0,arr.size()-1);

    }
  };
