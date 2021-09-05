class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums[k-1] - nums[0];
        for (int i=0; i+k-1 < nums.size(); i++) {
            ans = min(ans, nums[i+k-1] - nums[i]);
        }
        return ans;
    }
};
