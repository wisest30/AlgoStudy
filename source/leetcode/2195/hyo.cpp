class Solution {
public:
    long long sum_from_to(long long l, long long r) {
        if(l > r)
            return 0;
        else
            return r * (r + 1) / 2 - l * (l - 1) / 2;
    }
    
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);

        long long ret = 0, prev = 0;
        for(long long cur : nums) {
            long long cnt = max(0ll, cur - prev - 1);
            auto add = cnt <= k ? sum_from_to(prev + 1, cur - 1) : sum_from_to(prev + 1, prev + k);
            
            ret += add;
            k = max(0ll, k - cnt);
            prev = cur;
        }
        
        return ret;
    }
};
