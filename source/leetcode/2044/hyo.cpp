class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_val = 0;
        for(auto x : nums) max_val |= x;
        
        int n = nums.size(), ret = 0;
        for(auto mask = 0; mask < (1 << n); ++mask) {
            int val = 0;
            for(auto i = 0; i < n; ++i)
                if(mask & (1 << i)) val |= nums[i];
            
            if(val == max_val)
                ++ret;
        }

        return ret;
    }
};
