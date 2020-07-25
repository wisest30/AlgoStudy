class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        auto ret = 0;
        for(auto i = 0; i < n; ++i)
            for(auto j = i+1; j < n; ++j)
                ret += nums[i] == nums[j];
        return ret;
    }
};
