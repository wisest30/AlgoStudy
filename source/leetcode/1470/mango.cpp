class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>shuffled;
        for(int i = 0; i < n; i++){
            shuffled.push_back(nums[i]);
            shuffled.push_back(nums[i + n]);
        }
        return shuffled;
    }
};
