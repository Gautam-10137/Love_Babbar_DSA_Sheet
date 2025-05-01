#include<bits/stdc++.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Solution {
    public:
      Node* fn(int pre[],int s, int e){
          if(s>e) return NULL;
          Node* root=newNode(pre[s]);
          int idx=s+1;
          for(int i=s+1;i<=e;i++){
              if(pre[i]>pre[s]){
                  idx=i;
                  break;
              }
          }
          root->left=fn(pre,s+1,idx-1);
          root->right=fn(pre,idx,e);
          return root;
      }
      // Function that constructs BST from its preorder traversal.
      Node* Bst(int pre[], int size) {
          // code here
          Node* root=fn(pre,0,size-1);
          return root;
          
      }
  };