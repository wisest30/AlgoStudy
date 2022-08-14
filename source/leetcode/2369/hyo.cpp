class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> dp(n + 1);
        dp[0] = true;
        
        for(auto i = 2; i <= n; ++i) {
            if(dp[i-2] && nums[i-2] == nums[i-1])
                dp[i] = true;
            if(i >= 3 && dp[i-3] && nums[i-3] == nums[i-2] && nums[i-2] == nums[i-1])
                dp[i] = true;
            if(i >= 3 && dp[i-3] && nums[i-3] + 1 == nums[i-2] && nums[i-2] + 1 == nums[i-1])
                dp[i] = true;
        }
        
        return dp[n];
    }
};
