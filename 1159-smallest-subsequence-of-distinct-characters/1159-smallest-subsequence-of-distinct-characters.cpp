class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,bool>seen;
        vector<int>lastOccur(26,-1);
        stack<char>St;
        string ans="";

        for(int i=0;i<s.length();i++){
            lastOccur[s[i]-'a']=i;
        }

        for(int i=0;i<s.length();i++){
            char curr=s[i];
            if(!seen[curr]){
                while(!St.empty() && curr< St.top() && i<lastOccur[St.top()-'a']){
                    seen[St.top()]=false;
                    St.pop();
                }
                St.push(curr);
                seen[curr]=true;
            }
        }
        while(!St.empty()){
            ans=St.top()+ans;
            St.pop();
        }
        return ans;
        
    }
};