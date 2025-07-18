class Solution {
    
    boolean dfs(int node,List<ArrayList<Integer>> adjL,int[] parent,boolean[] visited){
        visited[node]=true;
      
        for(int neihbour:adjL.get(node)){
            if(!visited[neihbour]) {
                parent[neihbour]=node;
                if(dfs(neihbour,adjL,parent,visited)) return true;
            }    
            else if(neihbour!=parent[node]) return true;
        }
        return false;
    }
    public boolean isCycle(int V, int[][] edges) {
        // Code here
        int[] parent=new int[V];
        boolean[] visited=new boolean[V];
        
        List<ArrayList<Integer>> adjL=new ArrayList<>();
        
        for(int i=0;i<V;i++){
            adjL.add(new ArrayList<>());
            parent[i]=-1;
        }
         for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjL.get(u).add(v);
            adjL.get(v).add(u);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adjL,parent,visited)) return true;
            }
            
        }
        return false;
        
    }
}