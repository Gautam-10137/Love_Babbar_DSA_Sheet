#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
   int findUnion(vector<int>& a, vector<int>& b) {
      // 1st approach
        // map<int,int> mp;
        // for(int i=0;i<a.size();i++){
        //     mp[a[i]]=1;
        // }
        // for(int i=0;i<b.size();i++){
        //     mp[b[i]]=1;
        // }
        // return mp.size();
        
      // 2nd approach  
        set<int>st;
        for(int i=0;i<a.size();i++){
            st.insert(a[i]);
        }
        for(int i=0;i<b.size();i++){
            st.insert(b[i]);
        }
        return st.size();
        
    }
};

