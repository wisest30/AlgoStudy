class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), ret = 0;
        for(auto i = 0; i < n; ++i)
            for(auto j = 0; j < n; ++j)
                if(i != j && nums[i] + nums[j] == target)
                    ret++;
        
        return ret;
    }
};
