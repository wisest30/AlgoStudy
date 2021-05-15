class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ret = INT_MAX;
        for(auto i = 0; i < nums.size(); ++i)
            if(nums[i] == target)
                ret = min(ret, abs(start - i));
        return ret;
    }
};
