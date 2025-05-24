#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int currS=0;
        int maxS=INT_MIN;
        for(int i:arr){
            currS+=i;
            maxS=max(maxS,currS);
            if(currS<0) currS=0;
        }
        
        return maxS;
    }
};

