class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto max_val = *max_element(nums.begin(), nums.end());
        int cnt = 0, ret = 0;
        for(auto num : nums)
            ret = max(ret, num == max_val ? ++cnt : (cnt = 0));
        
        return ret;
    }
};