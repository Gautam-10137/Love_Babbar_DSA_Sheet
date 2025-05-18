#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

// DFS approach , we can also follow BFS approach, by remove each bracket and take that 
// new string into consideration,then in next round again remove each bracket
//    
    unordered_set<string> result;
    unordered_set<string> visited;
    void dfs(string s,int idx,int leftCount ,int rightCount,int leftRemove,int rightRemove,string path){
        if(idx==s.length()){
            if(leftCount==0 && leftRemove==0 && rightRemove==0)
                result.insert(path);
            return;
        }
        char c=s[idx];
        string key=to_string(idx)+","+to_string(leftCount)+","+to_string(rightCount)+","+to_string(leftRemove)+","+path;
        if(visited.count(key)) return;
        visited.insert(key);
        if(c=='('){
           // skipping current parenthesis 
           if(leftRemove>0)
             dfs(s,idx+1,leftCount,rightCount,leftRemove-1,rightRemove,path);
           
           // considering the current parenthesis
           dfs(s,idx+1,leftCount+1,rightCount,leftRemove,rightRemove,path+c); 
        }
        else if(c==')'){
            // skipping the ')'
            if(rightRemove>0)
              dfs(s,idx+1,leftCount,rightCount,leftRemove,rightRemove-1,path);
            
            // considering the ')' only if leftCount '(' is there
            if(leftCount>0)
              dfs(s,idx+1,leftCount-1,rightCount,leftRemove, rightRemove,path+c);

        }
        else{
            // always consider the char other than '(' and ')'
            // , all other values remains as such
            dfs(s,idx+1,leftCount,rightCount,leftRemove,rightRemove,path+c); 
        }

    }

    vector<string> removeInvalidParentheses(string s) {
 
       int leftRemove=0;
       int rightRemove=0;
   
       for(char c:s){
        if(c=='(') leftRemove++;
        else if(c==')'){
            if(leftRemove==0) rightRemove++;
            else leftRemove--;
        }
       }
       dfs(s,0,0,0,leftRemove,rightRemove,"");
       return vector<string>(result.begin(),result.end());

    }

};


