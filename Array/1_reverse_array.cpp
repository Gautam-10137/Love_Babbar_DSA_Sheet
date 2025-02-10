#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int size=arr.size();
        for(int i=0;i<size/2;i++){
            swap(arr[i],arr[size-i-1]);
        }
    }
};

