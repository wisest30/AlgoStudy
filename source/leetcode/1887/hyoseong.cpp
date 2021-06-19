class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> sorted(s.begin(), s.end());
        
        auto ret = 0;
        for(auto x : nums)
            ret += lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
        
        return ret;
    }
};
