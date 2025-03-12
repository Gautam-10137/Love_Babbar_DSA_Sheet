#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
  int findPosition(int n) {
        
    if(n==0 || n&(n-1)) return -1;
    
    return log2(n)+1;
  }
};