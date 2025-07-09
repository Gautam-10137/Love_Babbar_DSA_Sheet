class Solution {
    
    public boolean dfs(int node,boolean[] path,ArrayList<ArrayList<Integer>> adjL){
        if(path[node]==true) return true;
        path[node]=true;
        for(int neighNode:adjL.get(node)){
            if(dfs(neighNode,path,adjL)==true) return true;
            
        }
        path[node]=false;
        return false;
    }
    
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        boolean[] path=new boolean[V];
        ArrayList<ArrayList<Integer>> adjL=new ArrayList<>();
        
        for(int i=0;i<V;i++){
            adjL.add(new ArrayList<Integer>());
        }
        
        for(int i=0;i<edges.length;i++){
            adjL.get(edges[i][0]).add(edges[i][1]);
        }
        
        for(int i=0;i<V;i++){
            if(dfs(i,path,adjL)==true) return true;
        }
        
        return false;
        
    }
}