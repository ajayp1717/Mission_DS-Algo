class Solution {
public:
    int minDeletions(string s) {
        map<char,int>Mp;
        unordered_set<int>St;
        int cnt=0;
        for(auto x:s)Mp[x]++;

        for(auto x:Mp){
            if(!St.count(Mp[x.first])){
                St.insert(Mp[x.first]);
            }
            else{
                while(Mp[x.first] && St.count(Mp[x.first])>0){
                    Mp[x.first]--;
                    cnt++;
                }
                St.insert(Mp[x.first]);
            }
        }
        return cnt;
        
    }
};