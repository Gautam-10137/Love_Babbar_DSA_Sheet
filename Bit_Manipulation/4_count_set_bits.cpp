#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {

        // brute-force approach
        // int count=0;
        // int i=n;
        // while(i>0){
        //   int num=i;
        //   while(num){
        //     if(num & 1) count++;
        //     num=num>>1;
        //   }
        //   i--;
        // }
        // return count;

        // log(n) solution
        if(n==0) return 0;
        // Find the largest power of 2 that is <=n
        int x=log2(n);
        int power_of_2= 1<<x;   // equivalent to 2^x
        
        // count of set bits from 0 to 2^x-1
        int bits_up_to_2x= x*(power_of_2>>1); // x*(2^(x-1))
        
        // count MSB Contribution from 2^x to n
        int msb_from_2x_to_n= n-power_of_2+1;
        
        // recur for remaining numbers after 2^x
        int remaining= countSetBits(n - power_of_2);
        return bits_up_to_2x + msb_from_2x_to_n + remaining;
    }
};