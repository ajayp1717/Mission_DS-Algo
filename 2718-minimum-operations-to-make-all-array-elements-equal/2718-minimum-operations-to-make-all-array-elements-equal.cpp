class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> ans;
        vector<long long> prefixSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + (long long)nums[i];
        }

        for (int x : queries) {
            int lowerIndex = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            int upperIndex = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            
            long long lowerSum = abs(prefixSum[lowerIndex] - (long long)x * lowerIndex);
            long long upperSum = abs(prefixSum[n] - prefixSum[upperIndex] - (long long)x * (n - upperIndex));

            long long temp = lowerSum + upperSum;
            ans.push_back(temp);
        }

        return ans;
    }
};