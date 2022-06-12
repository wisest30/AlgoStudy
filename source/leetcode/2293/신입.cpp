class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> newNums;
        for(int i=0;i<nums.size()/2;i++)
        {
            if(i%2 == 0) newNums.push_back(min(nums[2*i], nums[2*i+1]));
            else newNums.push_back(max(nums[2*i], nums[2*i+1]));
        }
        return minMaxGame(newNums);
    }
};
