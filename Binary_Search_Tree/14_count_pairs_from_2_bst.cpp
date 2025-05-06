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
    
    void getNodes(Node* root,vector<int>&store){
        if(!root) return;
        getNodes(root->left,store);
        store.push_back(root->data);
        getNodes(root->right,store);
    }

    int countPairs(Node* root1, Node* root2, int x) {
        vector<int> store1;
        vector<int> store2;
        getNodes(root1,store1);
        getNodes(root2,store2);
        int countP=0;
        
        int m=store1.size(),n=store2.size();
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(store1[i]+store2[j]==x){
                int num1=store1[i];
                int num2=store2[j];
                i++;
                j--;
                int count1=1,count2=1;
                while(j>=0 && store2[j]==num2){
                   count2++; 
                   j--;
                } 
                while(i<m && store1[i]==num1){
                    count1++;
                    i++;
                }
                countP+=(count1*count2);
            }
            else if((store1[i]+store2[j])>x){
                j--;
            }
            else i++;
        }
        return countP;
    }
  };
