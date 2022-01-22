class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_val = 0, max_val = 0, cur = 0;
        for(auto d : differences) {
            cur += d;
            min_val = min(min_val, cur);
            max_val = max(max_val, cur);
        }
        int ret = 0;
        for(auto i = lower; i <= upper; ++i)
            if(i + min_val >= lower && i + max_val <= upper) ++ret;
        return ret;
    }
};
