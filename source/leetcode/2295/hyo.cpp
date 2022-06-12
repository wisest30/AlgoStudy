class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int ret = 1, l = 0, r = 0;
        while(r < nums.size())
            nums[r] - nums[l] <= k ? ++r : (l = r, ++ret);
        
        return ret;
    }
};
