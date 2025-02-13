#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  int setBits(int n) {
    int temp=n;
    int count=0;
    while(temp){
        if(temp & 1) count++;
        temp=temp>>1;
    }
    return count;
}
};