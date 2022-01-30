class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        int ret = original;
        for(auto num : nums) if(num == ret) ret *= 2;
        return ret;
    }
};
