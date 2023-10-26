class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long MOD = 1000000007;
        int n = arr.size();
        vector<long long> dp(n, 1);
        unordered_map<int, int> Mp;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            Mp[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int key = arr[i] / arr[j];
                    if (Mp.find(key) != Mp.end()) {
                        dp[i] = ((dp[i] + dp[j] * dp[Mp[key]]) % MOD);
                    }
                }
            }
        }

        long long ans = 0;
        for (auto x : dp) {
            ans += x;
        }

        return static_cast<int>(ans % MOD);
    }

};