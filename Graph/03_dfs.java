class Solution {
    // Function to return a list containing the DFS traversal of the graph.
    
    private void dfsT(int node, ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> ans, ArrayList<Integer> visited){
        visited.set(node,1);
        ans.add(node);
        for(Integer adjN:adj.get(node)){
            if(visited.get(adjN)==-1)
              dfsT(adjN,adj,ans,visited);
        }
    }
    public ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> ans=new ArrayList<>();
        int n=adj.size();
        ArrayList<Integer> visited=new ArrayList<>(Collections.nCopies(n,-1));
        
        dfsT(0,adj,ans,visited);
        return ans;
        
    }
}