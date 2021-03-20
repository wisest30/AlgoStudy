class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        constexpr int MAX_N = 1 << 10;
        
        vector<int> dp(MAX_N, 1e5);
        dp[0] = 0;
        for(auto i = 0; i < k; ++i) {
            unordered_map<int, int> cnt;
            int tc = 0;
            for(auto j = i; j < nums.size(); j += k) {
                cnt[nums[j]]++;
                tc++;
            }
            
            auto min_val = *min_element(dp.begin(), dp.end());
            auto ndp = vector<int>(MAX_N, min_val + tc);
            for(auto j = 0; j < MAX_N; ++j) {
                for(auto& p : cnt) {
                    auto x = p.first;
                    auto c = tc - p.second;
                    ndp[j ^ x] = min(ndp[j ^ x], dp[j] + c);
                }
            }
            swap(dp, ndp);
        }
        
        auto ret = dp[0];
        return ret;
    }
};
