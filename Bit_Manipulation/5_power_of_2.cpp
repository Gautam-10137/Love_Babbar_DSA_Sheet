#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  bool isPowerofTwo(int n) {
        
    return (n & (n-1))==0?true:false;
}
};