class Solution {
public:
    vector<int> nums;
    vector<vector<int>> dp;
    int numSlots;
    int recur(int start, int subset) {
        if(start == nums.size()) return 0;
        auto& ret = dp[start][subset];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(auto i = 0, p = 1; i < numSlots; ++i, p *= 3)
            if(subset / p % 3 < 2)
                ret = max(ret, (nums[start] & (i+1)) + recur(start + 1, subset + p));

        return ret;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        this->numSlots = numSlots;
        this->nums = nums;
        
        auto max_subset = 1;
        for(auto i = 0; i < numSlots; ++i)
            max_subset *= 3;
        
        dp = vector<vector<int>>(nums.size(), vector<int>(max_subset, -1));
        return recur(0, 0);
    }
};
