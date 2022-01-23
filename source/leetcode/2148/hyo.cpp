class Solution {
public:
    int countElements(vector<int>& nums) {
        auto max_val = *max_element(nums.begin(), nums.end());
        auto min_val = *min_element(nums.begin(), nums.end());
        auto ret = 0;
        for(auto num : nums) if(num > min_val && num < max_val) ++ret;
        return ret;
    }
};
