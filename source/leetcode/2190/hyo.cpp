class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> m;
        int ret = -1, max_cnt = 0;
        for(auto i = 1; i < nums.size(); ++i) {
            if(nums[i-1] == key) {
                if(++m[nums[i]] > max_cnt)
                    ret = nums[i], max_cnt = m[nums[i]];
            }
        }
        
        return ret;
    }
};
