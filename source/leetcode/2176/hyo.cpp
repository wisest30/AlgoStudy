class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = 0;
        for(auto i = 0; i < n; ++i) {
            for(auto j = i + 1; j < n; ++j) {
                if(nums[i] == nums[j] && i * j % k == 0)
                    ++ret;
            }
        }
        
        return ret;
    }
};
