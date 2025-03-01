#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {

        // brute-force approach
        int count=0;
        int i=n;
        while(i>0){
          int num=i;
          while(num){
            if(num & 1) count++;
            num=num>>1;
          }
          i--;
        }
        return count;
    }
};