class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> ps(n+1);
        for(auto i = 1; i <= n; ++i)
            ps[i] = ps[i-1] + nums[i-1];
        
        long long ret = 0;
        for(auto i = 1; i <= n; ++i) {
            int l = -1, r = i;
            while(l + 1 < r) {
                auto m = (l + r) / 2;
                long long s = (ps[i] - ps[m]) * (i - m);
                if(s >= k) l = m;
                else r = m;
            }
            
            ret += i - r;
        }
        
        return ret;
    }
};
