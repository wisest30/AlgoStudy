class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int64_t ret = 1, su = nums[0], i = 1, j = 0;
        while(i <= nums.size()) {
            auto need = nums[i-1] * (i - j) - su;
            while(need > k) {
                su -= nums[j++];
                need = nums[i-1] * (i - j) - su;
            }
            
            ret = max(ret, i - j);

            if(i < nums.size())
                su += nums[i];
            i++;
        }
        return ret;
    }
};
