#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {

    unordered_map<Node*,Node*>mp;
    Node* clone(Node* node){
        Node* newNode;
        if(mp.find(node)!=mp.end()){
                newNode=mp[node];
        }
        else{
            newNode=new Node(node->val);
            mp[node]=newNode;

            for(int i=0;i<node->neighbors.size();i++){
               newNode->neighbors.push_back(clone(node->neighbors[i]));
            }
    
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        return clone(node);
    }
};