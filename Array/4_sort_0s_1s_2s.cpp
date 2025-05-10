#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  // using Dutch National Flag Algo
  void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int low=0,high=n-1,mid=low;
        
        while(mid<=high){
            
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[high],arr[mid]);
                high--;
            }
            else{
                mid++;
            }
            
        }
        
    }
};

