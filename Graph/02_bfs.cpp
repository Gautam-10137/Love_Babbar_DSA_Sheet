#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    vector<int> bfsGraph(vector<vector<int>>& adj,vector<int>&visited){
        vector<int> ans;
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(visited[it]==0){
                    q.push(it);
                    visited[it]=1;
                }
            }
            
        }
        return ans;
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        
       
        vector<int> visited(adj.size(),0);
        
        return bfsGraph(adj,visited);
        
    }
};