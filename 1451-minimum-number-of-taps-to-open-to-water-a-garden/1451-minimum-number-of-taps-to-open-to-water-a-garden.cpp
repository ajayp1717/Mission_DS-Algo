class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intv;
        for (int i = 0; i <= n; i++) {
            intv.push_back({max(0, i - ranges[i]), min(n, i + ranges[i])});
        }
        sort(intv.begin(), intv.end());
        int ans=0,curr=0,nxt=0;
        for (int i = 0; i <= n; i++) {
            if(intv[i][0]>curr){
                if(curr>=nxt){
                    return -1;
                }
                curr=nxt;
                ans++;
            }
            nxt=max(nxt,intv[i][1]);
            if(nxt>=n)return ans+1;  
        }
        return -1;
    }
};