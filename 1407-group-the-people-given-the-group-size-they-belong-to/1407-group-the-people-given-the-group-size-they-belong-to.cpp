class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gS) {
        map<int,vector<int>>Mp;
        for(int i=0;i<gS.size();i++){
            Mp[gS[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto x:Mp){
            
            for(int i=0;i<x.second.size();){
                vector<int>temp;
                int size=x.first;
                while(size--){
                    temp.push_back(x.second[i]);
                    i++;
                }
                ans.push_back(temp);
            }
        }

        return ans;

        
    }
};