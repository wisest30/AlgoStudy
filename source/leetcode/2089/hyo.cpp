class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<int> ret;
        for(auto i = 0; i < nums.size(); ++i)
            if(nums[i] == target)
                ret.push_back(i);
        
        return ret;
    }
};
