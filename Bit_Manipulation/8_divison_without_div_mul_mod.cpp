#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
  long long divide(long long dividend, long long divisor) {
        
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        int sign= (dividend<0)^(divisor<0)?-1:1;
        
        dividend=abs(dividend);
        divisor=abs(divisor);
        int qoutient=0;
        
        for(int i=31;i>=0;i--){
            if(dividend>=(divisor<<i)*1LL){
                dividend-= (divisor<<i)*1LL;
                qoutient|=1LL<<i;
            }    
          
            
        }
        return qoutient*sign;
    }
};