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
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            int cnt=binSearch(mat[i]);
            pq.push({cnt,i});
            if(pq.size()>k)pq.pop();
        }
        
        vector<int> ans(k);
        for(int i=k-1;i>=0;i--){
            ans[i]=(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};