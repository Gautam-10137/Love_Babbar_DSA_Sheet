#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int sum=0;
        int max_sum=INT_MIN;
        for(int i=0;i<arr.size();i++){
            
            sum+=arr[i];
            max_sum=max(max_sum,sum);
            if(sum<0) sum=0;
            
        }
        return max_sum;
    }
};

