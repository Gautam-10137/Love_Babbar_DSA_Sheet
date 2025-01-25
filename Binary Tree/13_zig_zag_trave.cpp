
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
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>ans;
    	queue<Node*>q;
    	deque<int> dq;
    	q.push(root);
    	bool flag=true;
    	while(!q.empty()){
    	    int size=q.size();
    	    
    	    while(size--){
    	        Node* front=q.front();
    	        q.pop();
    	        dq.push_back(front->data);
    	        if(front->left) q.push(front->left);
    	        if(front->right) q.push(front->right);
    	    }
    	    if(flag){
    	        while(!dq.empty()){
    	            ans.push_back(dq.front());
    	            dq.pop_front();
    	        }
    	    }
    	    else{
    	        while(!dq.empty()){
    	            ans.push_back(dq.back());
    	            dq.pop_back();
    	        }
    	    }
    	    flag=!flag;
    	}
    	return ans;
    }
};

