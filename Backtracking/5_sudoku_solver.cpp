#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    // Function to find a solved Sudoku.
    
    bool valid(vector<vector<int>>& mat,int row,int col,int val){
        for(int i=0;i<9;i++){
            if(mat[i][col]==val) return false;
        }
        
        for(int j=0;j<9;j++){
            if(mat[row][j]==val) return false;
        }
        int r=(row/3)*3;
        int c=(col/3)*3;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(mat[i][j]==val) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int>>&mat){
     
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]==0){
                    for(int k=1;k<=9;k++){
                        if(valid(mat,i,j,k)){
                            mat[i][j]=k;
                            if(solve(mat)) return true;
                            mat[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
        
    }

};


