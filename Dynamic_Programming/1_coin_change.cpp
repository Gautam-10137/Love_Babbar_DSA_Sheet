#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int findCount(vector<int>& coins,int idx,int target){
        if(target==0) return 1;
        if(idx==0){
            if(target%coins[0]==0) return 1;
            else return 0;
        }
        int take=0;
        if(target>=coins[idx]){
            take=findCount(coins,idx,target-coins[idx]);
        }
        int notake=findCount(coins,idx-1,target);
        return take+notake;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int target=0;target<=sum;target++){
            if(target%coins[0]==0) dp[0][target]=1;
        }
        
        for(int idx=1;idx<n;idx++){
            for(int target=0;target<=sum;target++){
                int take=0;
                if(target>=coins[idx]){
                   take=dp[idx][target-coins[idx]];
                }
                int notake=dp[idx-1][target];
                dp[idx][target]=take+notake;
            }
        }
        
        return dp[n-1][sum];
    }
};