class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        if(nums.size() % 2) nums.push_back(0);

        int p = nums.size() / 2;
        vector<int> left, right;
        for(auto i = 0; i < p; ++i) left.push_back(nums[i]);
        for(auto i = p; i < nums.size(); ++i) right.push_back(nums[i]);
        
        vector<int> left_sum, right_sum;
        for(auto i = 0; i < (1 << p); ++i) {
            int su = 0;
            for(auto j = 0; j < p; ++j)
                if(i & (1 << j)) su += left[j];
            left_sum.push_back(su);
        }
        for(auto i = 0; i < (1 << p); ++i) {
            int su = 0;
            for(auto j = 0; j < p; ++j)
                if(i & (1 << j)) su += right[j];
            right_sum.push_back(su);
        }

        
        int ret = abs(goal);
        sort(right_sum.begin(), right_sum.end());
        for(auto a : left_sum) {
            auto p = lower_bound(right_sum.begin(), right_sum.end(), goal - a);
            if(p != right_sum.end()) ret = min(ret, abs(goal - a - *p));
            if(p != right_sum.begin()) ret = min(ret, abs(goal - a - *prev(p)));
        }
        return ret;
    }
};
