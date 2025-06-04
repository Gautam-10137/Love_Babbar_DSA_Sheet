
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
       int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        unordered_map<int,stack<int>> treeA;
        unordered_map<int,queue<int>> treeB;
        
        for(int i=0;i<2*e;i+=2){
            treeA[A[i]].push(A[i+1]);
        }
        
        for(int i=0;i<2*e;i+=2){
            treeB[B[i]].push(B[i+1]);
        }
        
        for(auto it : treeA){
            int node=it.first;
            while(!it.second.empty() && !treeB[node].empty()){
                if( treeA[node].top()!=treeB[node].front()){
                    return 0;
                }
                treeA[node].pop();
                treeB[node].pop();
            }
            
            if(!treeA[node].empty() || !treeB[node].empty())
              return 0;
            
        }
        return 1;
            
    }
};

