#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int findMax(int W,int idx,vector<int> &val, vector<int> &wt){
        if(idx==0){
            if(W>=wt[0]) return val[0];
            else return 0;
        }
        int take=0;
        if(W>=wt[idx]){
            take=val[idx]+findMax(W-wt[idx],idx-1,val,wt);
        }
        int notake=findMax(W,idx-1,val,wt);
        return max(take,notake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        
        
        for(int wg=1;wg<=W;wg++){
            if(wg>=wt[0]) dp[0][wg]=val[0];        
        }
        
        for(int idx=1;idx<n;idx++){
            for(int wg=1;wg<=W;wg++){
                int take=0;
                if(wg>=wt[idx]){
                    take=val[idx]+dp[idx-1][wg-wt[idx]];
                }
                int notake=dp[idx-1][wg];
                dp[idx][wg]=max(take,notake);
            }
        }
        
        
        return dp[n-1][W];
        
    }
};