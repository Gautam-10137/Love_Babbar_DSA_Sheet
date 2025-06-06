#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=arr[n-1]-arr[0];
        int smallest=arr[0]+k;
        int largest=arr[n-1]-k;
        
        for(int i=0;i<n-1;i++){
            // if we decrease current height, it will affect lowest Height
            int minH=min(smallest,arr[i+1]-k);
            // if we increase current height , it will addect highest height
            int maxH=max(largest,arr[i]+k);
            
            if(minH<0) continue;
            ans=min(ans,maxH-minH);
        }
        return ans;
    }
};

