class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> indexes(101);
        for(auto i = 0; i < nums.size(); ++i)
            indexes[nums[i]].push_back(i);
        
        vector<int> ret;
        for(auto& q : queries) {
            int l = q[0], r = q[1] + 1;
            
            constexpr int inf = 1000;
            int ans = inf, prev = -inf;
            for(auto i = 1; i <= 100; ++i) {
                auto p = lower_bound(indexes[i].begin(), indexes[i].end(), l);
                auto q = lower_bound(indexes[i].begin(), indexes[i].end(), r);

                if(p != q) {
                    ans = min(ans, i - prev);
                    prev = i;
                }
            }
            
            if(ans == inf)
                ans = -1;
            
            ret.push_back(ans);
        }
        
        return ret;
    }
};
