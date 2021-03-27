class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        auto ret = nums[k];
        
        int l = k, r = k+1, min_val = nums[k];
        while(l > 0 || r < nums.size()) {
            if(l == 0) min_val = min(min_val, nums[r++]);
            else if(r == nums.size()) min_val = min(min_val, nums[--l]);
            else if(nums[l-1] < nums[r]) min_val = min(min_val, nums[r++]);
            else min_val = min(min_val, nums[--l]);
            
            ret = max(ret, min_val * (r - l));
        }
        
        return ret;
    }
};
