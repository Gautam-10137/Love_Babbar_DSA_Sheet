#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>> &image,vector<vector<int>> &ans,
    int row, int col,int drow[], int dcol[],
    int initialColor, int newColor ){


        // Color the current cell
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i<4; i++){
            int newRow = row + drow[i];
            int newCol = col + dcol[i];

            // Check bounds, color match, and not already updated
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                image[newRow][newCol] == initialColor &&
                ans[newRow][newCol] != newColor) {
            
                dfs(image,ans,newRow,newCol,drow,dcol,initialColor,newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc]; // to be coloured everywhere

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1}; 

        if(initialColor == color) return image;

        vector<vector<int>> ans = image;

        dfs(image,ans,sr,sc,drow,dcol,initialColor,color);

        return ans;
        
    }
};