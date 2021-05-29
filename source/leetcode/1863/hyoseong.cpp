class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for(auto subset = 0; subset < 1 << n; ++subset) {
            int x = 0;
            for(auto i = 0; i < n; ++i)
                if(subset & (1 << i))
                    x ^= nums[i];
            ret += x;
        }
        
        return ret;
    }
};
