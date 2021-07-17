class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        
        for(auto i = 0; i < n; ++i)
            ret[i] = nums[nums[i]];
        
        return ret;
    }
};
