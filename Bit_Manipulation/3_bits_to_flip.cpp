#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  int countBitsFlip(int a, int b){
        
    int diff=a^b;
    int count=0;
    while(diff){
        if(diff&1) count++;
        diff=diff>>1;
    }
    return count;
    
  }
};