class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {        
        unordered_map<int, long long> m;
        for(auto num : nums) {
            auto s = to_string(num);
            for(auto& c : s)
                c = mapping[c - '0'] + '0';
            
            m[num] = stoll(s);
        }
        
        sort(nums.begin(), nums.end(), [&](auto l, auto r) {
            return m[l] < m[r];
        });
        
        return nums;
    }
};
