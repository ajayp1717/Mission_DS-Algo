class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        unordered_map<int,int>Mp;
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)cnt++;
            }
            temp.push_back({cnt,i});
        }
        sort(temp.begin(),temp.end());
        vector<int> ans(k);
        int i=0;
        for(auto x:temp){
            ans[i]=x.second;
            if(i==k-1)break;
            i++;
        }
        return ans;
        

        
    }
};