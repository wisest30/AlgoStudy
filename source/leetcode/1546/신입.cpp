class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> cumSumIdx;
        cumSumIdx[0] = -1;
        
        int lastIdx = -1;
        int ans = 0;
        
        int sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            
            if(cumSumIdx.find(sum-target) != cumSumIdx.end())
            {
                if(cumSumIdx[sum-target] >= lastIdx)
                {
                    ans++;
                    lastIdx = i;
                }
            }
            
            cumSumIdx[sum] = i;
        }
        
        return ans;
    }
};
