class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        map<int, set<int>> m;
        for(auto num : nums)
            m[__builtin_popcount(num)].insert(num);
        
        long long ret = 0;
        set<int> s(nums.begin(), nums.end());
        for(auto x : s) {
            auto cnt = __builtin_popcount(x);
            for(auto& p : m) {
                if(p.first + cnt >= k) {
                    ret += p.second.size();
                }
            }
        }
        
        return ret;
    }
};
