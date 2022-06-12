class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size() > 1) {
            for(auto i = 0; i < nums.size() / 2; ++i)
                nums[i] = i % 2 ? max(nums[2 * i], nums[2 * i + 1]) : min(nums[2 * i], nums[2 * i + 1]);
            
            nums.resize(nums.size() / 2);
        }
        
        return nums.back();
    }
};
