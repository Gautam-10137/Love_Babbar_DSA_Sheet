#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int jump(int idx,vector<int>& arr, vector<int>&memo){
        if(idx>=(arr.size()-1)) return 0;
        if(memo[idx]!=-1) return memo[idx];
        int minSteps=INT_MAX;
        for(int k=1;k<=arr[idx];k++){
            minSteps=min(minSteps,jump(idx+k,arr,memo));
        }
        return memo[idx]=minSteps==INT_MAX?INT_MAX:1+minSteps;
        
    }
  
    int minJumps(vector<int>& arr) {
        vector<int> memo(arr.size(),-1);
        int steps= jump(0,arr,memo);
        return steps==INT_MAX?-1:steps;
        
    }
};

