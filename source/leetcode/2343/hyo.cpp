class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums[0].size();
        auto vs = vector<vector<tuple<string, int>>>(n + 1);
        for(auto len = 1; len <= n; ++len) {
            for(auto i = 0; i < nums.size(); ++i)
                vs[len].push_back(make_tuple(nums[i].substr(n - len), i));
            
            sort(vs[len].begin(), vs[len].end());
        }
        
        vector<int> ret;
        for(auto& q : queries)
            ret.push_back(get<1>(vs[q[1]][q[0] - 1]));
        
        return ret;
    }
};
