class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> ans, prefix(n + 1);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + (long long) nums[i];

        for (int& x : queries) {
            int i = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            ans.push_back(1LL * x * (2 * i - n) + prefix[n] - 2 * prefix[i]);
        // query[i] * i - prefix[i] is increments required
        // prefix[n] - prefix[i] - query[i] * (n - i) is decrements required
        // Total = query[i] * i - prefix[i] + prefix[n] - prefix[i] - query[i] * (n - i)
        // Can be simplified to query[i] * (2 * i - n) + prefix[n] - 2 * prefix[i]
        }
        return ans;
    }
};
