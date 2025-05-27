#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
    
     struct Node{
        int data;
        Node* left;
        Node* right;
        Node(int val): data(val),left(NULL),right(NULL){}
    };
    
    Node* insertNode(Node* root,int key,Node*&successor){
        if(!root) return new Node(key);
        if(root->data > key){
            successor=root;
            root->left=insertNode(root->left,key,successor);
        }
        else{
            root->right=insertNode(root->right,key,successor);
        }
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> result(n,-1);
        
        Node* root=NULL;
        for(int i=n-1;i>=0;i--){
            Node* successor=NULL;
            root=insertNode(root,arr[i],successor);
            if(successor) result[i]=successor->data;
        }
        return result;
    }
  };
