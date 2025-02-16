#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  int kthSmallest(vector<int> &arr, int k) {
         
    int maxe=arr[0];
    for(int i=1;i<arr.size();i++){
        maxe=max(maxe,arr[i]);
    }
    
    vector<int> freq(maxe+1,0);
    for(int ele:arr){
        freq[ele]++;
    }
    int count=0;
    int ans=0;
    for(int i=1;i<=maxe;i++){
        if(freq[i]){
            count++;
            if(count==k){
                ans=i;
                break;
            }
        }
    }
    return ans;
}
};

