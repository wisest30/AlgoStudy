class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k == 1)
        {
            if(nums.size() > 1) return nums[1];
            return -1;
        }
        if(nums.size() == 1)
        {
            if(k%2 == 1) return -1;
            return nums[0];
        }
        int ans = 0;
        
        for(int i=0;i<min(k-1,(int)nums.size());i++) ans = max(ans, nums[i]);
        
        if(k < nums.size()) return max(ans, nums[k]);
        return ans;
    }
};
