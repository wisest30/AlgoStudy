class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p, m;
        for(auto num : nums)
            num > 0 ? p.push_back(num) : m.push_back(num);

        vector<int> ret;
        for(auto i = 0; i < p.size(); ++i) {
            ret.push_back(p[i]);
            ret.push_back(m[i]);
        }

        return ret;
    }
};
