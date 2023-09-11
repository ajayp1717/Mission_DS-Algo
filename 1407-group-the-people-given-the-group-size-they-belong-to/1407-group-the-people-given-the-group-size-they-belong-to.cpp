class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gS) {
        unordered_map<int,vector<int>>Mp;
        vector<vector<int>> ans;
        for(int i=0;i<gS.size();i++){
            Mp[gS[i]].push_back(i);

            if(Mp[gS[i]].size()==gS[i]){
                ans.push_back(Mp[gS[i]]);
                Mp.erase(gS[i]);
            }
        }
        return ans;        
    }
};