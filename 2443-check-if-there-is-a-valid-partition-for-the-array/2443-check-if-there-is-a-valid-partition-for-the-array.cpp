class Solution {
public:
    std::unordered_map<int, bool> memo;

    // Determine if the prefix array nums[0 ~ i] has a valid partition
    bool prefixIsValid(std::vector<int>& nums, int i) {
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }
        bool ans = false;

        // Check 3 possibilities
        if (i > 0 && nums[i] == nums[i - 1]) {
            ans |= prefixIsValid(nums, i - 2);
        }
        if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
            ans |= prefixIsValid(nums, i - 3);
        }
        if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) {
            ans |= prefixIsValid(nums, i - 3);
        }
        memo[i] = ans;
        return ans;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        memo[-1] = true;

        return prefixIsValid(nums, n - 1);
        
    }
};