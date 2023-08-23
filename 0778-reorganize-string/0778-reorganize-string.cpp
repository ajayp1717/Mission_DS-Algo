class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>Mp;
        for(char c:s)Mp[c]++;
        int tot=s.size(),maxi;
        char maxOcc;

        vector<pair<char,int>>charFreq;
        for(auto& x:Mp){
            charFreq.push_back(x);  
        }
        sort(charFreq.begin(),charFreq.end(),[](const auto& a,const auto & b){
            return a.second>b.second;
        });
        maxi=charFreq[0].second;
        if(maxi>(tot+1)/2)return "";
        string ans(tot,'#');
        
        int idx = 0;
        for (auto &entry : charFreq) {
            while (entry.second > 0) {
                if (idx >= tot)
                    idx = 1;  // Start filling odd indices
                ans[idx] = entry.first;
                entry.second--;
                idx += 2;
            }
        }
        return ans;
        
    }
};