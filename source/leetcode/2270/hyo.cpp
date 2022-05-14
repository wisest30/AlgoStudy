class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long right_sum = accumulate(nums.begin(), nums.end(), 0ll);
        long long left_sum = 0;
        int ret = 0;
        for(auto i = 0; i + 1 < nums.size(); ++i) {
            left_sum += nums[i];
            right_sum -= nums[i];
            if(left_sum >= right_sum)
                ret++;
        }
        
        return ret;
    }
};
