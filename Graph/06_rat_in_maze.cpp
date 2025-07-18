#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void find(int row, int col,vector<vector<int>>& maze,string path, 
    vector<string> &ans,vector<vector<int>>&visit){
        
        if(row<0 || row >= maze.size() || col<0 
            || col>=maze.size() || maze[row][col]==0 || visit[row][col]) return;
            
        if(row==maze.size()-1 && col==maze.size()-1) {
            ans.push_back(path);
            return;
        }    
        
        visit[row][col]=1;
        find(row+1,col,maze,path+'D',ans,visit);
        find(row,col-1,maze,path+'L',ans,visit);
        find(row-1,col,maze,path+'U',ans,visit);
        find(row,col+1,maze,path+'R',ans,visit);
        visit[row][col]=0;
        return;
        
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        vector<vector<int>>visit(maze.size(),vector<int>(maze.size(),0));
        find(0,0,maze,"",ans,visit);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};