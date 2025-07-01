#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Depth First Traversal of given graph.
    void dfsT(int node, vector<vector<int>>& adjL, vector<int>& visited,vector<int>& ans){
        visited[node]=1;
        ans.push_back(node);
        for(int adjN:adjL[node]){
            if(!visited[adjN])
              dfsT(adjN,adjL,visited,ans);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n= adj.size();
        vector<int> visited(n,0);
        vector<int> ans;
        dfsT(0,adj,visited,ans);
        return ans;
    }
};