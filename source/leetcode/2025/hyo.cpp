class Solution {
public:
    int waysToPartition(vector<int>& nums, long long k) {
        int n = nums.size();
        long long lsum = nums[0], rsum = 0;
        for(auto i = 1; i < n; ++i) {
            rsum += nums[i];
        }

        map<long long, int> lm, rm;
        for(auto i = 1; i < n; ++i) {
            rm[lsum - rsum]++;
            lsum += nums[i];
            rsum -= nums[i];
        }
        
        int ret = rm[0];
        rsum = lsum;
        lsum = 0;
        for(auto i = 0; i < n; ++i) {
            long long d = k - nums[i];
            ret = max(ret, rm[-d] + lm[d]);            
            lsum += nums[i];
            rsum -= nums[i];
            rm[lsum - rsum]--;
            lm[lsum - rsum]++;
        }
        
        return ret;
    }
};
