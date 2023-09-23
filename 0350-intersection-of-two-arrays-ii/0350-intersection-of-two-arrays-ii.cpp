class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>Mp;
        for(auto x:nums1)Mp[x]++;

        int k=0;
        for(auto n:nums2){
            if(Mp.find(n)!=Mp.end() && --Mp[n]>=0){
                nums1[k++]=n;
            }
        }
        return vector(nums1.begin(),nums1.begin()+k);
    }
};