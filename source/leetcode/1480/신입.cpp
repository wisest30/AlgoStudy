class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> newNums(nums.size(), nums[0]);
        for(int i=1;i<newNums.size();i++) newNums[i] = newNums[i-1] + nums[i];
        return newNums;
    }
};
