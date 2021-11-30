class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        auto ret = vector<int>(n, -1);
        
        if(n < 2 * k + 1)
            return ret;
        
        long long s = 0;
        for(auto i = 0; i < 2 * k + 1; ++i)
            s += nums[i];
        
        ret[k] = s / (2 * k + 1);
        
        for(auto i = k + 1; i + k < n; ++i) {
            s -= nums[i - k - 1];
            s += nums[i + k];
            ret[i] = s / (2 * k + 1);
        }
        
        return ret;
    }
};
