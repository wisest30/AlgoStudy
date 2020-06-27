class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        auto ret = nums;
        for(auto i = 1; i < ret.size(); ++i)
            ret[i] += ret[i-1];
        return ret;
    }
};
