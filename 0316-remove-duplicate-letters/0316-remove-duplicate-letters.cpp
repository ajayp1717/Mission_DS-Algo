class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int>used(26,0);
        vector<int>lastOccur(26,-1);
        string ans="";
        stack<char>St;

        for(int i=0;i<s.length();i++){
            lastOccur[s[i]-'a']=i;
        }
        for(int i=0;i<s.length();i++){
            char curr=s[i];
            if(used[curr -'a'])continue;

            while(!St.empty() && curr< St.top() && i< lastOccur[St.top()-'a']){
                used[St.top()-'a']=0;
                St.pop();
            }
            St.push(curr);
            used[curr-'a']=1;
        }
        while(!St.empty()){
            ans=St.top()+ans;
            St.pop();
        }
        return ans;
    }
};