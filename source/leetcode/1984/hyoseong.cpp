class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int ret = INT_MAX;
        for(int i = 0, j = k-1; j < n; ++i, ++j)
            ret = min(ret, nums[j] - nums[i]);
        
        return ret;
    }
};
