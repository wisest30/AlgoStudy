class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        constexpr long long MOD = 1e9+7;
        
        long long su = 0;
        int n = nums1.size();
        for(auto i = 0; i < n; ++i)
            su += abs(nums1[i] - nums2[i]);

        auto A = nums1;
        sort(A.begin(), A.end());

        auto ret = su;
        for(auto i = 0; i < n; ++i) {
            auto p = lower_bound(A.begin(), A.end(), nums2[i]) - A.begin();
            if(p > 0) ret = min(ret, su - abs(nums1[i] - nums2[i]) + abs(A[p-1] - nums2[i]));
            if(p < n) ret = min(ret, su - abs(nums1[i] - nums2[i]) + abs(A[p] - nums2[i]));
        }
        
        ret %= MOD;
        return ret;
    }
};
