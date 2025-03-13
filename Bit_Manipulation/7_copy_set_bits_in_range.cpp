#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
  int setSetBit(int x, int y, int l, int r){
    int pos=l-1;
    while(pos<r){
      x=x | (y&(1<<pos));
      pos++;
    }
    return x;
  }
};