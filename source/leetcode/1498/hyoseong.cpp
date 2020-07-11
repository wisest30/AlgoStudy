class Solution {
public:
    int numSubseq(vector<int>& nums, int t) {
        constexpr int MOD = 1e9+7;
        
        auto A = vector<long long>{1};
        for(auto i = 0; i < nums.size(); ++i) A.push_back(A.back() * 2 % MOD);
        
        sort(nums.begin(), nums.end());
        long long ret = 0;
        for(auto i = 0; i < nums.size(); ++i) {
            auto p = upper_bound(nums.begin(), nums.end(), t - nums[i]) - nums.begin();
            if(p <= i) break;
            ret = (ret + A[p - i - 1]) % MOD;
        }
        return ret;
    }
};
