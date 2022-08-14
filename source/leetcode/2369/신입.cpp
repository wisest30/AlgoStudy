class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1])
            {
                if(dp[i-1]) dp[i+1] = true;
            }
            if(i > 1)
            {
                if(nums[i] == nums[i-1] && nums[i] == nums[i-2])
                {
                    if(dp[i-2]) dp[i+1] = true;
                }
                if(nums[i] == nums[i-1] + 1 && nums[i-1] == nums[i-2] + 1)
                {
                    if(dp[i-2]) dp[i+1] = true;
                }
            }
        }
        
        return dp[n];
    }
};
