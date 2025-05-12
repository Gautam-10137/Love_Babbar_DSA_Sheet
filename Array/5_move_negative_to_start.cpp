#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

  vector<int> move(vector<int>& arr){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0) cnt++;
    }
    int i=0;
    for(int j=0;j<cnt;j++){
        while(i<n && arr[i]>0) i++;
        
        swap(arr[i],arr[j]);
        i++;
    }

    return arr;
  }
};

