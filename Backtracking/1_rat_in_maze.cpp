#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void dfs(vector<vector<int>> &mat,int row,int col,string path,vector<vector<int>>& isVisit,vector<string>&ans){
        int n=mat.size();
        if(row<0 || row>=n || col<0 || col>=n || !mat[row][col]) return;
        if(row==n-1 && col==n-1) {
            ans.push_back(path);
            return;
        }
        if(isVisit[row][col]) return;
        isVisit[row][col]=1;
        // down
        dfs(mat,row+1,col,path+'D',isVisit,ans);
        // up
        dfs(mat,row-1,col,path+'U',isVisit,ans);
        // left
        dfs(mat,row,col-1,path+'L',isVisit,ans);
        // right
        dfs(mat,row,col+1,path+'R',isVisit,ans);
        isVisit[row][col]=0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        string path="";
        vector<vector<int>>isVisit(mat.size(),vector<int>(mat.size(),0));
        vector<string>ans;
        dfs(mat,0,0,path,isVisit,ans);
        return ans;
    }
};


