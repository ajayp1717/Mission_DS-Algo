class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>Mp;
        for(char c:s)Mp[c]++;
        int tot=s.size();
        vector<pair<char,int>>cF;
        for(auto x:Mp){
            cF.push_back(x);
        }
        sort(cF.begin(),cF.end(),[](const auto& a, const auto& b){
            return a.second>b.second;
        });
        int maxi=cF[0].second;
        if(maxi>(tot+1)/2)return "";
        string ans(tot,'#');
        int idx=0;
        for( auto& x:cF){
            while(x.second){
                if(idx>=tot)idx=1; //start filling odd indices;
                ans[idx]=x.first;
                x.second--;
                idx+=2;
            }
        }
        return ans;
        
        
    }
};