#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    void rotate(vector<int> &arr) {
        // Brute force
        // int n=arr.size();
        // int temp=arr[n-1];
        // for(int i=n-2;i>=0;i--){
        //     arr[i+1]=arr[i];
        // }
        // arr[0]=temp;

        // built-in function
        // rbegin() -> begkin from end
        // rend() -> reverse end i.e. begin point 
        std::rotate(arr.rbegin(),arr.rbegin()+1,arr.rend());
    }
};

