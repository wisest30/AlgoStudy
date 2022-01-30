class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int cnt0 = 0, cnt1 = accumulate(nums.begin(), nums.end(), 0);
        int max_val = 0;
        vector<int> ret;
        for(auto i = 0; i <= nums.size(); ++i) {
            auto val = cnt0 + cnt1;
            if(val >= max_val) {
                if(val > max_val) ret.clear(), max_val = val;
                ret.push_back(i);
            }
            if(i < nums.size()) {
                cnt0 += nums[i] ^ 1;
                cnt1 -= nums[i];
            }
        }
        return ret;
    }
};
