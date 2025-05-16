#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  // using memoization
    vector<string> fn(string& str,int idx,map<string,int>mp
                            ,unordered_map<int,vector<string>>&memo){
        if(memo.count(idx)) return memo[idx];
        vector<string>res;
        if(idx==str.size()){
            res.push_back("");
            return res;
        }
        
        for(int i=idx;i<str.size();i++){
            string sub=str.substr(idx,i-idx+1);
            if(mp.find(sub)!=mp.end()){
                vector<string> tempList=fn(str,i+1,mp,memo);
                for(string suffix:tempList){
                    string sentence=sub + (suffix.empty() ?"":" "+suffix);
                    res.push_back(sentence);
                }
            }
        }
        
        return memo[idx]=res;
        
    }
    vector<string> wordBreak(vector<string>& dict, string& s) {
        
        map<string,int>mp;
        for(string str: dict) mp[str]=1;
        unordered_map<int,vector<string>>memo;
        return fn(s,0,mp,memo);
    }
};


