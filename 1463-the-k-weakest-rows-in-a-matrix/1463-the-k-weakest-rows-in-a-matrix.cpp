class Solution {
public:
    int binSearch(vector<int>&row){
        int lo=0,hi=row.size();
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(row[mid]==1)lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            int cnt=binSearch(mat[i]);
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