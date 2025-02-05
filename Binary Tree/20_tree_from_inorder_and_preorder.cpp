
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
    Node* fn(int si,int ei,vector<int>& inorder,int sp,int ep,vector<int>& preorder){
        if(si>ei || sp>ep) return NULL;
        int rv=preorder[sp];
        int ri=si;
        for(int i=si;i<=ei;i++){
            if(inorder[i]==rv){
                ri=i;
                break;
            }
        }
        Node* root=new Node(rv);
        root->left=fn(si,ri-1,inorder,sp+1,sp+(ri-si),preorder);
        root->right=fn(ri+1,ei,inorder,sp+(ri-si)+1,ep,preorder);
        return root;
    }
  
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        Node* root=fn(0,inorder.size()-1,inorder,0,preorder.size(),preorder);
        return root;
    }
};

