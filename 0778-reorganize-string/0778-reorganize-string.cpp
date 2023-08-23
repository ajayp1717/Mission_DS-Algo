class Solution {
public:
   struct Compare {
        bool operator()(const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second < b.second;
        }
    };
    string reorganizeString(string s) {
        unordered_map<char,int>Mp;
        for(char c:s)Mp[c]++;
        int tot=s.size();
        auto compare=[](const auto& a,const auto& b){
            return a.second<b.second;};
        priority_queue<pair<char,int>,vector<pair<char,int>>,Compare>pq;
        
        for(auto x:Mp){
            pq.push(x);
        }
        
        int maxi=pq.top().second;
        if(maxi>(tot+1)/2)return "";

        string ans(tot,'#');
        int idx=0;
        while( !pq.empty()){
            auto x=pq.top();
            pq.pop();
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