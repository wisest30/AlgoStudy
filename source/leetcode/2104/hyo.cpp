class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ret = 0;
        for(auto i = 0; i < nums.size(); ++i) {
            int mine = nums[i], maxe = nums[i];
            for(auto j = i+1; j < nums.size(); ++j) {
                mine = min(mine, nums[j]), maxe = max(maxe, nums[j]);
                ret += maxe - mine;
            }
        }
        return ret;
    }
};
