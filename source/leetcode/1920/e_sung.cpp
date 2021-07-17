class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        for(int i = 0; i < nums.size();i++){
            res[i] = nums[nums[i]];
        }
        return res;
    }
};
