class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> m;
        for(auto num : nums)
            m[num]++;
        
        vector<int> ret(2);
        for(auto p : m)
            ret[0] += p.second / 2, ret[1] += p.second % 2;
        
        return ret;
    }
};
